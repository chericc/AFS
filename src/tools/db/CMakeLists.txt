
set(sqlpp11_path ${CMAKE_SOURCE_DIR}/depends/sqlpp11/output)
set(date_DIR ${sqlpp11_path}/lib/cmake/date)
set(Sqlpp11_DIR ${sqlpp11_path}/lib/cmake/Sqlpp11)
find_package(Sqlpp11 REQUIRED)

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
    ${LIB_INTERFACE}
    ${MY_COMMON_HEADER}
    ${LIB_LOG}
    PRIVATE 
    sqlpp11::sqlpp11
)

aux_source_directory(demo src_demo)

set(BIN demo_${LIB_DB})
add_executable(
    ${BIN}
    ${src_demo}
)
target_link_libraries(
    ${BIN}
    ${LIB_DB}
    sqlpp11::sqlpp11
)