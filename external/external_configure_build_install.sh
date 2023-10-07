BUILD_DIR=build
INSTALL_DIR=install

EIGEN_DIR=eigen
cmake -S $EIGEN_DIR -B $BUILD_DIR/$EIGEN_DIR
cmake --build $BUILD_DIR/$EIGEN_DIR
cmake --install $BUILD_DIR/$EIGEN_DIR --prefix $INSTALL_DIR