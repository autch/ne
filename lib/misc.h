#ifndef misc_h
#define misc_h

/* misc.c */
void strjncpy(char *s, const char *t, size_t ln);
int touchfile(const char *path, time_t atime, time_t mtime);
_Bool mole_dir(const char *s);
_Bool kanji_chk(const char *s, const char *t);

#endif /* misc_h */
