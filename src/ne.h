#ifndef ne_h
#define ne_h

/* ne.c */
void ne_loop(int region);
void ne_fin(void);
void sysinfo_path(char *s, const char *t);
void ne_init(void);
void ne_report(void);
_Bool ne_arg(int argc, char *argv[]);
void CommandCom(char *sys_buff);
void op_misc_exec(void);
void op_opt_linenum(void);
void op_misc_redraw(void);
void op_misc_insert_output(void);

#endif /* ne_h */
