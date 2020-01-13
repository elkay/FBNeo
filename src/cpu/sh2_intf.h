#include <stdint.h>

#ifndef FASTCALL
 #undef __fastcall
 #define __fastcall
#endif

typedef UINT8 (__fastcall *pSh2ReadByteHandler)(UINT32 a);
typedef void (__fastcall *pSh2WriteByteHandler)(UINT32 a, UINT8 d);
typedef UINT16 (__fastcall *pSh2ReadWordHandler)(UINT32 a);
typedef void (__fastcall *pSh2WriteWordHandler)(UINT32 a, UINT16 d);
typedef UINT32 (__fastcall *pSh2ReadLongHandler)(UINT32 a);
typedef void (__fastcall *pSh2WriteLongHandler)(UINT32 a, UINT32 d);

extern int has_sh2;
extern INT32 cps3speedhack;
extern INT32 sh2_busyloop_speedhack_mode2;

void __fastcall Sh2WriteByte(unsigned int a, unsigned char d);
unsigned char __fastcall Sh2ReadByte(unsigned int a);

INT32 Sh2Init(INT32 nCount);
int Sh2Exit();

void Sh2Open(const INT32 i);
void Sh2Close();
INT32 Sh2GetActive();

void Sh2Reset();
void Sh2Reset(UINT32 pc, UINT32 r15); // hack
INT32 Sh2Run(INT32 cycles);

int Sh2MapMemory(unsigned char* pMemory, unsigned int nStart, unsigned int nEnd, int nType);
int Sh2MapHandler(uintptr_t nHandler, unsigned int nStart, unsigned int nEnd, int nType);

int Sh2SetReadByteHandler(int i, pSh2ReadByteHandler pHandler);
int Sh2SetWriteByteHandler(int i, pSh2WriteByteHandler pHandler);
int Sh2SetReadWordHandler(int i, pSh2ReadWordHandler pHandler);
int Sh2SetWriteWordHandler(int i, pSh2WriteWordHandler pHandler);
int Sh2SetReadLongHandler(int i, pSh2ReadLongHandler pHandler);
int Sh2SetWriteLongHandler(int i, pSh2WriteLongHandler pHandler);

void Sh2SetIRQLine(const int line, const int state);

unsigned int Sh2GetPC(int n);
void Sh2StopRun();
void Sh2SetVBR(unsigned int i);

void Sh2BurnUntilInt(int);

INT32 Sh2TotalCycles();
void Sh2NewFrame();
void Sh2BurnCycles(int cycles);
void Sh2Idle(int cycles);
void Sh2SetEatCycles(int i);

int Sh2Scan(int);


void Sh2CheatWriteByte(UINT32 a, UINT8 d); // cheat core
UINT8 Sh2CheatReadByte(UINT32 a);

extern struct cpu_core_config Sh2Config;

// depreciate this and use BurnTimerAttach directly!
#define BurnTimerAttachSh2(clock)	\
	BurnTimerAttach(&Sh2Config, clock)
