
set(BINARY ${CMAKE_PROJECT_NAME}_test)

set(SOURCES 
    main.cpp
    sqrt_test_utils.cpp
    gcd_test_utils.cpp
    getdegree_test_validate.cpp
    getreduced_test_validate.cpp
    setup_test_validate.cpp
    getABCD_test_polynomial.cpp
    getdiscriminant_test_polynomial.cpp
    getsolutions_test_polynomial.cpp
)

add_executable(${BINARY} ${SOURCES})

add_test(
    NAME ${BINARY}
    COMMAND ${BINARY}
)

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)