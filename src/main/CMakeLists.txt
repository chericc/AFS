aux_source_directory(. src)
add_executable(
    ${BIN_AFS}
    ${src}
)
target_link_libraries(
    ${BIN_AFS}
    ${LIB_FILE_PROVIDER}
    ${LIB_LOG}
)
install(
    TARGETS ${BIN_AFS}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)