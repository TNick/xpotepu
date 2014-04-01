
# ----------------------------------------------------------------------------
# configure the project

set ( LOC_PRJ_NAME "${PROJECT_NAME}_mxml" )
string(TOUPPER ${LOC_PRJ_NAME} LOC_PRJ_NAME_U)
set ( LOC_DEFS "-D${LOC_PRJ_NAME_U}_STATIC=1")
add_definitions( ${LOC_DEFS} )

# ============================================================================



# ----------------------------------------------------------------------------
# external libraries

# ============================================================================


# ----------------------------------------------------------------------------
# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
    "${CMAKE_CURRENT_SOURCE_DIR}/config.h.in"
    "${PROJECT_BINARY_DIR}/build/include/${PROJECT_NAME}/mxml-config.h"
)
# ============================================================================


# ----------------------------------------------------------------------------
# modules
set ( modules 
    
)

# generated libraries are accumulated in modules_libs
FOREACH ( mod ${modules} )
    add_subdirectory( "${mod}" )
ENDFOREACH(mod)
# ============================================================================



# ----------------------------------------------------------------------------
# our library
set ( LIB_SOURCES
	mxml-attr.c
	mxml-entity.c
	mxml-file.c
	mxml-get.c
	mxml-index.c
	mxml-node.c
	mxml-private.c
	mxml-search.c
	mxml-set.c
	mxml-string.c
	mxml.xml
)

set ( LIB_HEADERS
	mxml-private.h
	mxml.h
)

add_library( ${LOC_PRJ_NAME} STATIC
    ${LIB_SOURCES}
)
target_link_libraries( ${LOC_PRJ_NAME} 
    
)

if (INCLUDE_OUTPUT_PATH)
    FOREACH (hfile ${LIB_HEADERS})
        execute_process(
            COMMAND ${CMAKE_COMMAND} -E copy_if_different "${hfile}" "${INCLUDE_OUTPUT_PATH}/${hfile}"
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        )
    ENDFOREACH(hfile)
endif (INCLUDE_OUTPUT_PATH)
# ============================================================================

