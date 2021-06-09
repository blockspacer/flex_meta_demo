# About

Example project for [https://github.com/blockspacer/flextool](https://github.com/blockspacer/flextool)

Uses conanfile and CMakeLists.txt to integrate with flextool

See `flex_meta_demo/src/main.cc` for usage example.

## Before installation

- [installation guide](https://blockspacer.github.io/flex_docs/download/)

- [usage guide](https://blockspacer.github.io/flex_docs/building_projects/)

- Build all required plugins:

`flex_meta_plugin` is plugin example that can be found at [https://github.com/blockspacer/flex_meta_plugin](https://github.com/blockspacer/flex_meta_plugin)

`flex_reflect_plugin` is plugin example that can be found at [https://github.com/blockspacer/flex_reflect_plugin](https://github.com/blockspacer/flex_reflect_plugin)

`flex_support_headers` is header-only library that can simplify usage of `Cling C++ interpreter` with flextool. `flex_support_headers` can be found at [https://github.com/blockspacer/flex_support_headers](https://github.com/blockspacer/flex_support_headers)

Make sure you installed `flex_reflect_plugin`, `flex_meta_plugin` and `flex_support_headers` using `conan`. You can find installation instructions in `README.md` at [https://github.com/blockspacer/flex_meta_plugin](https://github.com/blockspacer/flex_meta_plugin), [https://github.com/blockspacer/flex_support_headers](https://github.com/blockspacer/flex_support_headers) and  [https://github.com/blockspacer/flex_support_headers](https://github.com/blockspacer/flex_support_headers)

Note that plugins can depend on each other, so order of `conan create` may be important (or you will get build errors).

If you built flextool using `conan create`, than `flextool` must be in output of command `conan search flextool`. Same must apply for plugins, example: `conan search flex_meta_plugin`

## Installation

```bash
export VERBOSE=1
export CONAN_REVISIONS_ENABLED=1
export CONAN_VERBOSE_TRACEBACK=1
export CONAN_PRINT_RUN_COMMANDS=1
export CONAN_LOGGING_LEVEL=10
export GIT_SSL_NO_VERIFY=true

export CXX=clang++-10
export CC=clang-10

# NOTE: change `build_type=Debug` to `build_type=Release` in production
# NOTE: use --build=missing if you got error `ERROR: Missing prebuilt package`
cmake -E time \
  conan create . conan/stable \
  -s build_type=Debug -s cling_conan:build_type=Release \
  --profile clang \
      -o flex_meta_demo:enable_clang_from_conan=False \
      -e flex_meta_demo:enable_tests=True

# clean build cache
conan remove "*" --build --force
```
