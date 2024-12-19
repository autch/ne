#ifndef crt_h
#define crt_h

#include "ed.h"
#include "disp.h"

typedef	struct
{
	int 	dline;	// 画面上のライン
	long	line;	// バッファの row

	block_t	bm;
}	crt_draw_t;


/* crt.c */
int GetMinRow(void);
int GetMaxRow(void);
int GetRowWidth(void);
int GetMinCol(void);
int GetMaxCol(void);
int GetColWidth(void);
void widthputs(const char *s, size_t len);
void crt_crmark(void);
void crt_draw_proc(const char *s, crt_draw_t *gp);
void CrtDrawAll(void);
void DeleteAndDraw(void);
void InsertAndDraw(void);
void RefreshMessage(void);
dspfmt_t *dspreg_guide(void *vp, int a, int sizex, int sizey);
void putDoubleKey(int key);
void delDoubleKey(void);
void system_guide_init(void);
void system_guide(void);
dspfmt_t *dspreg_sysmsg(void *vp, int a, int sizex, int sizey);
void system_msg(const char *buffer);

#endif /* crt_h */
