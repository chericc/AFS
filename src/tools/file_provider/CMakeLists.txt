aux_source_directory(. src)
aux_source_directory(demo src_demo)

set(LIB_INTERFACE ${LIB_FILE_PROVIDER}_interface)

add_library(${LIB_INTERFACE} INTERFACE)
target_include_directories(
    ${LIB_INTERFACE}
    INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_library(${LIB_FILE_PROVIDER} STATIC ${src})
target_link_libraries(
    ${LIB_FILE_PROVIDER}
    PUBLIC
    ${LIB_LOG}
    ${LIB_INTERFACE}
    ${MY_COMMON_HEADER}
)

set(BIN demo_${LIB_FILE_PROVIDER})
add_executable(
    ${BIN}
    ${src_demo}
)
target_link_libraries(
    ${BIN}
    ${LIB_FILE_PROVIDER}
)
install(
    TARGETS ${BIN}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)