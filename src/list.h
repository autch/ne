#ifndef list_h
#define list_h

typedef void* (*list_func)(char*, void*);
typedef void (*lists_proc_func)(char*, void*);

#include "ed.h"

/* list.c */
long GetTopNumber(void);
long GetLastNumber(void);
EditLine *GetTop(void);
EditLine *GetLast(void);
void lists_debug(void);
void lists_init(void);
void lists_clear(void);
EditLine *MakeLine(const char *buffer);
void Realloc(EditLine *li, const char *s);
void AppendLast(EditLine *li);
void InsertLine(EditLine *bli, EditLine *li);
void DeleteList(EditLine *li);
EditLine *GetList(long o_number);
size_t lists_size(long n_st, long n_en);
void lists_proc(lists_proc_func func, void *gp, long n_st, long n_en);
void lists_add(list_func func, void *gp);
void lists_delete(int n_st, int n_ed);

#endif /* list_h */
