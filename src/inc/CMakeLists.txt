
message(STATUS "2-Link target: ${MY_COMMON_HEADER}")

add_library(${MY_COMMON_HEADER} INTERFACE)
target_include_directories(
    ${MY_COMMON_HEADER}
    INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
