#pragma once
#include "lib/Transform/Arith/Mul2Add.h"
#include "mlir/Dialect/Arith/IR/Arith.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/IR/PatternMatch.h"
#include "mlir/Pass/Pass.h"
#include "mlir/Support/LogicalResult.h"
#include <cstdint>
using namespace mlir;

namespace tutorial {

struct PowerOfTwoPattern : public OpRewritePattern<arith::MulIOp> {
  PowerOfTwoPattern(MLIRContext *ctx)
      : OpRewritePattern<arith::MulIOp>(ctx, 6) {}
  // match pattern like y=a*x, a=2^n
  LogicalResult matchAndRewrite(arith::MulIOp op,
                                PatternRewriter &rewriter) const override {
    auto lhs = op.getLhs();
    auto rhs = op.getRhs();
    auto rhs_const = rhs.getDefiningOp<arith::ConstantIntOp>();
    if (!rhs_const)
      return failure();
    auto target = rhs_const.value();
    if (target & (target - 1))
      return failure();
    int64_t factor = 0;
    while (target) {
      target = target >> 1;
      factor++;
    }
    auto fact = rewriter.create<arith::ConstantIntOp>(op.getLoc(), factor,
                                                      rhs.getType());
    auto shl = rewriter.create<arith::ShLIOp>(op->getLoc(), lhs, fact);
    rewriter.replaceOp(op, shl);

    return success();
  }
};

class Mul2ShlPass
    : public PassWrapper<Mul2ShlPass, OperationPass<func::FuncOp>> {
  void runOnOperation() override;

  StringRef getArgument() const override { return "mul-to-shl"; }

  StringRef getDescription() const override { return "Impl mul to shl"; }
};

} // namespace tutorial