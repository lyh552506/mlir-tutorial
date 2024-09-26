#include "mlir/Dialect/Arith/IR/Arith.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/IR/AsmState.h"
#include "mlir/IR/Builders.h"
#include "mlir/IR/BuiltinOps.h"
#include "mlir/IR/DialectRegistry.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/IR/ValueRange.h"
#include "mlir/Parser/Parser.h"
#include "mlir/Support/FileUtilities.h"
#include "llvm/Support/raw_ostream.h"
#include "mlir/InitAllDialects.h"
using namespace mlir;
int main(int argc, char *argv[]) {
    DialectRegistry registry;
    registerAllDialects(registry);
    
//   MLIRContext ctx;
//   ctx.loadDialect<func::FuncDialect, arith::ArithDialect>();

//   OpBuilder builder(&ctx);
//   auto mod = builder.create<ModuleOp>(builder.getUnknownLoc());
//   builder.setInsertionPointToEnd(mod.getBody());
//   // build func
//   auto funcTp = builder.getFunctionType(
//       {builder.getI32Type(), builder.getI32Type()}, builder.getI32Type());
//   auto func =
//       builder.create<func::FuncOp>(builder.getUnknownLoc(), "Test", funcTp);

//   auto entry = func.addEntryBlock();
//   auto args = entry->getArguments();

//   builder.setInsertionPointToEnd(entry);

//   auto addi =
//       builder.create<arith::AddIOp>(builder.getUnknownLoc(), args[0], args[1]);
//   builder.create<func::ReturnOp>(builder.getUnknownLoc(), ValueRange{addi});
  //   auto src = parseSourceFile<ModuleOp>(argv[1], &ctx);
  //   src->print(llvm::outs());
//   mod->print(llvm::outs());
  return 0;
}