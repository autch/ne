#ifndef lineedit_h
#define lineedit_h

/* lineedit.c */
int le_getcsx(le_t *lep);
void le_setlx(le_t *lep, int lx);
void le_csrleftside(le_t *lep);
void le_csrrightside(le_t *lep);
void le_csrleft(le_t *lep);
void le_csrright(le_t *lep);
void le_edit(le_t *lep, int ch, int cm);
size_t le_regbuf(const char *s, char *t);
void legets_hist(le_t *lep, int hn, int hy);
_Bool legets_histprev(le_t *lep, int hn, int *hy);
_Bool legets_histnext(le_t *lep, int hn, int *hy);
dspfmt_t *dspreg_legets(void *vp, int a, int sizex, int sizey);
int legets_gets(const char *msg, char *s, int dsize, int size, int hn);

#endif /* lineedit_h */
