
set(BINARY ${CMAKE_PROJECT_NAME})

set(SOURCES
    header.hpp
    main.cpp
    polynomial.cpp
    polynomial.hpp
    utils.cpp
    validate.cpp
    validate.hpp
)

add_executable(${BINARY}_run ${SOURCES})

add_library(${BINARY}_lib ${SOURCES})