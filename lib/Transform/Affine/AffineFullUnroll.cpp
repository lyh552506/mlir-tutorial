#include "AffineFullUnroll.h"
#include "mlir/Dialect/Affine/IR/AffineOps.h"
#include "mlir/Dialect/Affine/LoopUtils.h"
#include "mlir/Support/LogicalResult.h"
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
} // namespace tutorial