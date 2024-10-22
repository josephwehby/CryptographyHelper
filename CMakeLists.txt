cmake_minimum_required(VERSION 3.21.1)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(main)

set(EXECUTABLE_OUTPUT_PATH "bin")

#set(LIBRARY_OUTPUT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/library")

# add library path for BigInteger
set(CPP_LIBS_DIR "/home/wehby/C++Libs")

# add src files
set(MAIN_SRC_FILES src/main.cpp src/CryptoHelper.cpp)

# for the shared library
set(CRYPTO_SRC_FILES src/CryptoHelper.cpp)
set(CRYPTO_HEADER_FILES include/CryptoHelper.hpp)

# add header files
include_directories(
   "./include"
   "${CPP_LIBS_DIR}/BigInteger"
)

# bigint library path
set(BIG_INTEGER_LIB "${CPP_LIBS_DIR}/BigInteger/libBigInteger.so")

add_executable(main ${MAIN_SRC_FILES})
target_link_libraries(main ${BIG_INTEGER_LIB})

if (UNIX)
  string(APPEND CMAKE_CXX_FLAGS " -Wall -Werror -Wno-format-security -Wno-self-assign-overloaded")
endif()

# create library
#add_library(CryptoHelper SHARED ${CRYPTO_SRC_FILES})

#set_target_properties(BigInteger PROPERTIES
#    LIBRARY_OUTPUT_DIRECTORY ${LIBRARY_OUTPUT_PATH}
#)
