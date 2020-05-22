#pragma once

/// \note You can conditionally disable some macro using:
/// defined(CLANG_ENABLED) || defined(CLING_ENABLED)
/// \todo use defined(...) to create executeCodeLineAndKeepInSourceFile

// \note if you don't want to keep trailing ';'
// then place __attribute__ near `namespace{}` like below:
/**
// will be replaced with 234432
namespace
_executeCodeAndReplace(
  new llvm::Optional<std::string>{"234432"};
) {}
  **/

/**
 * USAGE:

// will be replaced with empty string
__attribute__((annotate("{gen};{executeCode};\
printf(\"Hello me!\");"))) \
int SOME_UNIQUE_NAME1
;

// will be replaced with empty string
_executeCodeLine(LOG(INFO) << "Hello world!";)
int a0;

// will be replaced with empty string
_executeCodeAndEmptyReplace(
  LOG(INFO) << "Hello me!";
) int a1;

// will be replaced with 1234711
class
_executeCodeAndReplace(
  new llvm::Optional<std::string>{"1234711"};
) {};

// will be replaced with 56
_executeCodeAndReplace(
  new llvm::Optional<std::string>{"56"};
) int a3;

#include <string>
#include <vector>

struct
  _apply(
    make_reflect
  )
SomeStructName {
 public:
  SomeStructName() {
    // ...
  }
 private:
  //__attribute__((annotate("{gen};{attr};reflectable;")))
  const int m_bar2 = 2;

  __attribute__((annotate("{gen};{attr};reflectable;")))
  std::vector<std::string> m_VecStr2;
};
  **/

#define GEN_CAT(a, b) GEN_CAT_I(a, b)
#define GEN_CAT_I(a, b) GEN_CAT_II(~, a ## b)
#define GEN_CAT_II(p, res) res

/**
 * USAGE:
// will be replaced with 123471
_executeCodeAndReplace(
  new llvm::Optional<std::string>{"123471"};
) int GEN_UNIQUE_NAME(__tmp__executeCodeAndReplace);
 **/
#define GEN_UNIQUE_NAME(base) GEN_CAT(base, __COUNTER__)

// executeStringWithoutSpaces executes code
// unlike exec, executeStringWithoutSpaces may use `#include` e.t.c.
// no return value
// does not support newline characters or spaces
// may use `#include` or preprocessor macros
// example:
//   _executeStringWithoutSpaces("#include <cling/Interpreter/Interpreter.h>")
// if you need to execute multiline C++ code line - use "executeCode"
/**
  EXAMPLE:
    // will be replaced with empty string
    __attribute__((annotate("{gen};{executeCode};\
    printf(\"Hello world!\");"))) \
    int SOME_UNIQUE_NAME0
    ;
    // if nothing printed, then
    // replace printf with
    // LOG(INFO)<<\"Hello!\";"))) \
**/
#define _executeStringWithoutSpaces(...) \
  /* generate definition required to use __attribute__ */ \
  __attribute__((annotate("{gen};{executeCode};" __VA_ARGS__)))

// executeStringWithoutSpaces that can accept not quoted code line
/**
  EXAMPLE:
    // will be replaced with empty string
    _executeCodeLine(LOG(INFO) << "Hello world!";)
**/
#define _executeCodeLine(...) \
  __attribute__((annotate("{gen};{executeCode};" #__VA_ARGS__ )))

// executeCodeAndReplace executes code and
// returns (optional) source code modification
#define _executeCodeAndReplace(...) \
  /* generate definition required to use __attribute__ */ \
  __attribute__((annotate("{gen};{executeCodeAndReplace};" #__VA_ARGS__)))

// shortened executeCodeAndReplace syntax
// param1 - returns (optional) source code modification
#define _executeCodeAndReplaceTo(RETVAL, ...) \
  /* generate definition required to use __attribute__ */ \
  __attribute__((annotate( \
      "{gen};{executeCodeAndReplace};" \
      "[&clangMatchResult, &clangRewriter, &clangDecl]() {" \
        #__VA_ARGS__ \
        "return new llvm::Optional<std::string>{" \
          #RETVAL \
          "};" \
      "}();" \
    )))

// exec is similar to executeCodeAndReplace,
// but returns empty source code modification
#define _executeCodeAndEmptyReplace(...) \
  /* generate definition required to use __attribute__ */ \
  __attribute__((annotate( \
      "{gen};{executeCodeAndReplace};" \
      "[&clangMatchResult, &clangRewriter, &clangDecl]() {" \
        #__VA_ARGS__ \
        "return new llvm::Optional<std::string>{\"\"};" \
      "}();" \
    )))

#define _apply(...) \
  __attribute__((annotate("{gen};{funccall};" #__VA_ARGS__)))

