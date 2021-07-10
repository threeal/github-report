cmake_minimum_required(VERSION 3.5)

project(github-report)

if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(PkgConfig REQUIRED)
pkg_check_modules(CURLPP REQUIRED IMPORTED_TARGET curlpp)

add_executable(github_report "src/github_report.cpp")
target_include_directories(github_report PUBLIC ${CURLPP_INCLUDE_DIRS})
target_link_libraries(github_report PUBLIC ${CURLPP_LIBRARIES})
