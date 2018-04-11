#ifndef CODEGEN_H_
#define CODEGEN_H_ 1

#include <stdio.h>
#include "ast.h"

int genCode(node *ast);
int print_to_file(node *ast);

#endif
