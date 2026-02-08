aux_source_directory(. src)

set(BIN demo_${LIB_DB})
add_executable(
    ${BIN}
    ${src}
)
target_link_libraries(
    ${BIN}
    ${LIB_DB}
)
