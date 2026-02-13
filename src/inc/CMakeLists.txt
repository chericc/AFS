
add_library(${MY_COMMON_HEADER} INTERFACE)
target_include_directories(
    ${MY_COMMON_HEADER}
    INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
