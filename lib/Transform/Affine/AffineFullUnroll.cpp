#include "AffineFullUnroll.h"
#include "mlir/Dialect/Affine/IR/AffineOps.h"
#include "mlir/Dialect/Affine/LoopUtils.h"
#include "mlir/IR/PatternMatch.h"
#include "mlir/Support/LogicalResult.h"
#include "mlir/Transforms/GreedyPatternRewriteDriver.h"
using namespace mlir;
namespace tutorial {
#define GEN_PASS_DEF_AFFINEFULLUNROLLPASS
#include "lib/Transform/Affine/Passes.h.inc"

struct AffineFullUnroll : impl::AffineFullUnrollPassBase<AffineFullUnroll> {
  using AffineFullUnrollPassBase::
      AffineFullUnrollPassBase; // 直接使用基类构造函数
  void runOnOperation() {
    getOperation()->walk([&](affine::AffineForOp op) {
      if (failed(affine::loopUnrollFull(op))) {
        op.emitError("Unrolling failed");
        signalPassFailure();
      }
    });
  }
};

} // namespace tutorial