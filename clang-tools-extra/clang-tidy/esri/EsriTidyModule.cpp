//===--- EsriTidyModule.cpp - clang-tidy ----------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "../ClangTidy.h"
#include "../ClangTidyModule.h"
#include "../ClangTidyModuleRegistry.h"
#include "ImplicitCastToSizetCheck.h"

namespace clang::tidy {
namespace esri {

class EsriTidyModule : public ClangTidyModule {
public:
  void addCheckFactories(ClangTidyCheckFactories &CheckFactories) override {
    CheckFactories.registerCheck<ImplicitCastToSizetCheck>(
        "esri-implicit-cast-to-sizet");
  }
};

// Register the EsriTidyModule using this statically initialized variable.
static ClangTidyModuleRegistry::Add<EsriTidyModule>
    X("esri-module", "Adds Esri-specific lint checks.");

} // namespace esri

// This anchor is used to force the linker to link in the generated object file
// and thus register the MiscModule.
volatile int EsriModuleAnchorSource = 0;

} // namespace clang::tidy
