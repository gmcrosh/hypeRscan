#!/bin/sh
set -ex

cd ..
wget https://github.com/intel/hyperscan/archive/v5.1.1.tar.gz
tar -xzvf v5.1.1.tar.gz

mkdir build_hyperscan
cd build_hyperscan
cmake ../hyperscan-5.1.1/
sudo make install
