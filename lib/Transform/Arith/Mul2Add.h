#pragma once
#include "mlir/Dialect/Affine/IR/AffineOps.h"
#include "mlir/Dialect/Affine/LoopUtils.h"
#include "mlir/Dialect/Arith/IR/Arith.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/IR/PatternMatch.h"
#include "mlir/Pass/Pass.h"
#include "mlir/Support/LogicalResult.h"
#include "llvm/ADT/StringRef.h"
using namespace mlir;

namespace tutorial {

// define the target pattern
struct PowerOfTwoExpand : public OpRewritePattern<arith::MulIOp> {
  PowerOfTwoExpand(MLIRContext *ctx) : OpRewritePattern(ctx, /*benefit*/ 4) {}
  // rewrites y=C*x as y = C/2*x + C/2*x
  LogicalResult matchAndRewrite(arith::MulIOp op,
                                PatternRewriter &rewriter) const override {
    auto lhs = op.getLhs();
    auto rhs = op.getRhs();
    auto rhs_const = rhs.getDefiningOp<arith::ConstantIntOp>();
    if (!rhs_const)
      return failure();
    auto target = rhs_const.value();
    // check if it is 2^n
    if (target & (target - 1))
      return failure();
    auto newConst = rewriter.create<arith::ConstantOp>(
        op->getLoc(), rewriter.getIntegerAttr(rhs.getType(), target / 2));
    auto newMul =
        rewriter.create<arith::MulIOp>(newConst->getLoc(), lhs, newConst);
    auto new_Add =
        rewriter.create<arith::AddIOp>(newMul.getLoc(), newMul, newMul);

    // RAUW
    rewriter.replaceOp(op, new_Add);
    // rewriter.eraseOp(op);
    return success();
  }
};

// define the target pattern
struct PeelFromMul : public OpRewritePattern<arith::MulIOp> {
  PeelFromMul(MLIRContext *ctx) : OpRewritePattern(ctx, /*benefit*/ 3) {}
  // rewriting y = 9*x as y = 8*x + x
  LogicalResult matchAndRewrite(arith::MulIOp op,
                                PatternRewriter &rewriter) const override {
    auto lhs = op.getLhs();
    auto rhs = op.getRhs();
    auto rhs_const = rhs.getDefiningOp<arith::ConstantIntOp>();
    if (!rhs_const)
      return failure();
    auto target = rhs_const.value();
    if (!(target & (target - 1)))
      return failure();
    auto newConst = rewriter.create<arith::ConstantOp>(
        op->getLoc(), rewriter.getIntegerAttr(rhs.getType(), target - 1));
    auto newMul =
        rewriter.create<arith::MulIOp>(newConst->getLoc(), lhs, newConst);
    auto newAdd = rewriter.create<arith::AddIOp>(newMul.getLoc(), newMul, lhs);

    rewriter.replaceOp(op, newAdd);
    // rewriter.eraseOp(op);
    return success();
  }
};

class Mul2AddPass
    : public PassWrapper<Mul2AddPass, OperationPass<func::FuncOp>> {
  void runOnOperation() override;

  StringRef getArgument() const final { return "mul-to-add"; }

  StringRef getDescription() const final { return "Impl Mul to Add pass"; }
};
} // namespace tutorial
