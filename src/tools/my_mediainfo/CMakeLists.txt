aux_source_directory(. src)

set(LIB_INTERFACE ${LIB_MYMEDIAINFO}_interface)
add_library(${LIB_INTERFACE} INTERFACE)
target_include_directories(
    ${LIB_INTERFACE}
    INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

link_directories(
    ${LIB_MEDIAINFO_LIB_PATH}
    ${LIB_ZEN_LIB_PATH}
)
include_directories(
    ${LIB_MEDIAINFO_INC_PATH}
    ${LIB_ZEN_INC_PATH}
)
add_library(
    ${LIB_MYMEDIAINFO}
    ${src}
)
target_link_libraries(
    ${LIB_MYMEDIAINFO}
    PUBLIC
    ${MY_COMMON_HEADER}
    ${LIB_LOG}
    ${LIB_MEDIAINFO}
    ${LIB_ZEN}
    ${LIB_INTERFACE}
    z
)

link_libraries(
    ${LIB_MYMEDIAINFO}
)

aux_source_directory(demo src_demo)
set(BIN demo_${LIB_MYMEDIAINFO})
add_executable(
    ${BIN}
    ${src_demo}
)
install(
    TARGETS ${BIN}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
