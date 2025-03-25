# 1 "game.c" 1
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
# 1 "game.c" 2
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
# 2 "game.c" 2
# 1 "C:/c68/include/string.h" 1
# 25 "C:/c68/include/string.h"
 void *memcpy (void *dst, const void *src, size_t size) ;
 void *memmove (void *dst, const void *src, size_t size) ;
 int memcmp (const void *s1, const void *s2, size_t size) ;
 void *memchr (const void *s, int ucharwanted, size_t size) ;
 void *memset (void *s, int ucharfill, size_t size) ;

 char *strcpy (char *dst, const char *src) ;
 char *strncpy (char *dst, const char *src, size_t n) ;
 char *strcat (char *dst, const char *src) ;
 char *strncat (char *dst, const char *src, size_t n) ;
 int strcmp (const char *scan1, const char *scan2) ;
 int strncmp (const char *scan1, const char *scan2, size_t n) ;
 int strcoll (const char *scan1, const char *scan2) ;
 size_t	strxfrm (char *to, const char *from, size_t maxsize) ;
 char *strchr (const char *s, int charwanted) ;
 size_t strcspn (const char *s, const char *reject) ;
 char *strpbrk (const char *s, const char *breakat) ;
 char *strrchr (const char *s, int charwanted) ;
 size_t strspn (const char *s, const char *accept) ;
 char *strstr (const char *s, const char *wanted) ;
 char *strtok (char *s, const char *delim) ;
 size_t strlen (const char *scan) ;
 char *strerror (int errnum) ;
# 54 "C:/c68/include/string.h"
 void *memccpy (void *dst, const void *src, int ucharstop, size_t size) ;
 char *strlwr (char *string) ;
 char *strupr (char *string) ;



 char *strrev (char *string) ;
 char *strdup (const char *s) ;




 char *index (const char *s, int charwanted) ;
 char *rindex (const char *s, int charwanted) ;
 void bcopy (const void *src, void *dst, size_t length) ;
 int bcmp (const void *src, const void *dst, size_t n) ;
 void bzero (void *b, size_t n) ;

 void _bcopy (const void *src, void *dst, unsigned long length) ;
 int  _bcmp (const void *s1, const void *s2, unsigned long length) ;
 void _bzero (void *dst, unsigned long length) ;

 int stricmp ( const char *, const char * ) ;
 int strnicmp ( const char *, const char *, size_t ) ;
 int strcmpi ( const char *, const char * ) ;
 int strncmpi ( const char *, const char *, size_t ) ;
# 3 "game.c" 2
# 1 "C:/c68/include/time.h" 1
# 26 "C:/c68/include/time.h"
typedef long 		time_t;
# 34 "C:/c68/include/time.h"
typedef unsigned long	clock_t;

struct tm
{
	int	tm_sec;
	int	tm_min;
	int	tm_hour;
	int	tm_mday;
	int	tm_mon;
	int	tm_year;
	int	tm_wday;
	int	tm_yday;
	int	tm_isdst;
};



struct timeval {
	long	tv_sec;
	long	tv_usec;
};

struct timezone {
	int	tz_minuteswest;
	int	tz_dsttime;
};


 clock_t	clock	 (void) ;
 double		difftime (time_t, time_t) ;
 time_t		mktime	 (const struct tm *) ;
 time_t		time	 (time_t *) ;
 char * 	asctime	 (const struct tm *) ;
 char *		ctime	 (const time_t *) ;
 struct tm *	gmtime   (const time_t *) ;
 struct tm *	localtime (const time_t *) ;
 unsigned long  strftime (	char *s, size_t maxsize, const char *format, const struct tm *timeptr) ;



 void		tzset	(void) ;


 clock_t	_clock	 (void) ;
 int	gettimeofday (struct timeval *, struct timezone *) ;
 int	settimeofday (struct timeval *, struct timezone *) ;



typedef unsigned long  fd_set;


 int	select	(int, fd_set *, fd_set *, fd_set *,					struct timeval *) ;
# 4 "game.c" 2
# 1 "./game.h" 1
# 1 "C:/c68/include/osbind.h" 1
# 4 "./game.h" 2
# 1 "C:/c68/include/stdlib.h" 1
# 5 "./game.h" 2
# 1 "./model.h" 1
# 8 "./model.h"
typedef enum {
    ASTEROID_SMALL = 1,
    ASTEROID_MEDIUM = 2,
    ASTEROID_LARGE = 3
} AsteroidSize;


typedef struct {
    int x;
    int y;
} Position;


typedef struct {
    Position pos;
    int angle;
} Ship;


typedef struct {
    Position pos;
    int dx;
    int dy;
    int lifetime;
    int active;
} Missile;


typedef struct {
    Position pos;
    int dx;
    int dy;
    AsteroidSize size;
    int active;
} Asteroid;


typedef struct {
    int score;
    int lives;
} Scoreboard;


typedef struct {
    Ship ship;
    Missile missiles[10 ];
    Asteroid asteroids[20 ];
    Scoreboard scoreboard;
    int quit;
} Model;


void initModel(Model *model);


void moveShipForward(Ship *ship);
void rotateShip(Ship *ship, int angle_delta);


void initMissile(Missile *missile, Position pos, int dx, int dy, int lifetime);
void updateMissile(Missile *missile);


void initAsteroid(Asteroid *asteroid, Position pos, int dx, int dy, AsteroidSize size);
void updateAsteroid(Asteroid *asteroid);


void updateScore(Scoreboard *scoreboard, int points);
void loseLife(Scoreboard *scoreboard);
void awardBonusLife(Scoreboard *scoreboard);


void wrapPosition(Position *pos, int screen_width, int screen_height);
# 6 "./game.h" 2
# 1 "./renderer.h" 1
# 1 "./model.h" 1
# 4 "./renderer.h" 2
# 1 "./types.h" 1




typedef unsigned char UINT8;


typedef unsigned int UINT16;


typedef unsigned long UINT32;


typedef enum {
    num_0 = 0,
    num_1,
    num_2,
    num_3,
    num_4,
    num_5,
    num_6,
    num_7,
    num_8,
    num_9,
    totalNumbers
} numberEnum;
# 5 "./renderer.h" 2
# 1 "./bitmaps.h" 1
# 1 "./types.h" 1
# 4 "./bitmaps.h" 2



extern const UINT32 shipUpBitmap[];


extern const UINT32 shipDownBitmap[32];


extern const UINT32 shipLeftBitmap[32];


extern const UINT32 shipRightBitmap[32];


extern const UINT32 shipDiagDownLeftBitmap[32];


extern const UINT32 shipDiagDownRightBitmap[32];


extern const UINT32 shipDiagUpLeftBitmap[32];


extern const UINT32 shipDiagUpRightBitmap[32];


extern const UINT32 largeAsteroidBitmap[4][32];


extern const UINT32 mediumAsteroidBitmap[4][32];


extern const UINT32 smallAsteroidBitmap[4][32];


extern const UINT8 bullet[8];


extern const UINT32 startBitmap[16][32];


extern const UINT16 numberSprites[totalNumbers][16];
# 6 "./renderer.h" 2
# 13 "./renderer.h"
void render(const Model *model, UINT32 *base);


void renderShip(const Ship *ship, UINT32 *base);


void renderMissile(const Missile *missile, UINT32 *base);


void renderAsteroid(const Asteroid *asteroid, UINT32 *base);


void renderScoreboard(const Scoreboard *scoreboard, UINT32 *base);
# 7 "./game.h" 2
# 1 "./input.h" 1
# 1 "./model.h" 1
# 4 "./input.h" 2



int InputPending();


char ReadInput();
# 8 "./game.h" 2
# 1 "./raster.h" 1
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
# 3 "./raster.h" 2
# 1 "./types.h" 1
# 4 "./raster.h" 2
# 15 "./raster.h"
void plotBitmap8 (UINT8 *base, int x, int y, const UINT8 *bitmap, unsigned int height);
# 26 "./raster.h"
void plotBitmap16 (UINT16 *base, int x, int y, const UINT16 *bitmap, unsigned int height);
# 37 "./raster.h"
void plotBitmap32(UINT32 *base, int x, int y, const UINT32 *bitmap, unsigned int height);
# 46 "./raster.h"
void plotPixel (UINT8 *base, int x, int y);
# 53 "./raster.h"
void clearSc (UINT32* base);
# 60 "./raster.h"
void blackSc(UINT32* base);
# 70 "./raster.h"
void plotVline(UINT8 *base, int x, int y1, int y2);
# 80 "./raster.h"
void plotHline(UINT8 *base, int y, int x1, int x2);
# 92 "./raster.h"
void plotBitmap(UINT32 *base, int x, int y, const UINT32 *bitmap, unsigned int width, unsigned int height);
# 99 "./raster.h"
void plotStars(void *base);
# 9 "./game.h" 2
# 19 "./game.h"
void InitializegGame(Model *model);

UINT32 GetTime();


void RunGame();


void swapBuffers(void **active, void **inactive);
# 5 "game.c" 2
# 1 "./music.h" 1
# 1 "./types.h" 1
# 3 "./music.h" 2


void start_music();

void update_Mainmusic(UINT32 time_elapsed);

void start_Deathmusic();

void update_Deathmusic(UINT32 time_elapsed);
# 6 "game.c" 2
# 1 "./model.h" 1
# 7 "game.c" 2
# 1 "./time.h" 1
# 1 "./types.h" 1
# 3 "./time.h" 2


UINT32 getTime();
# 8 "game.c" 2
# 1 "./psg.h" 1
# 1 "./types.h" 1
# 3 "./psg.h" 2


typedef enum{
    A_CHANNEL = 0,
    B_CHANNEL,
    C_CHANNEL,
} Channel;

typedef enum{
    C = 0,
    C_SHARP,
    D,
    D_SHARP,
    E,
    F,
    F_SHARP,
    G,
    G_SHARP,
    A,
    A_SHARP,
    B,
    NUM_TONES
} Note;

typedef enum{
    OCTAVE_3 = 0,
    OCTAVE_4,
    OCTAVE_5,
    NUM_OCTAVES
} Octave;

typedef struct {
	Note note;
	Octave octave;
	unsigned long holdTime;
}PlayableNote;

extern const UINT16 noteTunings[NUM_TONES][NUM_OCTAVES];

void write_psg(int reg, int val);

void enable_channel(int channel, int tone_on, int noise_on);

void stop_sound();

void set_volume(int channel, int volume);

void set_tone(int channel, int tuning);

void set_noise(int tuning);

void set_envelope(int shape, unsigned int sustain);
# 9 "game.c" 2
# 1 "./types.h" 1
# 10 "game.c" 2
# 1 "./renderer.h" 1
# 11 "game.c" 2
# 1 "./input.h" 1
# 12 "game.c" 2
# 1 "./raster.h" 1
# 13 "game.c" 2
# 1 "./events.h" 1
# 1 "./model.h" 1
# 4 "./events.h" 2
# 11 "./events.h"
void handleMoveForward(Model *model);
void handleIncreaseAngle(Model *model);
void handleDecreaseAngle(Model *model);
void handleShootMissile(Model *model);
void handleQuit(Model *model);



void updateAsteroids(Model *model);
void updateMissiles(Model *model);
void respawnShip(Model *model);



void handleAsteroidSplit(Model *model, int asteroid_index);
void handleAsteroidDestroyed(Model *model, int asteroid_index);
void handleShipDestroyed(Model *model);
void handleObjectWraparound(Model *model, int object_type, int index);
void handleGameOver(Model *model);
void handleMissileCollision(Model *model, int missile_index, int asteroid_index);
void handleBonusLifeAwarded(Model *model);
void handleDifficultyRampUp(Model *model);
# 14 "game.c" 2


UINT32 GetTime() {
    long old_ssp;
    UINT32 timeNow;
    old_ssp = _trap_1_wl((short)0x20,(long)(0)) ;
    timeNow = *(UINT32 *)0x462;
    _trap_1_wl((short)0x20,(long)(old_ssp)) ;
    return timeNow;
}

UINT32 start_time, current_time;

void InitializegGame(Model *model) {



    Position asteroid_pos1 = {100, 100};
    Position asteroid_pos2 = {500, 300};

    initModel(model);
    initAsteroid(&model->asteroids[0], asteroid_pos1, 1, 1, ASTEROID_LARGE);
    initAsteroid(&model->asteroids[1], asteroid_pos2, -1, 1, ASTEROID_MEDIUM);
}


void RunGame() {
    Model model;
    UINT32 timeThen, timeNow, timeElapsed;
    UINT32 *frameBuffer = (void*)_trap_14_w((short)0x2) ;

    UINT32 *backBuffer = (UINT32 *)malloc(8000 * sizeof(UINT32));
    if (!backBuffer) {
        exit(1);
    }


    start_music();
    start_time = getTime();


    InitializegGame(&model);
    timeThen = GetTime();

    while (!model.quit) {


        current_time = getTime();
        update_Mainmusic(current_time - start_time);

        timeNow = GetTime();
        timeElapsed = timeNow - timeThen;


        if (InputPending()) {
            char input = ReadInput();
            switch (input) {
                case 'w':
                case 'W':
                    handleMoveForward(&model);
                    break;
                case 'a':
                case 'A':
                    handleIncreaseAngle(&model);
                    break;
                case 'd':
                case 'D':
                    handleDecreaseAngle(&model);
                    break;
                case 's':
                case 'S':
                    handleShootMissile(&model);
                    break;
                case 'q':
                case 'Q':
                    handleQuit(&model);
                    break;
                default: break;
            }
        }



        timeNow = GetTime();
        timeElapsed = timeNow - timeThen;


        updateAsteroids(&model);
        updateMissile(&model);


        render(&model, backBuffer);


        (void)_trap_14_w((short)0x25) ;

        memcpy(frameBuffer, backBuffer, 8000 * sizeof(UINT32));

        timeThen = timeNow;
    }

    free(backBuffer);

    stop_sound();
}

void main() {

    srand((unsigned) time(((void *)0) ));

    printf("\033E\033F\n");
    RunGame();
}
