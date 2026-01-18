aux_source_directory(. src)

set(LIB_FILE_PROVIDER_INTERFACE ${LIB_FILE_PROVIDER}_interface)

add_library(${LIB_FILE_PROVIDER_INTERFACE} INTERFACE)
target_include_directories(
    ${LIB_FILE_PROVIDER_INTERFACE}
    INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_library(${LIB_FILE_PROVIDER} STATIC ${src})
target_link_libraries(
    ${LIB_FILE_PROVIDER}
    PUBLIC
    ${LIB_FILE_PROVIDER_INTERFACE}
)