/*--------------------------------------------------------------------
  filer module.

    Copyright (c) 1998,1999,2000 SASAKI Shunsuke.
    All rights reserved. 
--------------------------------------------------------------------*/
#ifndef filer_h
#define filer_h

#include	"ed.h"

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<errno.h>


typedef	struct	fitem
{
	char			*fn;
	char			*e;
	struct	stat	stat;

	struct	fitem	*next;
}	fitem_t;

typedef	struct
{
	fitem_t	*fitem;
	int 	n;
}	flist_t;

typedef	struct
{
	char	path[LN_path +1];

	menu_t	menu;
	bool	df;

	flist_t	flist;
	fitem_t	**findex;
	int 	*mark;
	int 	markmax;
	int 	marknum;

	char	match[LN_path+1];
}	fw_t;
#define	fw_c	fw[eff.wa]

typedef	struct
{
	int 	wn;			/* window�ο� */
	int 	wa;			/* Window Active ���� */
	bool	df;			/* dirty flag */

	int 	sort[2];	/* sort���� */
}	eff_t;

enum	{SA_none,SA_fname,SA_ext};

typedef struct	fop
{
	int 	(*file_func)(const char*,struct stat *,const char*, struct fop*);
	int 	(*dir_func)(const char*,struct stat *,const char*
														,bool, struct fop*);
	char    *title;

	int 	om;		/* overwrite mode. */
	int 	pfm;	/* permition force mode. */

	int 	en;		/* error number */
}	fop_t;

#define	FR_err		-1
#define	FR_ok		0
#define	FR_end		1
#define	FR_nonrec	2

#define	FO_owrite	1
#define	FO_update	2
#define	FO_none		3
#define	FO_rename	4

#define	FP_ignore	1
#define	FP_force	2


extern	bool	need_filer( const char* pszFileName );

/* filer.c */
void dm_init(void);
void dm_set(const char *p, const char *s);
void dm_get(const char *p, char *s);
void fw_init(fw_t *fwp, const char *s, int a);
void eff_init(const char *s1, const char *s2);
struct stat *fw_getstat(fw_t *fwp, int a);
fitem_t *fw_getfi(fw_t *fwp, int a);
void fwc_chdir(const char *s, _Bool f);
void fw_match(fw_t *fwp);
fitem_t *fitem_free(fitem_t *fip);
void fw_free(fw_t *fwp);
fitem_t *fitem_mk(const char *path, char *s);
void flist_set(flist_t *flp, const char *path);
fitem_t **findex_get(flist_t *flp);
void prt_kmsize(char *s, off_t n);
void fw_make(fw_t *fwp);
int fw_getmarkfirst(fw_t *fwp);
void fw_chmark(fw_t *fwp, int a);
void fw_chmarkall(fw_t *fwp);
int fw_fop_file(const char *srcpath, const char *fn, struct stat *srcstp, const char *dstpath, fop_t *fop);
int fw_fop_dir(const char *srcpath, const char *fn, struct stat *srcstp, const char *dstpath, fop_t *fop, _Bool wf);
int fw_fop_list(fitem_t **findex, size_t fi_nums, const char *srcpath, const char *dstpath, fop_t *fop);
void fw_fop(fw_t *srcfwp, const char *dstpath, char *title, int file_func(const char *, struct stat *, const char *, fop_t *), int dir_func(const char *, struct stat *, const char *, _Bool, fop_t *));
_Bool fw_cpdest(char *s, fw_t *srcfwp, fw_t *dstfwp);
void fw_copy(fw_t *srcfwp, fw_t *dstfwp);
void fw_move(fw_t *srcfwp, fw_t *dstfwp);
void fw_remove(fw_t *srcfwp, fw_t *dstfwp);
void fw_rename(fw_t *fwp);
void fw_mkdir(fw_t *fwp);
char *pval_parse(const char *s, char *t);
_Bool eff_exec(void);
_Bool eff_filer(char *fn);

#endif /* filer_h */
