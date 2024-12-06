set(LLVM_LINK_COMPONENTS
  support
  FrontendOpenMP
)

add_clang_library(clangTidyEsriModule
  EsriTidyModule.cpp

  LINK_LIBS
  clangTidy
  clangTidyUtils

  DEPENDS
  omp_gen
  ClangDriverOptions
)

clang_target_link_libraries(clangTidyEsriModule
  PRIVATE
  clangAnalysis
  clangAST
  clangASTMatchers
  clangBasic
  clangLex
  clangTooling
)
