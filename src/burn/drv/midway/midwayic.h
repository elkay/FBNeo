#ifndef SERIALPIC
#define SERIALPIC

void MidwaySerialPicInit(INT32 upper);
void MidwaySerialPicReset();
UINT32 MidwaySerialPicStatus();
UINT8 MidwaySerialPicRead();
void MidwaySerialPicWrite(UINT8 data);

#endif // SERIALPIC

