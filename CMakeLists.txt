cmake_minimum_required(VERSION 3.20)
project(libbits)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FindPkgConfig)

# libprim
pkg_check_modules(libprim REQUIRED IMPORTED_TARGET libprim)
  get_target_property(
  LIBPRIM_INC
  PkgConfig::libprim
  INTERFACE_INCLUDE_DIRECTORIES
)

add_library(
  bits
  SHARED
  ${PROJECT_SOURCE_DIR}/src/bits/bits.h
  ${PROJECT_SOURCE_DIR}/src/bits/bits.tcc
  )

set_target_properties(
  bits
  PROPERTIES
  LINKER_LANGUAGE
  CXX
  POSITION_INDEPENDENT_CODE
  ON
  )

target_include_directories(
  bits
  PUBLIC
  ${PROJECT_SOURCE_DIR}/src
  ${LIBPRIM_INC}
  )

target_link_libraries(
  bits
  PkgConfig::libprim
  )

include(GNUInstallDirs)

install(
  FILES
  ${PROJECT_SOURCE_DIR}/src/bits/bits.h
  DESTINATION
  ${CMAKE_INSTALL_INCLUDEDIR}/bits/
  )

install(
  FILES
  ${PROJECT_SOURCE_DIR}/src/bits/bits.tcc
  DESTINATION
  ${CMAKE_INSTALL_INCLUDEDIR}/bits/
  )

install(
  TARGETS
  bits
  )

configure_file(
  ${PROJECT_SOURCE_DIR}/libbits.pc.in
  ${CMAKE_CURRENT_BINARY_DIR}/libbits.pc
  @ONLY
  )
install(
  FILES
  ${CMAKE_CURRENT_BINARY_DIR}/libbits.pc
  DESTINATION
  ${CMAKE_INSTALL_LIBDIR}/pkgconfig/
  )
