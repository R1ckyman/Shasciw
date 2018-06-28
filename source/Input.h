#ifndef _Input_H_
#define _Input_H_

#include <switch.h>

class Input{
    public:
      static u32 getInput() { return hidKeysDown(CONTROLLER_P1_AUTO); };
};

#endif
