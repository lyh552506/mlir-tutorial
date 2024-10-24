#include "AffineFullUnrollPatternRewriter.h"
#include "mlir/Dialect/Affine/IR/AffineOps.h"
#include "mlir/Dialect/Affine/LoopUtils.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/IR/PatternMatch.h"
#include "mlir/Support/LogicalResult.h"
#include "mlir/Transforms/GreedyPatternRewriteDriver.h"
using namespace mlir;

namespace tutorial {

#define GEN_PASS_DEF_AFFINEFULLUNROLLPATTERNREWRITER
#include "lib/Transform/Affine/Passes.h.inc"

struct AffineUnrollPattern : public OpRewritePattern<affine::AffineForOp> {
  AffineUnrollPattern(MLIRContext *ctx)
      : OpRewritePattern<affine::AffineForOp>(ctx, 1) {}
  LogicalResult matchAndRewrite(affine::AffineForOp op,
                                PatternRewriter &rewriter) {
    return affine::loopUnrollFull(op);
  }
};

struct AffineFullUnrollPatternRewriter
    : impl::AffineFullUnrollPatternRewriterBase<
          AffineFullUnrollPatternRewriter> {
  using AffineFullUnrollPatternRewriterBase::
      AffineFullUnrollPatternRewriterBase;

  void runOnOperation() {
    RewritePatternSet patterns(&getContext());
    patterns.add<AffineUnrollPattern>(&getContext());

    applyPatternsAndFoldGreedily(getOperation(), std::move(patterns));
  }
};
} // namespace tutorial