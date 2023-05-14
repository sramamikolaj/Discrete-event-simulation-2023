cmake_minimum_required(VERSION 3.0.0)
project(sc2023 VERSION 0.1.0)

include(CTest)
enable_testing()

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Simulation.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/NewUserEvent.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/System.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/User.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/UserReportEvent.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Generator.cpp
)

add_executable(sc2023 "")

target_sources(sc2023
    PRIVATE
        ${SOURCES}
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
