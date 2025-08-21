add_executable(test_my_sorts main.c)
target_include_directories(test_my_sorts PRIVATE ${CRITERION_DIR}/include)
target_link_directories(test_my_sorts PRIVATE ${CRITERION_DIR}/lib)
target_link_libraries(test_my_sorts PRIVATE my_sorts criterion)
target_compile_options(test_my_sorts PRIVATE -Wall -Wextra -pedantic -Werror)

add_test(NAME test_my_sorts COMMAND test_my_math)