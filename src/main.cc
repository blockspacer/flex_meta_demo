#include "project_specific_header.hpp"

#include "codegen_macros.hpp"

#include <cling/Interpreter/Interpreter.h>

#include <llvm/ADT/Optional.h>

#include <clang/Rewrite/Core/Rewriter.h>
#include <clang/ASTMatchers/ASTMatchFinder.h>

#include "flexlib/utils.hpp"

#include "flexlib/funcParser.hpp"
#include "flexlib/inputThread.hpp"

#include "flexlib/clangUtils.hpp"

#include "flexlib/clangPipeline.hpp"

#include "flexlib/annotation_parser.hpp"
#include "flexlib/annotation_match_handler.hpp"

#include "flexlib/matchers/annotation_matcher.hpp"

#include "flexlib/options/ctp/options.hpp"

#if defined(CLING_IS_ON)
#include "flexlib/ClingInterpreterModule.hpp"
#endif // CLING_IS_ON

//#include "flexlib/ctp_registry.hpp"

#include <base/logging.h>
#include <base/cpu.h>
#include <base/bind.h>
#include <base/command_line.h>
#include <base/debug/alias.h>
#include <base/debug/stack_trace.h>
#include <base/memory/ptr_util.h>
#include <base/sequenced_task_runner.h>
#include <base/strings/string_util.h>
#include <base/trace_event/trace_event.h>

#include <string>
#include <iostream>

#include <vector>
#include <string>
#include <iostream>

// will be replaced with empty string
__attribute__((annotate("{gen};{executeCode};\
printf(\"Hello me!\");"))) \
int SOME_UNIQUE_NAME1
;

// will be replaced with empty string
$executeCodeLine(LOG(INFO) << "Hello world!";)
int a0;

// will be replaced with empty string
$executeCodeAndEmptyReplace(
  LOG(INFO) << "Hello me!";
) int a1;

// will be replaced with int a12347
$executeCodeAndReplace(
  new llvm::Optional<std::string>{"int a12347;"};
) int a2;

// will be replaced with int a56
$executeCodeAndReplace(
  new llvm::Optional<std::string>{"int a56;"};
) int a3;

// will be replaced with 234432
namespace
$executeCodeAndReplace(
  new llvm::Optional<std::string>{"int a234432;"};
) {}

#include <string>
#include <vector>

struct
  $apply(
    make_reflect
  )
SomeStructName {
 public:
  SomeStructName() {
    // ...
  }
 private:
  const int m_bar2 = 2;

  __attribute__((annotate("{gen};{attr};reflectable;")))
  std::vector<std::string> m_VecStr2;
};

int main(int argc, char** argv) {
  Bar bar;

  bar.foo = 1;

  std::cout << "bar.foo = " << bar.foo;

  return 0;
}
