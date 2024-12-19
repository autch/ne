#ifndef iskanji_h
#define iskanji_h

/* iskanji.c */
_Bool iscnt(unsigned char c);
_Bool iskanji(int c);
int IsThisKanjiPosition(int offset, const char *buffer);
int IsKanjiPosition(void);
int char_getctype(int c);
int kanji_getctype(int c1, int c2);
int kanji_tknext(const char *s, int a, _Bool f);
int kanji_tkprev(const char *s, int a, _Bool f);
const char *kanji_fromeuc(char *s, size_t bytes, const char *t, int kc);
int file_knjchk(FILE *fp);
int file_gets(char *s, size_t bytes, FILE *fp, int *n_cr, int *n_lf);
void kanji_toeuc(char *s, size_t bytes, const char *t, _Bool f_sjis, int *jm);
int kanji_poscanon(int offset, const char *buf);
int kanji_poscandsp(int offset, const char *buf);
int kanji_posnext(int offset, const char *buf);
int kanji_posprev(int offset, const char *buf);
int kanji_posdsp(int offset, const char *buf);
int kanji_posbuf(int offset, const char *buf);
void strjfcpy(char *s, const char *t, size_t bytes, size_t len);
int kanji_countbuf(char c);
int kanji_countdsp(char c, int n);

#endif /* iskanji_h */
