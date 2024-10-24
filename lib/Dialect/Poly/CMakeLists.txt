file(GLOB POLY "${PROJECT_SOURCE_DIR}/lib/Dialect/Poly/*.cpp")

set(LLVM_TARGET_DEFINITIONS PolyOps.td)
# set(LLVM_TARGET_DEFINITIONS PolyType.td)
mlir_tablegen(PolyOps.h.inc -gen-op-decls)
mlir_tablegen(PolyOps.cpp.inc -gen-op-defs)
mlir_tablegen(PolyType.h.inc -gen-typedef-decls -typedefs-dialect=poly)
mlir_tablegen(PolyType.cpp.inc -gen-typedef-defs -typedefs-dialect=poly)
mlir_tablegen(PolyDialect.h.inc -gen-dialect-decls -dialect=poly)
mlir_tablegen(PolyDialect.cpp.inc -gen-dialect-defs -dialect=poly)
add_public_tablegen_target(MLIRPolyOpsIncGen)
add_dependencies(mlir-headers MLIRPolyOpsIncGen)


add_mlir_library(PolyDialect
	${POLY}
	${PROJECT_SOURCE_DIR}/lib/Dialect/Poly
	ADDITIONAL_HEADER_DIRS


	LINK_LIBS PUBLIC
)
