#include "lib/Dialect/Poly/PolyOps.h"

#include "mlir/Dialect/CommonFolders.h"
#include "mlir/Dialect/Complex/IR/Complex.h"
#include "mlir/IR/BuiltinTypes.h"
#include "mlir/IR/OpDefinition.h"
#include "mlir/IR/PatternMatch.h"
#include "llvm/ADT/APInt.h"

namespace mlir {
namespace tutorial {
namespace poly {
OpFoldResult ConstantOp::fold(FoldAdaptor adaptor) {
  return adaptor.getCoefficients();
}

OpFoldResult AddOp::fold(FoldAdaptor adaptor) {
  return constFoldBinaryOp<IntegerType, llvm::APInt>(
      adaptor.getOperands(),
      [](llvm::APInt a, llvm::APInt b) { return a + b; });
}

OpFoldResult SubOp::fold(FoldAdaptor adaptor) {
  return constFoldBinaryOp<IntegerType, llvm::APInt>(
      adaptor.getOperands(),
      [](llvm::APInt a, llvm::APInt b) { return a - b; });
}

OpFoldResult MulOp::fold(FoldAdaptor adaptor) {
  return constFoldBinaryOp<IntegerType, llvm::APInt>(
      adaptor.getOperands(),
      [](llvm::APInt a, llvm::APInt b) { return a + b; });
}
} // namespace poly

} // namespace tutorial
} // namespace mlir
