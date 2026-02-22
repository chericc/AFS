CUR_PATH=$(dirname $(realpath $BASH_SOURCE))

cd $CUR_PATH

echo $(pwd)

tar xf ZenLib.tgz
tar xf MediaInfoLib.tgz

rm -rf build
mkdir -p build
cd build

rm -rf *
mkdir -p ../output_zenlib
rm -rf ../output_zenlib/*
cmake ../ZenLib/Project/CMake/ \
-DCMAKE_INSTALL_PREFIX=$(realpath $(pwd)/../output_zenlib) \
-DCMAKE_BUILD_TYPE=Release \
-DBUILD_SHARED_LIBS=OFF \
-DENABLE_UNICODE=OFF 

make -j2
make install

rm -rf *
mkdir -p ../output_mediainfo
rm -rf ../output_mediainfo/*
cmake ../MediaInfoLib/Project/CMake/ \
-DCMAKE_INSTALL_PREFIX=$(realpath $(pwd)/../output_mediainfo) \
-DCMAKE_BUILD_TYPE=Release \
-DBUILD_SHARED_LIBS=OFF \
-DCMAKE_DISABLE_FIND_PACKAGE_TinyXML=ON \
-DCMAKE_DISABLE_FIND_PACKAGE_CURL=ON \
-DZenLib_DIR=$(realpath ../output_zenlib/lib/cmake/zenlib)

make -j2
make install
