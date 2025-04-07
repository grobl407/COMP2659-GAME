# 1 "bbreak.c" 1
# 1 "C:/c68/include/osbind.h" 1
# 1 "C:/c68/include/compiler.h" 1
# 9 "C:/c68/include/osbind.h" 2
# 1 "C:/c68/include/ostruct.h" 1
# 22 "C:/c68/include/ostruct.h"
typedef struct {
    long b_free;
    long b_total;
    long b_secsiz;
    long b_clsiz;
} _DISKINFO;


typedef struct {
  short time;
  short date;
} _DOSTIME;


typedef struct
{
        unsigned char maxlen;
        unsigned char actuallen;
        char    buffer[255];
} _CCONLINE;
# 48 "C:/c68/include/ostruct.h"
typedef struct _dta {
    char 	    dta_buf[21];
    char            dta_attribute;
    unsigned short  dta_time;
    unsigned short  dta_date;
    long            dta_size;
    char            dta_name[14];
} _DTA;
# 98 "C:/c68/include/ostruct.h"
typedef struct {
  short recsiz;
  short clsiz;
  short clsizb;
  short rdlen;
  short fsiz;
  short fatrec;
  short datrec;
  short numcl;
  short bflags;
} _BPB;




typedef struct _md {
    struct _md	*md_next;
    long	 md_start;
    long	 md_length;
    long	 md_owner;
} _MD;


typedef struct {
    _MD *mp_free;
    _MD *mp_used;
    _MD *mp_rover;
} _MPB;
# 141 "C:/c68/include/ostruct.h"
typedef struct {
    char    *ibuf;
    short   ibufsiz;
    volatile short   ibufhd;
    volatile short   ibuftl;
    short   ibuflow;
    short   ibufhi;
} _IOREC;


typedef struct {
	char	topmode;
	char	buttons;
	char	xparam;
	char	yparam;
	short	xmax;
	short	ymax;
	short	xstart;
	short	ystart;
} _PARAM;


typedef struct {
    void    (*midivec)	(void) ;
    void    (*vkbderr)	(void) ;
    void    (*vmiderr)	(void) ;
    void    (*statvec)	(void *) ;
    void    (*mousevec)	(void *) ;
    void    (*clockvec)	(void *) ;
    void    (*joyvec)	(void *) ;
    long    (*midisys)	(void) ;
    long    (*ikbdsys)	(void) ;
    char    kbstate;
} _KBDVECS;


typedef struct {
    void *unshift;
    void *shift;
    void *caps;
} _KEYTAB;


typedef struct
{
        void    *pb_scrptr;
        int     pb_offset;
        int     pb_width;
        int     pb_height;
        int     pb_left;
        int     pb_right;
        int     pb_screz;
        int     pb_prrez;
        void    *pb_colptr;
        int     pb_prtype;
        int     pb_prport;
        void    *pb_mask;
} _PBDEF;
# 17 "C:/c68/include/osbind.h" 2
# 33 "C:/c68/include/osbind.h"
 long _trap_1_w		(short) ;
 long _trap_1_ww	(short,short) ;
 long _trap_1_wl	(short,long) ;
 long _trap_1_wlw	(short,long,short) ;
 long _trap_1_wwll	(short,short,long,long) ;
 long _trap_1_wlww	(short,long,short,short) ;
 long _trap_1_www	(short,short,short) ;
 long _trap_1_wll	(short,long,long) ;
 long _trap_1_wwlll	(short,short,long,long,long) ;
 long _trap_1_wwwll	(short,short,short,long,long) ;
 long _trap_13_wl	(short,long) ;
 long _trap_13_w	(short) ;
 long _trap_13_ww	(short,short) ;
 long _trap_13_www	(short,short,short) ;
 long _trap_13_wwlwww	(short,short,long,short,short,short) ;
 long _trap_13_wwl	(short,short,long) ;
 long _trap_14_wwl	(short,short,long) ;
 long _trap_14_wwll	(short,short,long,long) ;
 long _trap_14_ww	(short,short) ;
 long _trap_14_w	(short) ;
 long _trap_14_wllw	(short,long,long,short) ;
 long _trap_14_wl	(short,long) ;
 long _trap_14_www	(short,short,short) ;
 long _trap_14_wllwwwww (short,long,long,short,short,short,short,short) ;
 long _trap_14_wllwwwwlw (short,long,long,short,short,short,short,long,short) ;
 long _trap_14_wllwwwwwlw (short,long,long,short,short,short,short,short,long,short) ;
 long _trap_14_wwwwwww	(short,short,short,short,short,short,short) ;
 long _trap_14_wlll	(short,long,long,long) ;
 long _trap_14_wllww	(short,long,long,short,short) ;
 long _trap_14_wwwwl	(short,short,short,short,long) ;
 long _trap_14_wwwl	(short,short,short,long) ;
 long _trap_14_wlwlw	(short,long,short,long,short) ;
# 103 "C:/c68/include/osbind.h"
 long _trap_1_ 	(short,...) ;
 long _trap_14_ 	(short,...) ;
 long _trap_13_ 	(short,...) ;
# 1 "bbreak.c" 2
# 1 "./../stg3/model.h" 1
# 1 "./../stg3/TYPES.H" 1



typedef unsigned char UINT8;
typedef unsigned int  UINT16;
typedef unsigned long UINT32;
typedef unsigned int long UINT64;
# 4 "./../stg3/model.h" 2
# 1 "./../stg3/../stg4/bitmap.h" 1
# 1 "./../stg3/../stg4/types.h" 1
# 4 "./../stg3/../stg4/bitmap.h" 2


extern UINT16 ball_bitmap[];
extern UINT32 paddle_bitmap[];
extern UINT32 full_brick_map[];
extern UINT32 semi_cracked_map[];
extern UINT32 cracked_brick_map[];
extern UINT32 almost_broken_map[];
extern UINT32 broken_brick_map[];
extern UINT32 clear_brickmap[];
extern UINT16 heart_map[];
extern UINT32 clear_paddle[];
# 5 "./../stg3/model.h" 2



typedef struct {
  unsigned int x, y;
  int delta_x;
  int delta_y;
  int isActive;
  int size_x;
  int size_y;
  UINT16 *ball_bitmap;
} Ball;

typedef struct {
  unsigned int x, y;
  int isBroken;
  int base_points;
  int size_x;
  int size_y;
  int health;

  UINT32 *full_brick_map;
  UINT32 *semi_cracked_map;
  UINT32 *cracked_brick_map;
  UINT32 *almost_broken_map;
  UINT32 *broken_brick_map;
  UINT32 *clear_brickmap;
} Brick;

typedef struct {
  unsigned int x;
} Wall;

typedef struct {
  unsigned int y;
} Ceiling;

typedef struct {
  unsigned int y;
} Floor;

typedef struct {
  unsigned int x, y;
  int size_x;
  int size_y;
  int p_input;
  int move_dist;
  UINT32 *paddle_bitmap;
  UINT32 *clear_paddle;

} Paddle;

typedef struct {
  int x, y;
  UINT16 *heart_map;

}Heart;

typedef struct {
  Brick brick;
  Ball ball;
  Paddle paddle;
  Heart heart;
} Model;


typedef struct {
  int score;
  int lives;
  int level;
  int game_over;
  int paused;
} Game;



void ball_collisions(Ball *ball, Paddle *paddle, Brick bricks[], int num_bricks,
  Wall *left_wall, Wall *right_wall, Ceiling *ceiling, Floor *floor, Game *game);

Brick *find_brick(Ball *ball, Brick bricks[], int num_bricks);
void reset_ball (Ball *ball, Paddle *paddle);
void move_paddle (Paddle *paddle, int direction);
void move_ball (Ball *ball);
void check_broken (Brick *brick, Game *game);
# 2 "bbreak.c" 2
# 1 "./../stg4/render.h" 1
# 1 "./../stg4/../stg3/model.h" 1
# 4 "./../stg4/render.h" 2
# 1 "./../stg4/types.h" 1
# 5 "./../stg4/render.h" 2
# 1 "C:/c68/include/stdlib.h" 1
# 18 "C:/c68/include/stdlib.h"
typedef unsigned long  size_t;




typedef char  wchar_t;
# 44 "C:/c68/include/stdlib.h"
typedef struct {
    int		quot;
    int		rem;
} div_t;

typedef struct {
    long	quot;
    long	rem;
} ldiv_t;

 double atof (const char *s) ;
 int atoi (const char *str) ;
 long atol (const char *str) ;
 long int strtol (const char *nptr, char **endptr, int base) ;
 unsigned long int strtoul (const char *nptr, char **endptr, int base) ;
 double strtod (const char *s, char **endptr) ;

 void srand (unsigned int seed) ;
 int rand (void) ;

 void *malloc (size_t n) ;
 void free (void *param) ;
 void *realloc (void *_r, size_t n) ;
 void *calloc (size_t n, size_t sz) ;





 void *alloca (size_t) ;
# 89 "C:/c68/include/stdlib.h"
 void  abort (void) ;


 int atexit (void (*)(void)) ;

 void  exit (int) ;

 char *getenv (const char *tag) ;
 int system (const char *s) ;

 void *bsearch (const void *key, const void *base, size_t num, size_t size, int (*cmp )(const void *, const void *)) ;
 void qsort (void *base, size_t total_elems, size_t size, int (*cmp )(const void *, const void *)) ;

 int abs (int x) ;
 long labs (long x) ;

 div_t div (int num, int denom) ;
 ldiv_t ldiv (long num, long denom) ;

 int mblen (const char *, size_t) ;
 size_t mbstowcs (wchar_t *, const char *, size_t) ;
 int mbtowc (wchar_t *, const char *, size_t) ;
 size_t wcstombs (char *, const wchar_t *, size_t) ;
 int wctomb (char *, wchar_t) ;

 wchar_t *wcscat (wchar_t *, const wchar_t *) ;
 int wcscmp (const wchar_t *, const wchar_t *) ;
 wchar_t *wcscpy (wchar_t *, const wchar_t *) ;
 size_t wcslen (const wchar_t *) ;
 wchar_t *wcsncat (wchar_t *, const wchar_t *, size_t) ;
 int wcsncmp (const wchar_t *, const wchar_t *, size_t) ;
 wchar_t *wcsncpy (wchar_t *, const wchar_t *, size_t) ;
# 6 "./../stg4/render.h" 2
# 1 "C:/c68/include/stdio.h" 1
# 69 "C:/c68/include/stdio.h"
typedef	struct
	{
	long		_cnt;
	unsigned char	*_ptr;
	unsigned char	*_base;
	unsigned int	_flag;
	int		_file;
	long		_bsiz;
	unsigned char	_ch;
	}
	FILE;


typedef unsigned long fpos_t;
# 92 "C:/c68/include/stdio.h"
extern	FILE	_iob[];
# 108 "C:/c68/include/stdio.h"
 char *	ctermid	(char *) ;




 int	remove	(const char *) ;
 int	rename	(const char *, const char *) ;
 char *	tmpnam	(char *) ;
 FILE *	tmpfile	(void) ;

 int	fclose	(FILE *) ;
 int	fflush	(FILE *) ;

 FILE *	fopen	(const char *, const char *) ;
 FILE *	freopen	(const char *, const char *, FILE *) ;

 void	setbuf	(FILE *, char *) ;
 int	setvbuf	(FILE *, char *, int, size_t) ;
# 132 "C:/c68/include/stdio.h"
 int  fscanf  (FILE *, const char *, ...) ;
 int  scanf   (const char *, ...) ;
 int  sscanf  (const char *, const char *, ...) ;


 int	fprintf	(FILE *, const char *, ...) ;
 int	printf	(const char *, ...) ;
 int	sprintf	(char *, const char *, ...) ;

 int 	vfprintf (FILE *, const char *, char * ) ;
 int 	vprintf	 (const char *, char * ) ;
 int 	vsprintf (char *, const char *, char * ) ;

 int	vscanf  (const char *, char * ) ;
 int	vfscanf (FILE *, const char *, char * ) ;
 int	vsscanf	(const char *, const char *, char * ) ;


 int	fgetc	(FILE *) ;
 char	*fgets	(char *, int, FILE *) ;
 char	*gets	(char *) ;
 int	fputc	(int c, FILE *) ;
 int	fputs	(const char *, FILE *) ;
 int	puts	(const char *) ;

 size_t	fread	(void *, size_t, size_t, FILE *) ;
 size_t	fwrite	(const void *, size_t, size_t, FILE *) ;

 int	fgetpos	(FILE *, fpos_t *) ;
 int	fsetpos	(FILE *, fpos_t *) ;

 int	fseek	(FILE *, long, int) ;
 long	ftell	(FILE *) ;
 void	rewind	(FILE *) ;

 void	perror	(const char *) ;


 FILE	*fdopen	(int, const char *) ;


 FILE *	fopenp	(const char *, const char *) ;
 int 	fungetc	(int, FILE *) ;
 int	pclose	(FILE *) ;
 FILE *	popen	(const char *, const char *) ;
 void	setlinebuf	(FILE *) ;

 void	_binmode	(int) ;
 long 	getl	(FILE *) ;
 long 	putl	(long, FILE *) ;
 short 	getw	(FILE *) ;
 short 	putw	(short, FILE *) ;
 void	_getbuf	(FILE *fp) ;
# 192 "C:/c68/include/stdio.h"
 int	_filbuf	(FILE *) ;
# 7 "./../stg4/render.h" 2




void render(Model *model, UINT8 *base);
void render_ball(Ball *ball, UINT8 *base);
void render_brick(Brick *brick, UINT8 *base);
void render_heart(Heart *heart, UINT8 *base);
void render_paddle(Paddle *paddle, UINT8 *base);
void render_walls(UINT8 *base);
void render_singlebrick(Brick *brick, UINT8 *base);
void render_clear_paddle(Paddle *paddle, UINT8 *base);
# 3 "bbreak.c" 2
# 1 "./../stg4/bitmap.h" 1
# 4 "bbreak.c" 2
# 1 "C:/c68/include/TYPES.H" 1
# 19 "C:/c68/include/TYPES.H"
typedef long  time_t;


typedef unsigned short	dev_t;
typedef unsigned short 		gid_t;
typedef unsigned long	ino_t;
typedef unsigned short	mode_t;
typedef short		nlink_t;
typedef long		off_t;
typedef int 		pid_t;
typedef unsigned short 		uid_t;


typedef unsigned char	u_char;
typedef unsigned short	u_short;
typedef unsigned int 	u_int;
typedef unsigned long	u_long;
typedef void *		caddr_t;
# 43 "C:/c68/include/TYPES.H"
typedef unsigned long  fd_set;
# 52 "C:/c68/include/TYPES.H"
 int truncate	(const char *_filename, off_t length) ;
 int ftruncate	(int fd, off_t length) ;
# 1 "C:/c68/include/utime.h" 1
# 8 "C:/c68/include/utime.h"
struct utimbuf {
	time_t	actime;
	time_t	modtime;
};

 int utime (const char *path, const struct utimbuf *times) ;
# 55 "C:/c68/include/TYPES.H" 2
# 5 "bbreak.c" 2
# 1 "./bbreak.h" 1
# 1 "C:/c68/include/TYPES.H" 1
# 4 "./bbreak.h" 2
# 1 "./../stg3/model.h" 1
# 5 "./bbreak.h" 2
# 1 "./../stg4/render.h" 1
# 6 "./bbreak.h" 2
# 1 "C:/c68/include/stdlib.h" 1
# 7 "./bbreak.h" 2
# 1 "C:/c68/include/stdio.h" 1
# 8 "./bbreak.h" 2


void initialize_game(Game *game, Model *game_model, Wall *left_wall, Wall *right_wall, Ceiling *ceiling, Floor *floor);
void initialize_bricks(Brick *bricks[], int num_bricks);
void process_input(Paddle *paddle, Ball *ball);
# 19 "./bbreak.h"
void render_clear_paddle(Paddle *paddle, UINT8 *base);
# 6 "bbreak.c" 2
# 1 "C:/c68/include/stdio.h" 1
# 7 "bbreak.c" 2
# 1 "C:/c68/include/linea.h" 1
# 325 "C:/c68/include/linea.h"
typedef struct {



   short  _VPLANES;
   short  _VWRAP;




   short  *_CONTRL;
   short  *_INTIN;
   short  *_PTSIN;
   short  *_INTOUT;
   short  *_PTSOUT;
# 349 "C:/c68/include/linea.h"
   short  _COLBIT0;
   short  _COLBIT1;
   short  _COLBIT2;
   short  _COLBIT3;




   short  _LSTLIN;



   short  _LNMASK;



   short  _WMODE;
# 372 "C:/c68/include/linea.h"
   short  _X1;

   short  _Y1;

   short  _X2;

   short  _Y2;


   short  *_PATPTR;

   short  _PATMSK;

   short  _MFILL;



   short  _CLIP;
   short  _XMINCL;
   short  _YMINCL;
   short  _XMAXCL;
   short  _YMAXCL;


   short  _XDDA;


   short  _DDAINC;



   short  _SCALDIR;
   short  _MONO;





   short  _SOURCEX;
# 417 "C:/c68/include/linea.h"
   short  _SOURCEY;

   short  _DESTX;
   short  _DESTY;
   short  _DELX;

   short  _DELY;

   short  *_FBASE;
   short  _FWIDTH;

   short  _STYLE;
# 435 "C:/c68/include/linea.h"
   short  _LITEMASK;

   short  _SKEWMASK;

   short  _WEIGHT;

   short  _ROFF;


   short  _LOFF;


   short  _SCALE;

   short  _CHUP;




   short  _TEXTFG;

   char  *_SCRTCHP;




   short  _SCRPT2;



   short  _TEXTBG;


   short  _COPYTRAN;
# 476 "C:/c68/include/linea.h"
 short(*_SEEDABORT) (void) ;
# 484 "C:/c68/include/linea.h"
} __LINEA;
# 546 "C:/c68/include/linea.h"
typedef struct _font {



   short  font_id;

   short  size;

   char   name[32];

   short  first_ade;


   short  last_ade;


   short  top;

   short  ascent;

   short  half;

   short  descent;

   short  bottom;



short max_char_width;

short max_cell_width;

  short left_offset;

  short right_offset;

   short  thicken;

   short  ul_size;

   short  lighten;

   short  skew;



   short  flags;





   char   *h_table;

   short  *off_table;

   char   *dat_table;

   short  form_width;

   short  form_height;

 struct _font *next_font;


} __FONT;
# 620 "C:/c68/include/linea.h"
typedef short(*FPTR) (void) ;
typedef FPTR *FUNCPTR;
# 628 "C:/c68/include/linea.h"
typedef struct {



   char   fg0bg0;
   char   fg0bg1;
   char   fg1bg0;
   char   fg1bg1;

} OP_TAB;





typedef struct  {
	short	bl_xmin;
	short	bl_ymin;
	char	*bl_form;
	short	bl_nxwd;
	short 	bl_nxln;
	short 	bl_nxpl;
}SDDB;
# 673 "C:/c68/include/linea.h"
typedef struct {



   short   bb_b_wd;
   short   bb_b_ht;
   short   bb_plane_ct;
   short   bb_fg_col;
   short   bb_bg_col;
   OP_TAB  bb_op_tab;
   SDDB	   bb_s;
   SDDB	   bb_d;
   short   *bb_p_addr;
   short   bb_p_nxln;
   short   bb_p_nxpl;
   short   bb_p_mask;
   char	   bb_fill[24];

} BBPB;
# 700 "C:/c68/include/linea.h"
typedef struct
{
	char		*fd_addr;


	short		fd_w;
	short		fd_h;
	short		fd_wdwidth;
	short		fd_stand;
	short		fd_nplanes;
	short		fd_r1;
	short		fd_r2;
	short		fd_r3;
} MFDB;
# 720 "C:/c68/include/linea.h"
typedef struct
{
	short	sp_xhot;
	short	sp_yhot;
	short	sp_format;
	short	sp_bg;
	short	sp_fg;
	short	sp_data[32];





} SFORM;
# 750 "C:/c68/include/linea.h"
extern __LINEA *__aline;



extern __FONT  **__fonts;



extern short  (**__funcs) (void) ;
# 1013 "C:/c68/include/linea.h"
 void linea0 (void) ;
 void linea1 (void) ;
 int linea2 (void) ;
 void linea3 (void) ;
 void linea4 (void) ;
 void linea5 (void) ;
 void linea6 (void) ;
 void linea7 (BBPB *P) ;
 void linea8 (void) ;
 void linea9 (void) ;
 void lineaa (void) ;
 void lineab (void) ;
 void lineac (void *P) ;
 void linead (int x, int y, SFORM *sd, void *ss) ;
 void lineae (void) ;
 void lineaf (void) ;
# 8 "bbreak.c" 2
# 14 "bbreak.c"
void initialize_game(Game *game, Model *game_model, Wall *left_wall, Wall *right_wall, Ceiling *ceiling, Floor *floor) {

  game->score = 0;
  game->lives = 3;
  game->level = 1;
  game->game_over = 0;
  game->paused = 0;


  game_model->ball.x = 640  / 2;
  game_model->ball.y = 342;
  game_model->ball.delta_x = 1;
  game_model->ball.delta_y = 1;
  game_model->ball.isActive = 0;
  game_model->ball.size_x = 8;
  game_model->ball.size_y = 8;
  game_model->ball.ball_bitmap = ball_bitmap;



  game_model->paddle.x = 250;
  game_model->paddle.y = 350;
  game_model->paddle.size_x = 32;
  game_model->paddle.size_y = 5;
  game_model->paddle.p_input = 0;
  game_model->paddle.move_dist = 20;
  game_model->paddle.paddle_bitmap = paddle_bitmap;

  game_model->heart.x = 170;
  game_model->heart.y = 45;
  game_model->heart.heart_map = heart_map;


  left_wall->x = 160;
  right_wall->x = 480;


  ceiling->y = 0;
  floor->y = 400 ;
}
# 85 "bbreak.c"
void process_input(Paddle *paddle, Ball *ball) {
    if ((short)_trap_1_w((short)0x0B) ) {
        char ch = (char)_trap_1_w((short)0x08) ;

        if (ch == 'a') {
            move_paddle(paddle, 0);
        } else if (ch == 'd') {
            move_paddle(paddle, 1);
        } else if (ch == ' ') {
            start_ball(ball);
        }
    }
}
# 114 "bbreak.c"
UINT32 get_time() {
    long old_ssp;
    UINT32 timeNow;

    old_ssp = _trap_1_wl((short)0x20,(long)(0)) ;
    timeNow = *(UINT32 *)0x462;
    _trap_1_wl((short)0x20,(long)(old_ssp)) ;

    return timeNow;
}

int main() {

  Model game_model;
  Game game;
  Wall left_wall;
  Wall right_wall;
  Ceiling ceiling;
  Floor floor;
  Paddle paddle;
  Ball ball;
  Brick bricks[27];


  UINT8 *base = (void*)_trap_14_w((short)0x2) ;

  initialize_game(&game, &game_model, &left_wall, &right_wall, &ceiling, &floor);



  render(&game_model, base);
# 163 "bbreak.c"
}
