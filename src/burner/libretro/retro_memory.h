#ifndef __RETRO_MEMORY__
#define __RETRO_MEMORY__

#include <string>
#include "libretro.h"
#include "burner.h"

extern void* MainRamData;
extern size_t MainRamSize;
extern bool bMainRamFound;

INT32 StateGetMainRamAcb(BurnArea *pba);

#endif
