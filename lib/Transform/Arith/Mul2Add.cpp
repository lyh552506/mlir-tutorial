#include "Mul2Add.h"
#include "mlir/IR/PatternMatch.h"
#include "mlir/Transforms/GreedyPatternRewriteDriver.h"

namespace tutorial {
void Mul2AddPass::runOnOperation() {
  RewritePatternSet patternset(&getContext());
  patternset.add<PowerOfTwoExpand>(&getContext());
  patternset.add<PeelFromMul>(&getContext());

  applyPatternsAndFoldGreedily(getOperation(), std::move(patternset));
}
} // namespace tutorial