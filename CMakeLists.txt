PROJECT(tests)

CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

set(PAM_TACPLUS_TEST_DIR ${CMAKE_SOURCE_DIR}/test/)
set(PAM_TACPLUS_DIR ${CMAKE_SOURCE_DIR}/pam_tacplus)
set(CMAKE_CXX_FLAGS "-fpermissive")

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

INCLUDE_DIRECTORIES(
    ${PAM_LIBTAC_INCLUDE_DIR}
    ${PAM_LIBTAC_SOURCE_DIR}
)

include(${CMAKE_ROOT}/Modules/ExternalProject.cmake)

find_package(Gtest REQUIRED)

ADD_EXECUTABLE(pam_tacplus_test
    ${PAM_TACPLUS_TEST_DIR}/pam_tacplus_test.cpp
)
TARGET_LINK_LIBRARIES(pam_tacplus_test
    gmock gtest gtest_main pthread pam_tacplus tac pam crypto
)
target_include_directories(pam_tacplus_test PRIVATE ${CMAKE_SOURCE_DIR}/client/include)

include(CTest)
