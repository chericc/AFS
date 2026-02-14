# build.md

## zenlib

```bash
cmake ../ZenLib/Project/CMake/ \
-DCMAKE_INSTALL_PREFIX=$(realpath $(pwd)/../output_zenlib) \
-DCMAKE_BUILD_TYPE=Release \
-DBUILD_SHARED_LIBS=OFF
```

## mediainfolib

```bash
cmake ../MediaInfoLib/Project/CMake/ \
-DCMAKE_INSTALL_PREFIX=$(realpath $(pwd)/../output_mediainfo) \
-DCMAKE_BUILD_TYPE=Release \
-DBUILD_SHARED_LIBS=OFF \
-DZenLib_DIR=$(realpath ../output_zenlib/lib/cmake/zenlib)
```