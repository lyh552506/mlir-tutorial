cmake_minimum_required(VERSION 3.20.0)

project(mlir-tutorial LANGUAGES CXX C)

if(NOT CMAKE_GENERATOR)
  set(CMAKE_GENERATOR "Ninja" CACHE INTERNAL "" FORCE)
endif()

set(CMAKE_CXX_STANDARD 17 CACHE STRING "C++ standard to conform to")
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(BUILD_DEPS ON)
set(CMAKE_INSTALL_PREFIX "/home/lyh_irie/Arch_Learning/hands-on-mlir/install")
find_package(MLIR REQUIRED CONFIG)

message(STATUS "Using MLIRConfig.cmake in: ${MLIR_DIR}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
set(MLIR_BINARY_DIR ${CMAKE_BINARY_DIR})

include(AddLLVM)
include(TableGen)

list(APPEND CMAKE_MODULE_PATH "${MLIR_CMAKE_DIR}")
include(AddMLIR)
include_directories(${LLVM_INCLUDE_DIRS})
include_directories(${MLIR_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR})
include_directories(/home/lyh_irie/Arch_Learning/hands-on-mlir/llvm-project)
include_directories(${PROJECT_BINARY_DIR})

add_subdirectory(lib)

get_property(dialect_libs GLOBAL PROPERTY MLIR_DIALECT_LIBS)
get_property(conversion_libs GLOBAL PROPERTY MLIR_CONVERSION_LIBS)

set (target_libs
    ${dialect_libs}
    ${conversion_libs}
    AffineFullUnroll
	PolyDialect
    ArithOpt
    MLIROptLib
    MLIRPass
)

add_llvm_executable(mlir-tutorial tutorial-opt.cpp)
llvm_update_compile_flags(mlir-tutorial)
target_link_libraries(mlir-tutorial PRIVATE ${target_libs})

mlir_check_all_link_libraries(mlir-tutorial)
