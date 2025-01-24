#ifndef _LIB_DIALECT_POLY_POLYOPS_TD_
#define _LIB_DIALECT_POLY_POLYOPS_TD_

include "PolyDialect.td"
include "PolyType.td"
include "mlir/IR/OpBase.td"
include "mlir/Interfaces/SideEffectInterfaces.td"
//can be used in tensor,vector..etc
def PolyOrContainer:TypeOrContainer<Poly,"poly-or-container">;


class Poly_BinOp<string mnemonic>:Op<Poly_Dialect,mnemonic,[Pure,ElementwiseMappable,SameOperandsAndResultElementType]>{
	let summary="Binary operation between poly";

	let arguments=(ins PolyOrContainer:$lhs,PolyOrContainer:$rhs);
	let results=(outs PolyOrContainer:$output);
	let assemblyFormat="$lhs `,` $rhs attr-dict `:` `(` type($lhs) `,` type($rhs) `)` `->` type($output)";

	let hasFolder=1;
}


def Poly_AddOp:Poly_BinOp<"add">{
	let summary="Addition operation between poly";
}


def Poly_SubOp:Poly_BinOp<"sub">{
	let summary="sub";
}


def Poly_MulOp:Poly_BinOp<"mul">{
	let summary="mul";
}

def Poly_FromTensor:Op<Poly_Dialect,"from_tensor",[Pure]>{
	let summary="Creates a Polynomial from integer coefficients stored in a tensor.";

	let arguments=(ins TensorOf<[AnyInteger]>:$input);
	let results=(outs Poly:$output);
	let assemblyFormat="$input attr-dict `:` type($input) `->` type($output)";
}

def Poly_Eval:Op<Poly_Dialect,"eval">{
	let summary="Evaluates a Polynomial at a given input value.";

	let arguments=(ins Poly:$lhs,AnyInteger:$rhs);
	let results=(outs AnyInteger:$output);
	let assemblyFormat="$lhs `,` $rhs attr-dict `:` `(` type($lhs) `,` type($rhs) `)` `->` type($output)";
}


def Poly_ConstantOp : Op<Poly_Dialect, "constant", [Pure, ConstantLike]> {
  let summary = "Define a constant polynomial via an attribute.";
  let arguments = (ins AnyIntElementsAttr:$coefficients);
  let results = (outs Poly:$output);
  let assemblyFormat = "$coefficients attr-dict `:` qualified(type($output))";
  let hasFolder = 1;
}

#endif

