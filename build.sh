mkdir -p build
cd build
cmake .. \
-DCMAKE_BUILD_TYPE=Debug \
-DCMAKE_INSTALL_PREFIX=$(pwd)/output \
-DUSE_ASAN=ON

cmake ..

make all install $@
# make all $@