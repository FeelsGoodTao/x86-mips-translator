#include "common.h"
#include "translate.h"
#include "allinstr.h"

void trans_push(char *mode, char *argus[])
{
  Log("push worker");
  if (!strcmp(mode, "r"))
  {
    trans_push_r(argus[0]);
  }
}

void trans_push_r(char *reg)
{
  int idx = get_reg_index(reg);
  fprintf(fp_out, "  addi $sp,$sp,-4\n");
  fprintf(fp_out, "  sw %s,$sp\n", mips_regs_name[idx]);
}