cmake_minimum_required(VERSION 3.0)

project(static_math LANGUAGES CXX)

option(STATIC_MATH_BUILD_TESTS "Build the tests them." ON)

# Create static_math library and configure it
add_library(static_math INTERFACE)
target_include_directories(static_math INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_compile_features(static_math INTERFACE cxx_std_14)

add_library(static_math::static_math ALIAS static_math)

install(
    DIRECTORY "include/"
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
)

if (STATIC_MATH_BUILD_TESTS)
    include(CTest)
    enable_testing()

    function(build_test test_tgt check_tgt)
        # Add executable for the example
        add_executable(test-${test_tgt} ${headers} ${detail_headers} test/${test_tgt}.cpp)
        target_link_libraries(test-${test_tgt} PRIVATE static_math::static_math)
        add_custom_target(run-test-${test_tgt} COMMAND $<TARGET_FILE:test-${test_tgt}> )
        add_test(NAME ${test_tgt}
                 COMMAND test-${test_tgt})

        if(TARGET ${check_tgt})
            add_dependencies(${check_tgt} test-${test_tgt})
        endif()
    endfunction(build_test)

    add_custom_target(all_tests ALL)

    build_test(bit          all_tests)
    build_test(cmath        all_tests)
    build_test(complex      all_tests)
    build_test(constant     all_tests)
    build_test(formula      all_tests)
    build_test(rational     all_tests)
    build_test(trigonometry all_tests)
    build_test(vector       all_tests)

    add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND} -C "${CMAKE_BUILD_TYPE}" --output-on-failure
                            DEPENDS all_tests
                            VERBATIM)
endif()
