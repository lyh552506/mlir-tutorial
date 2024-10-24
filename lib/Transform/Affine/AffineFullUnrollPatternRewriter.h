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



#define GEN_PASS_DECL_AFFINEFULLUNROLLPATTERNREWRITER
#include "lib/Transform/Affine/Passes.h.inc"
}