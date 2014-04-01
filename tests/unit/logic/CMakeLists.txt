set ( modules_testing_src ${modules_testing_src}
    "${CMAKE_CURRENT_SOURCE_DIR}/test_logic.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/test_template.cc"

    CACHE INTERNAL "" 
)
list( REMOVE_DUPLICATES modules_testing_src )

