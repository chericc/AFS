#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "mediainfo" for configuration "Release"
set_property(TARGET mediainfo APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(mediainfo PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C;CXX"
  IMPORTED_LOCATION_RELEASE "/home/test/code/AFS/depends/mediainfo/output_mediainfo/lib/libmediainfo.a"
  )

list(APPEND _cmake_import_check_targets mediainfo )
list(APPEND _cmake_import_check_files_for_mediainfo "/home/test/code/AFS/depends/mediainfo/output_mediainfo/lib/libmediainfo.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
