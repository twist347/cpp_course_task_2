add_executable(test_edu_sorts main.c)
target_include_directories(test_edu_sorts PRIVATE ${CRITERION_DIR}/include)
target_link_directories(test_edu_sorts PRIVATE ${CRITERION_DIR}/lib)
target_link_libraries(test_edu_sorts PRIVATE edu_sorts criterion)
target_compile_options(test_edu_sorts PRIVATE -Wall -Wextra -pedantic -Werror)

add_test(NAME test_edu_sorts COMMAND test_edu_sorts)