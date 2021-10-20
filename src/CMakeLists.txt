
set(BINARY ${CMAKE_PROJECT_NAME})

set(SOURCES
    utils.hpp
    main.cpp
    polynomial.cpp
    polynomial.hpp
    utils.cpp
    validate.cpp
    validate.hpp
)

add_executable(${BINARY} ${SOURCES})

add_library(${BINARY}_lib ${SOURCES})