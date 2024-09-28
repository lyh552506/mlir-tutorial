file(GLOB ARITH "${PROJECT_SOURCE_DIR}/lib/Transform/Arith/*.cpp")

add_mlir_library(ArithOpt
    ${ARITH}

    ${PROJECT_SOURCE_DIR}/lib/Transform/Arith/
    ADDITIONAL_HEADER_DIRS

    # DEPENDS
    # MLIRAffineFullUnrollPasses

    LINK_LIBS PUBLIC
)