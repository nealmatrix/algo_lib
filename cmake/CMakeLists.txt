include(GNUInstallDirs)

include(CMakePackageConfigHelpers)

configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/${ALGO_LIB}Config.cmake
    INSTALL_DESTINATION
    ${CMAKE_INSTALL_LIBDIR}/cmake/${ALGO_LIB}
)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/${ALGO_LIB}ConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

install(
    FILES
    ${CMAKE_CURRENT_BINARY_DIR}/${ALGO_LIB}Config.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/${ALGO_LIB}ConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${ALGO_LIB}
)