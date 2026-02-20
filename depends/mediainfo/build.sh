CUR_PATH=$(dirname $(realpath $BASH_SOURCE))

cd $CUR_PATH

echo $(pwd)

tar xf ZenLib.tgz
tar xf MediaInfoLib.tgz

rm -rf build
mkdir -p build
cd build

rm -rf *
rm -rf ../output_zenlib
cmake ../ZenLib/Project/CMake/ \
-DCMAKE_INSTALL_PREFIX=$(realpath $(pwd)/../output_zenlib) \
-DCMAKE_BUILD_TYPE=Release \
-DBUILD_SHARED_LIBS=OFF \
-DENABLE_UNICODE=OFF

make -j2
make install

rm -rf *
rm ../output_mediainfo -rf
cmake ../MediaInfoLib/Project/CMake/ \
-DCMAKE_INSTALL_PREFIX=$(realpath $(pwd)/../output_mediainfo) \
-DCMAKE_BUILD_TYPE=Release \
-DBUILD_SHARED_LIBS=OFF \
-DZenLib_DIR=$(realpath ../output_zenlib/lib/cmake/zenlib)

make -j2
make install
