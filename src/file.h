#ifndef file_c
#define file_c

#include <stdio.h>
#include "ed.h"

/* file.c */
void FileStartInit(bool f);
void edbuf_init(void);
bool edbuf_lock(bool func(FILE *, const char *), const char *fn);
bool edbuf_rm_func(FILE *fp, const char *fn);
void edbuf_rm(int n);
bool edbuf_add_func(FILE *fp, const char *fn);
bool edbuf_add(const char *fn);
bool edbuf_mv(int n, const char *fn);
bool CheckFileAccess(const char *fn);
bool file_change(int n);
void SetFileChangeFlag(void);
void ResetFileChangeFlag(void);
int CheckFileOpened(const char *fn);
int FindOutNextFile(int no);
int GetBackFile(int n);
void filesave_proc(const char *s, FILE *fp);
int filesave(char *filename, bool f);
void *file_open_proc(char *s, kinfo_t *kip);
void *file_new_proc(char *s, void *vp);
int fileopen(char *filename);
bool file_insert(char *filename);
bool RenameFile(int current_no, const char *s);
bool FileOpenOp(const char *path);
bool _op_file_open(void);
void op_file_open(void);
void op_file_insert(void);
void op_file_save(void);
void op_file_profile(void);
bool fileclose(int n);
bool _op_file_close(void);
void op_file_close(void);
void op_file_aclose(void);
void op_file_quit(void);
void op_file_undo(void);
void op_menu_file(void);
void op_file_copen(void);
void op_file_toggle(void);
int SelectFileMenu(void);
void op_file_select(void);
void op_file_rename(void);

#endif /* file_c */
