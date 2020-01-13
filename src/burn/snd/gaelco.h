// gaelco sound
void    gaelcosnd_update(INT16 *outputs, INT32 samples);
UINT16  gaelcosnd_r(INT32 offset);
void    gaelcosnd_w(INT32 offset, UINT16 data);
void    gaelcosnd_start(UINT8 *soundrom, INT32 offs1, INT32 offs2, INT32 offs3, INT32 offs4);
void    gaelcosnd_exit();
void    gaelcosnd_scan(INT32 nAction, INT32*);
void    gaelcosnd_reset();
void    gaelcosnd_monoize();
void    gaelcosnd_swaplr();
