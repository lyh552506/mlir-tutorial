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

// struct Mul2AddPattern:public OpRewritePattern<>{

// };

class Mul2AddPass : public PassWrapper<Mul2AddPass, OperationPass<func::FuncOp>> {
  void runOnOperation() override;

  StringRef getArgument() const final { return "mul-to-add"; }

  StringRef getDescription() const final { return "Impl Mul to Add pass"; }
};
} // namespace tutorial
