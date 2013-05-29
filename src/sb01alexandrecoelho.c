/* strtok example */
#include <stdio.h>
#include <string.h>

#include "includes/parser.h"


int main ()
{
  char str[] ="INPUT N1";
  instruction* inst = str_to_instrction(str);
  printf("\nmm %s, op1 %s, op2 %s, op3 %s", inst->mnemonico, inst->op1, inst->op2, inst->op3);

  return 0;
}
