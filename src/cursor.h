#ifndef cursor_h
#define cursor_h

/* cursor.c */
int GetCol(void);
int GetScroll(void);
int GetBufferOffset(void);
int GetRow(void);
long GetLineOffset(void);
void csr_fix(void);
void csr_lenew(void);
void csr_leupdate(void);
void csr_movehook(void);
void OffsetSetByColumn(void);
void csr_setlx(int lx);
void LineOffsetSet(long n);
void CursorSetRow(int n);
long csr_getsy(void);
void csr_setly(long n);
void csr_setdy(int dy);
void CursorMove(void);
void op_cursor_up(void);
void op_cursor_down(void);
void op_cursor_sleft(void);
void op_cursor_sright(void);
void op_cursor_tkprev(void);
void op_cursor_tknext(void);
void op_cursor_left(void);
void op_cursor_right(void);
void op_cursor_sup(void);
void op_cursor_sdown(void);
void op_cursor_top(void);
void op_cursor_bottom(void);
void op_cursor_pup(void);
void op_cursor_pdown(void);
void op_cursor_rup(void);
void op_cursor_rdown(void);

#endif /* cursor_h */
