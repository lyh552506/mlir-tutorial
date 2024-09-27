add_mlir_library(ArithOpt
    Mul2Add.cpp

    ${PROJECT_SOURCE_DIR}/lib/Transform/Arith/
    ADDITIONAL_HEADER_DIRS

    # DEPENDS
    # MLIRAffineFullUnrollPasses

    LINK_LIBS PUBLIC
)