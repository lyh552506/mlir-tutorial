
#ifndef _LIB_DIALECT_POLY_POLYTYPE_TD_
#define _LIB_DIALECT_POLY_POLYTYPE_TD_
include "PolyDialect.td"
include "mlir/IR/AttrTypeBase.td"

class PolyType<string name,string typeMnemonic>:TypeDef<Poly_Dialect,name>{
	let mnemonic=typeMnemonic;
}

def Poly:PolyType<"Polynomial","poly">{
	let summary = "A polynomial with i32 coefficients";

    let description = [{
    A type for polynomials with integer coefficients in a single-variable polynomial ring.
  }];

    let parameters=(ins "int":$Bound);
	let assemblyFormat="`<`$Bound`>`";
}


#endif

