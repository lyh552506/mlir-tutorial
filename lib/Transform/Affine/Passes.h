#ifndef LIB_TRANSFORM_AFFINE_PASSES_H_
#define LIB_TRANSFORM_AFFINE_PASSES_H_

#include "lib/Transform/Affine/AffineFullUnroll.h"
#include "lib/Transform/Affine/AffineFullUnrollPatternRewriter.h"

using namespace mlir;
namespace tutorial {

#define GEN_PASS_REGISTRATION
#include "lib/Transform/Affine/Passes.h.inc"

}

#endif
