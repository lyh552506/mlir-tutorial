#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/Pass/Pass.h"
#include "llvm/ADT/StringRef.h"
using namespace mlir;

class AffineFullUnrollPass
    : public PassWrapper<AffineFullUnrollPass, OperationPass<func::FuncOp>> {
private:
  void runOnOperation() override;
  // 当使用类似 mlir-opt 工具运行时，可以通过--affine-full-unroll来启用该Pass。
  llvm::StringRef getArgument() const final { return "affine-full-unroll"; }
  //   运行 mlir-opt --help 时，会看到 --affine-full-unroll 的旁边显示 "Fully
  //   unroll all affine loops"
  llvm::StringRef getDescription() const final {
    return "Fully unroll all affine loops";
  }
};