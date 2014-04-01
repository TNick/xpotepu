
# ----------------------------------------------------------------------------
# configure the project

set ( LOC_PRJ_NAME "${PROJECT_NAME}_logic" )
string(TOUPPER ${LOC_PRJ_NAME} LOC_PRJ_NAME_U)
set ( LOC_DEFS "-D${LOC_PRJ_NAME_U}_STATIC=1")
add_definitions( ${LOC_DEFS} )

# ============================================================================



# ----------------------------------------------------------------------------
# external libraries

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
    logic.c
    template.c
)

set ( LIB_HEADERS
    global.h
    logic.h
    template.h
)

add_library( ${LOC_PRJ_NAME} STATIC
    ${LIB_SOURCES}
)
target_link_libraries( ${LOC_PRJ_NAME} 
    ${PROJECT_NAME}_mxml
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

