#ifndef setopt_h
#define setopt_h

/* setopt.c */
void key_set(void);
void sysinfo_optset(void);
void opt_set(const char *s, const char *t);
void op_opt_set(void);
void opt_default(void);
void option_set_proc(int a, mitem_t *mip, void *vp);
void SeeOption(void);
void op_menu_opt(void);
void op_opt_kanji(void);
void op_opt_retmode(void);
void op_opt_tab(void);
void config_read(char *path);

#endif /* setopt_h */
