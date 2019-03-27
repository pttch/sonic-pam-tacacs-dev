PROJECT(test)

CMAKE_MINIMUM_REQUIRED(VERSION 3.5 FATAL_ERROR)

set(PAM_TACPLUS_TEST_DIR ${CMAKE_SOURCE_DIR}/test/)
set(PAM_TACPLUS_DIR ${CMAKE_SOURCE_DIR}/client)
set(PAM_LIBTAC_DIR ${CMAKE_SOURCE_DIR}/client/include)
set(PAM_TACPLUS_LIB ${CMAKE_SOURCE_DIR}/client/lib/security)
set(CMAKE_CXX_FLAGS "-fpermissive")

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

INCLUDE_DIRECTORIES(
    ${PAM_LIBTAC_DIR}
    ${PROJECT_BINARY_DIR}
)

include(${CMAKE_ROOT}/Modules/ExternalProject.cmake)

find_package(Gtest REQUIRED)

configure_file (
    test/config.h.in
    ${PROJECT_BINARY_DIR}/config.h
)

ADD_EXECUTABLE(pam_tacplus_test
    ${PAM_TACPLUS_TEST_DIR}/pam_tacplus_test.cpp
)
TARGET_LINK_LIBRARIES(pam_tacplus_test
    gmock gtest gtest_main pthread ${CMAKE_SOURCE_DIR}/client/lib/security/pam_tacplus.so ${CMAKE_SOURCE_DIR}/client/lib/libtac.so pam crypto
)

include(CTest)
