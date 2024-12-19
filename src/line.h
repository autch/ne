#ifndef line_h
#define line_h

/* line.c */
void se_insert(const char *s, bool f);
void se_delete(int n, bool f);
void se_nazo(void);
void line_catnext(void);
void line_catprev(void);
void op_del_tknext(void);
void op_del_tkprev(void);
void op_del_sright(void);
void op_del_sleft(void);
void op_del_char(void);
void op_del_bs(void);
void split(bool f);
void op_line_cr(void);
void op_line_new(void);
int CatLine(void);
void op_char_input(void);
void tagJmp(void);
void op_jump_tag(void);
void op_jump_line(void);
void lm_mark(int ln, int n);
int lm_line(int n);
void op_jump_mark(void);
void op_jump_before(void);
void op_char_undo(void);
void udbuf_init(void);
void udbuf_get(char *s);
void udbuf_set(bool df, const char *s);
void undo_add(bool df, const char *s);
void undo_paste(void);
void op_line_undo(void);

#endif /* line_h */
