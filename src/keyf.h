#ifndef keyf_h
#define keyf_h

#include "ed.h"

#define	MAX_km	4096

typedef	enum	{KM_none,KM_set,KM_do}	kmmode_t;

typedef	struct	keylist
{
	int 			*buf;
	size_t 			n;		/* size of buffer */
	struct	keylist	*next;
}	kmlist_t;

typedef	struct
{
	kmmode_t	mode;
	int 		buf[MAX_km];
	int 		n,x;

	kmlist_t	*list;
}	keymacro_t;


/* keyf.c */
void km_init(void);
void km_fin(void);
void op_misc_kmacro(void);
kmlist_t *km_seek(int n);
void km_addkey(int c);
int km_getkey(void);
void km_set(int region, keydef_t *def, int k1, int k2);
void km_macro(keydef_t *def);
void keydef_init(void);
int keydef_num(int r);
keydef_t *keydef_set(int r, kdm_t kdm, int n, int k1, int k2);
keydef_t *keydef_get(int r, int k1, int k2);
int get_keyf(int region);
int keysel(const char *s, const char *t);
bool keysel_ynq(const char *s);
int keysel_yneq(const char *s);
void inkey_wait(const char *buffer);
const char *keyf_getarg(int n);
int keyf_numarg(void);

#endif /* keyf_h */
