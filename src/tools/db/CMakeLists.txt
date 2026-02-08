aux_source_directory(. src)

set(LIB_INTERFACE ${LIB_DB}_interface)

add_library(${LIB_INTERFACE} INTERFACE)
target_include_directories(
    ${LIB_INTERFACE}
    INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_library(${LIB_DB} STATIC ${src})
target_link_libraries(
    ${LIB_DB}
    PUBLIC
    ${LIB_LOG}
    ${LIB_INTERFACE}
    ${MY_COMMON_HEADER}
)
