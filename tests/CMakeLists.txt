add_subdirectory( "unit" )
add_subdirectory( "integration" )



set ( modules_testing_src ${modules_testing_src}
    "${CMAKE_CURRENT_SOURCE_DIR}/logic_helper.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/template_helper.cc"
    CACHE INTERNAL ""
)
list( REMOVE_DUPLICATES modules_testing_src )
