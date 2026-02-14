cmake_minimum_required(VERSION 3.16)
project(AFS)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

option(USE_ASAN "use asan(ASAN)" OFF)
if (USE_ASAN)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -fno-omit-frame-pointer" )
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer")
  add_link_options(-fsanitize=address -fno-omit-frame-pointer)
endif()

set(DEP_DIR ${CMAKE_SOURCE_DIR}/depends)
set(spdlog_DIR ${DEP_DIR}/spdlog/output/lib/cmake/spdlog)
# set(MediaInfoLib_DIR ${DEP_DIR}/mediainfo/output_mediainfo/lib/cmake/mediainfolib)

find_package(spdlog REQUIRED)
# find_package(MediaInfoLib REQUIRED)

set(LIB_MEDIAINFO_PATH ${DEP_DIR}/mediainfo/output_mediainfo)
set(LIB_MEDIAINFO_INC_PATH ${LIB_MEDIAINFO_PATH}/include)
set(LIB_MEDIAINFO_LIB_PATH ${LIB_MEDIAINFO_PATH}/lib)
set(LIB_MEDIAINFO mediainfo)

set(LIB_ZEN_PATH ${DEP_DIR}/mediainfo/output_zenlib)
set(LIB_ZEN_LIB_PATH ${LIB_ZEN_PATH}/lib)
set(LIB_ZEN zen)

set(MY_COMMON_HEADER my_common_header)

set(LIB_MYMEDIAINFO mymediainfo)
set(LIB_DB db)
set(LIB_FILE_PROVIDER file_provider)
set(LIB_LOG log)

set(BIN_AFS afs)

link_libraries(spdlog::spdlog)
add_subdirectory(src)
