#!/bin/sh
set -e

export NUM_JOBS=1

mkdir Bin
cd Bin
cmake ..
make
./bin/SRFramework