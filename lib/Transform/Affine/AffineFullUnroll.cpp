#include "AffineFullUnroll.h"
#include "mlir/Dialect/Affine/IR/AffineOps.h"
#include "mlir/Dialect/Affine/LoopUtils.h"
#include "mlir/IR/PatternMatch.h"
#include "mlir/Support/LogicalResult.h"
#include "mlir/Transforms/GreedyPatternRewriteDriver.h"
using mlir::affine::AffineForOp;
using mlir::affine::loopUnrollFull;
namespace tutorial {
void AffineFullUnrollPass::runOnOperation() {
  getOperation()->walk([&](AffineForOp target) {
    if (failed(loopUnrollFull(target))) {
      target->emitError("Unrolling failed");
      signalPassFailure();
    }
  });
}

void AffineFullUnrollPatternRewriter::runOnOperation() {
  RewritePatternSet patterns(&getContext());
  patterns.add<AffineFullUnrollPattern>(&getContext());

  applyPatternsAndFoldGreedily(getOperation(), std::move(patterns));
}
} // namespace tutorial