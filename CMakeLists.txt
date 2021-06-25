cmake_minimum_required(VERSION 3.10)
project(libbits)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# libprim
find_library(LIBPRIM_A NAMES libprim.a PATHS ${CMAKE_INSTALL_RPATH})
if(LIBPRIM_A MATCHES "NOTFOUND")
  message(FATAL_ERROR "libprim.a not found")
endif()
string(REPLACE lib/libprim.a include/ LIBPRIM_INC ${LIBPRIM_A})
if(NOT EXISTS ${LIBPRIM_INC})
  message(FATAL_ERROR "libprim include dir doesn't exist")
endif()

add_library(
  bits
  STATIC
  ${PROJECT_SOURCE_DIR}/src/bits/bits.h
  ${PROJECT_SOURCE_DIR}/src/bits/bits.tcc
  )

set_target_properties(
  bits
  PROPERTIES
  LINKER_LANGUAGE
  CXX
  )

target_include_directories(
  bits
  PUBLIC
  ${PROJECT_SOURCE_DIR}/src
  ${LIBPRIM_INC}
  )

target_link_libraries(
  bits
  ${LIBPRIM_A}
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

