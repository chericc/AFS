CUR_PATH=$(dirname $(realpath $BASH_SOURCE))

cd $CUR_PATH

echo $(pwd)

tar xf 0.65.tar.gz

rm -rf build
mkdir -p build
cd build

cmake ../sqlpp11-0.65/ -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=$(pwd)/../output \
-DBUILD_SQLITE3_CONNECTOR=ON -DDEPENDENCY_CHECK=OFF -DBUILD_TESTING=OFF

make -j2
make install

