#include <stddef.h>
#include <stdio.h>
#include "Subsystem.h"

void rt_OneStep(void);
void rt_OneStep(void)
{
  static bool OverrunFlag = false;
  if (OverrunFlag) {
    rtmSetErrorStatus(Subsystem_M, "Overrun");
    return;
  }

  OverrunFlag = true;
  Subsystem_step();
  OverrunFlag = false;
}

int main(int argc, const char *argv[])
{
  (void)(argc);
  (void)(argv);
  Subsystem_initialize();
  printf("Warning: The simulation will run forever. "
         "Generated ERT main won't simulate model step behavior. "
         "To change this behavior select the 'MAT-file logging' option.\n");
  fflush((NULL));
  while (rtmGetErrorStatus(Subsystem_M) == (NULL)) {
  }

  Subsystem_terminate();
  return 0;
}
