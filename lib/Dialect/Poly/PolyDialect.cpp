#include "lib/Dialect/Poly/PolyDialect.h"
#include "lib/Dialect/Poly/PolyDialect.cpp.inc"
#include "lib/Dialect/Poly/PolyType.h"
#include "llvm/include/llvm/ADT/TypeSwitch.h"
#define GET_TYPEDEF_CLASSES
#include "lib/Dialect/Poly/PolyType.cpp.inc"

namespace mlir {
namespace tutorial {
namespace poly {
void PolyDialect::initialize() {
  addTypes<
#define GET_TYPEDEF_LIST
#include "lib/Dialect/Poly/PolyType.cpp.inc"
      >();
}

} // namespace poly
} // namespace tutorial
} // namespace mlir