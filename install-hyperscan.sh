#!/bin/sh
set -ex
apt-get update
apt-get install git
apt-get install cmake
apt-get install g++
apt-get install libboost-all-dev
apt-get install ragel

wget https://github.com/intel/hyperscan/archive/v5.1.1.tar.gz
tar -xzvf v5.1.1.tar.gz

mkdir build_hyperscan
cmake ../hyperscan-5.1.1/
make install