// Feature tests of dynamic checking in Checked C
//
// The following lines are for the LLVM test harness:
//
// RUN: %clang -fcheckedc-extension -Xclang -verify -o %t.exe %s
// LLVM thinks that exiting via llvm.trap() is a crash.
// RUN: not --crash %t.exe

#include <stdbool.h>
#include "../../include/stdchecked.h"

int main(void) {
  // This is expected fail at runtime. It is simple enough for clang to issue a warning
  dynamic_check(false); // expected-warning {{dynamic check will always fail}}

  return 0;
}
