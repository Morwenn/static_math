cmake_minimum_required(VERSION 3.0)
project(static_math)

set(CMAKE_CXX_STANDARD 14)

option(STATIC_MATH_BUILD_TESTS  "Build the tests them." ON)
option(USE_CCACHE               "Use `ccache` if available"         ON)

if (NOT CMAKE_BUILD_TYPE)
    if(CMAKE_GENERATOR STREQUAL "Xcode")
        set(CMAKE_BUILD_TYPE "Debug")
    else()
        set(CMAKE_BUILD_TYPE "Release")
    endif()
    
    message(STATUS "No build type selected, default to ${CMAKE_BUILD_TYPE}")
endif()

if (USE_CCACHE)
    find_program(CCACHE_FOUND ccache)

    if (CCACHE_FOUND)
        message(STATUS "Using ccache")
    
        set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
        set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache) 
    endif(CCACHE_FOUND)
endif(USE_CCACHE)

set(headers include/static_math/cmath.h
            include/static_math/complex.h
            include/static_math/constant.h
            include/static_math/constants.h
            include/static_math/formula.h
            include/static_math/rational.h
            include/static_math/static_math.h
            include/static_math/trigonometry.h
            include/static_math/vector.h)

set(detail_headers
            include/static_math/detail/can_fit.h
            include/static_math/detail/cmath.inl
            include/static_math/detail/complex.inl
            include/static_math/detail/constant.inl
            include/static_math/detail/core.h
            include/static_math/detail/formula.inl
            include/static_math/detail/parse.h
            include/static_math/detail/rational.inl
            include/static_math/detail/trigonometry.inl
            include/static_math/detail/vector.inl)

install(DIRECTORY include/
        DESTINATION include/)

if (STATIC_MATH_BUILD_TESTS)
    include(CTest)
    enable_testing()

    include_directories(./include)
    # Generate all of the example parsers
    function(build_test test_tgt check_tgt)
        
        # Add executable for the example
        add_executable(test-${test_tgt} ${headers} ${detail_headers} test/${test_tgt}.cpp)
        add_test(NAME ${test_tgt}
                COMMAND test-${test_tgt})

        if(TARGET ${check_tgt})
            add_dependencies(${check_tgt} test-${test_tgt})
        endif()
    endfunction(build_test)

    add_custom_target(all_tests ALL)

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
