#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "zen" for configuration "Release"
set_property(TARGET zen APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(zen PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "/home/test/code/AFS/depends/mediainfo/output_zenlib/lib/libzen.a"
  )

list(APPEND _cmake_import_check_targets zen )
list(APPEND _cmake_import_check_files_for_zen "/home/test/code/AFS/depends/mediainfo/output_zenlib/lib/libzen.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
