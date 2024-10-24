#ifndef LIB_TRANSFORM_AFFINE_PASSES_TD_
#define LIB_TRANSFORM_AFFINE_PASSES_TD_
include "mlir/Pass/PassBase.td"

def AffineFullUnrollPass:Pass<"affine-fully-unroll">{
    let summary="Fully unroll all affine loops";

    let description=[{
    Fully unroll all affine loops. (...)
  }];
    let dependentDialects=["mlir::affine::AffineDialect"];
}


def AffineFullUnrollPatternRewriter:Pass<"affine-fully-unroll-rewrite">{
    let summary="Fully unroll all affine loops using rewriter";
    let description=[{Fully unroll all affine loops. (...)}];

    let dependentDialects=["mlir::affine::AffineDialect"];
}

#endif   


