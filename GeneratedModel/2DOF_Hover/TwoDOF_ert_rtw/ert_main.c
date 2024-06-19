#include <stddef.h>
#include <stdio.h>
#include "TwoDOF.h"

void rt_OneStep(void);
void rt_OneStep(void)
{
  static bool OverrunFlag = false;
  if (OverrunFlag) {
    rtmSetErrorStatus(TwoDOF_M, "Overrun");
    return;
  }

  OverrunFlag = true;
  TwoDOF_step();
  OverrunFlag = false;
}

int main(int argc, const char *argv[])
{
  (void)(argc);
  (void)(argv);
  TwoDOF_initialize();
  printf("Warning: The simulation will run forever. "
         "Generated ERT main won't simulate model step behavior. "
         "To change this behavior select the 'MAT-file logging' option.\n");
  fflush((NULL));
  while (rtmGetErrorStatus(TwoDOF_M) == (NULL)) {
  }

  TwoDOF_terminate();
  return 0;
}
