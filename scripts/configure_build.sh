EXTERNAL_INSTALL_DIR=$(pwd)/external/install
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug -DCMAKE_PREFIX_PATH=$EXTERNAL_INSTALL_DIR -DBUILD_SHARED_LIBS=ON
cmake --build build -j $(nproc)