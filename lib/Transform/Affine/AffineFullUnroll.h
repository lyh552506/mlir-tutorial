#pragma once
#include "mlir/Dialect/Affine/IR/AffineOps.h"
#include "mlir/Dialect/Affine/LoopUtils.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/IR/PatternMatch.h"
#include "mlir/Pass/Pass.h"
#include "mlir/Support/LogicalResult.h"
#include "llvm/ADT/StringRef.h"

using namespace mlir;

namespace tutorial {

class AffineFullUnrollPass
    : public PassWrapper<AffineFullUnrollPass, OperationPass<func::FuncOp>> {
private:
  void runOnOperation() override;
  // 当使用类似 mlir-opt 工具运行时，可以通过--affine-full-unroll来启用该Pass。
  StringRef getArgument() const final { return "affine-full-unroll"; }
  //   运行 mlir-opt --help 时，会看到 --affine-full-unroll 的旁边显示 "Fully
  //   unroll all affine loops"
  StringRef getDescription() const final {
    return "Fully unroll all affine loops";
  }
};

//define the pattern
struct AffineFullUnrollPattern : public OpRewritePattern<affine::AffineForOp> {
  AffineFullUnrollPattern(MLIRContext *ctx)
      : OpRewritePattern<affine::AffineForOp>(ctx, 1) {}
  LogicalResult matchAndRewrite(affine::AffineForOp op,
                                PatternRewriter &rewriter) const override {
    return affine::loopUnrollFull(op);
  }
};

class AffineFullUnrollPatternRewriter
    : public PassWrapper<AffineFullUnrollPatternRewriter,
                         OperationPass<func::FuncOp>> {
  void runOnOperation() override;

  StringRef getArgument() const final { return "affine-full-unroll-rewriter"; }
  //   运行 mlir-opt --help 时，会看到 --affine-full-unroll 的旁边显示 "Fully
  //   unroll all affine loops"
  StringRef getDescription() const final {
    return "Fully unroll all affine loops using pattern rewriter";
  }
};

} // namespace tutorial