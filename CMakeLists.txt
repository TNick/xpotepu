# ----------------------------------------------------------------------------
# prepare

cmake_minimum_required(VERSION 2.8.9)
set ( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
# ============================================================================


# ----------------------------------------------------------------------------
# customisation

set ( PROJECT_NAME "xpotepu" )

# Automatically link Qt executables to qtmain target on Windows
cmake_policy(SET CMP0020 OLD)

# ============================================================================


# ----------------------------------------------------------------------------
# configure the project

project(${PROJECT_NAME})

string(TOUPPER ${PROJECT_NAME} PROJECT_NAME_U)
string(TIMESTAMP ${PROJECT_NAME_U}_BUILD_TIME UTC)

# may be either Release or Debug
if ( CMAKE_BUILD_TYPE STREQUAL "" )
    set ( CMAKE_BUILD_TYPE "Release" )
endif (CMAKE_BUILD_TYPE STREQUAL "")

# the version as known to CMake
set ( ${PROJECT_NAME_U}_MAJOR_VERSION 1)
set ( ${PROJECT_NAME_U}_MINOR_VERSION 0)
set ( ${PROJECT_NAME_U}_PATCH_VERSION 0)
set ( ${PROJECT_NAME_U}_VERSION
  "${${PROJECT_NAME_U}_MAJOR_VERSION}.${${PROJECT_NAME_U}_MINOR_VERSION}.${${PROJECT_NAME_U}_PATCH_VERSION}")

# set some paths
set ( CMAKE_RUNTIME_OUTPUT_DIRECTORY  "${PROJECT_BINARY_DIR}/build/bin" )
set ( EXECUTABLE_OUTPUT_PATH  "${PROJECT_BINARY_DIR}/build/bin" )
set ( LIBRARY_OUTPUT_PATH  "${PROJECT_BINARY_DIR}/build/lib" )
set ( INCLUDE_OUTPUT_PATH  "${PROJECT_BINARY_DIR}/build/include/${PROJECT_NAME}" )

include_directories(
  "${PROJECT_SOURCE_DIR}"
  "${PROJECT_BINARY_DIR}/build/include"
)

if (WIN32)
  # set stuff for windows
  add_definitions( -D${PROJECT_NAME_U}_WIN32=1 )
else (WIN32)
  # set stuff for other systems
  
endif (WIN32)

# configure compiler
if ( CMAKE_BUILD_TOOL MATCHES "(msdev|devenv|nmake)" )
    add_definitions(/W4)
else ( CMAKE_BUILD_TOOL MATCHES "(msdev|devenv|nmake)" )
    add_definitions(-Wall)
endif()
if   (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions( -DQT_DEBUG=1 -D${PROJECT_NAME_U}_DEBUG=1 -D_DEBUG=1 )
    set ( DebugLogEnabled true )
else (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions( -DQT_NO_DEBUG=1 -D${PROJECT_NAME_U}_NO_DEBUG=1 -D_NDEBUG=1 )
    set ( DebugLogEnabled false )
endif (CMAKE_BUILD_TYPE STREQUAL "Debug")
set ( CMAKE_DEBUG_POSTFIX  "_debug")

# Find includes in corresponding build directories
set ( CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set ( CMAKE_AUTOMOC ON)

# accumulate testing source files
set (modules_testing_src)

# ============================================================================


# ----------------------------------------------------------------------------
# external libraries

add_subdirectory( "googletest" )
include_directories(googletest/include)

# ============================================================================

# ----------------------------------------------------------------------------
# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
    "${PROJECT_SOURCE_DIR}/config.h.in"
    "${PROJECT_BINARY_DIR}/build/include/${PROJECT_NAME}/config.h"
)
# ============================================================================

# ----------------------------------------------------------------------------
# modules

# modules belonging to this project
set ( lib_modules
    logic
)

# external modules embedded in the project
set ( modules
	mxml
    ${lib_modules}
)

# generated libraries are accumulated in modules_libs
FOREACH ( mod ${modules} )
    add_subdirectory( "${mod}" )
ENDFOREACH(mod)
# ============================================================================

# ----------------------------------------------------------------------------
# internal tests
add_subdirectory( "tests" )
if (modules_testing_src)
	list( REMOVE_DUPLICATES modules_testing_src )
    add_executable(internal-test
        ${modules_testing_src}
    )
    target_link_libraries ( internal-test
        gtest_main gtest
        ${PROJECT_NAME}_logic
        ${PROJECT_NAME}_mxml
    )
    set ( props "${PROJECT_NAME_U}_INTERNAL_TESTS=1")
    set_target_properties ( internal-test
        PROPERTIES COMPILE_DEFINITIONS "${props}"
    )
endif (modules_testing_src)
# ============================================================================


# ----------------------------------------------------------------------------
# documentation
find_package(Doxygen)

configure_file (
    "${PROJECT_SOURCE_DIR}/Doxyfile.in"
    "${PROJECT_BINARY_DIR}/Doxyfile"
    @ONLY
)

if(DOXYGEN_FOUND)
    add_custom_target(doc
        ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen" VERBATIM
    )
endif(DOXYGEN_FOUND)

# ============================================================================




