#include "Mul2Shl.h"
#include "mlir/IR/PatternMatch.h"
#include "mlir/Transforms/GreedyPatternRewriteDriver.h"
#include <algorithm>

namespace tutorial {
void Mul2ShlPass::runOnOperation() {
  RewritePatternSet patternset(&getContext());
  patternset.add<PowerOfTwoPattern>(&getContext());

  applyPatternsAndFoldGreedily(getOperation(), std::move(patternset));
}
} // namespace tutorial