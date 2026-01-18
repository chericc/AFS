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

set(COMMON_PCH common_pch)

set(LIB_FILE_PROVIDER file_provider)
set(BIN_AFS afs)

add_subdirectory(src)