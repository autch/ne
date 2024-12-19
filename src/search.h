#ifndef search_h
#define search_h

#include "../lib/regexp.h"

/* search.c */
void cursor_move(int lx, long ly);
void search_init(void);
void op_search_getword(void);
void search_clrword(void);
long search_next(const char *s, int x, long y, regm_t *rmp);
long search_prev(const char *s, int x, long y, regm_t *rmp);
void op_search_in(void);
void op_search_prev(void);
void op_search_next(void);
void replace(void);
void op_search_paging(void);
void op_search_repl_redo(void);
void op_search_repl(void);

#endif /* search_h */
