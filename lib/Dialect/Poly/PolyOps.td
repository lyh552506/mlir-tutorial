#ifndef _LIB_DIALECT_POLY_POLYOPS_TD_
#define _LIB_DIALECT_POLY_POLYOPS_TD_

include "PolyDialect.td"
include "PolyType.td"
include "mlir/IR/OpBase.td"


def Poly_AddOp:Op<Poly_Dialect,"add">{
	let summary="Addition operation between poly";

	let arguments=(ins Poly:$lhs,Poly:$rhs);
	let results=(outs Poly:$output);
	let assemblyFormat="$lhs `,` $rhs attr-dict `:` `(` type($lhs) `,` type($rhs) `)` `->` type($output)";
}



#endif

