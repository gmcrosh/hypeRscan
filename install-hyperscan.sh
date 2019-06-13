#!/bin/sh
set -ex

wget https://github.com/intel/hyperscan/archive/v5.1.1.tar.gz
tar -xzvf v5.1.1.tar.gz

mkdir build_hyperscan
cmake ../hyperscan-5.1.1/
make install