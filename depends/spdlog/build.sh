CUR_PATH=$(dirname $(realpath $BASH_SOURCE))

cd $CUR_PATH

echo $(pwd)

tar xf v1.16.0.tar.gz

rm -rf build
mkdir build
cd build
rm -rf *
mkdir -p ../output
rm -rf ../output/*
cmake ../spdlog-1.16.0/ -DCMAKE_INSTALL_PREFIX=$(realpath $(pwd)/../output) \
-DCMAKE_BUILD_TYPE=Release

make -j2
make install
