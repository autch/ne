#ifndef block_h
#define block_h

/* block.c */
void block_set(block_t *bp);
_Bool block_range(long n, block_t *bp, int *x_st, int *x_ed);
int GetBlockFlg(void);
void block_cmove(void);
void bstack_init(void);
void bstack_fin(void);
int block_size(block_t *bp);
_Bool bstack_copy(void);
void block_cut(void);
void BlockInit(void);
void op_block_start(void);
_Bool BlockCommand(void);
void op_block_yanc(void);
void op_block_cut(void);
const char *str_paste(char *s, const char *p);
void bstack_paste(void);
void op_block_paste(void);
void op_block_copy(void);
void op_block_dup(void);
void op_block_kill(void);
void op_block_chlast(void);

#endif /* block_h */
