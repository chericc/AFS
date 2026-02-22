CUR_PATH=$(dirname $(realpath $BASH_SOURCE))

cd $CUR_PATH

echo $(pwd)

rm -rf sqlite-src-3510200
unzip sqlite-src-3510200.zip

rm -rf build
mkdir -p build
cd build

mkdir -p ../output
rm -rf ../output/*
../sqlite-src-3510200/configure --enable-all --prefix=$(realpath $(pwd)/../output)
make -j2
make install