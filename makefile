all: tst_eff tst_mus

tst_mus: music.o psg.o tst_mus.o 
	cc68x -g music.o psg.o tst_mus.o -lm -o tst_mus.prg 

tst_eff: effects.o psg.o tst_eff.o
	cc68x -g effects.o psg.o tst_eff.o -lm -o tst_eff.prg 

main: renderer.o game.o bitmaps.o raster.o events.o model.o input.o time.o  effects.o psg.o effects.o music.o
	cc68x -g renderer.o game.o bitmaps.o raster.o events.o model.o input.o time.o effects.o music.o psg.o -lm -o main.prg

tst_mod: model.o bitmaps.o events.o tst_mod.o 
	cc68x -g tst_mod.o bitmaps.o model.o events.o -lm -o tst_mod.prg

tst_rast: raster.o bitmaps.o tst_rast.o 
	cc68x -g tst_rast.o bitmaps.o raster.o -o tst_rast.prg

tst_rend: tst_rend.o model.o events.o raster.o bitmaps.o renderer.o 
	cc68x -g tst_rend.o model.o events.o raster.o bitmaps.o renderer.o -lm -o tst_rend.prg

tst_rend.o: tst_rend.c renderer.h model.h events.h raster.h bitmaps.h
	cc68x -g -c tst_rend.c

renderer.o: renderer.c renderer.h model.h events.h raster.h bitmaps.h 
	cc68x -g -c renderer.c

tst_mod.o: tst_mod.c model.h bitmaps.h
	cc68x -g -c tst_mod.c
	
tst_rast.o: tst_rast.c raster.h bitmaps.h
	cc68x -g -c tst_rast.c

music.o:  music.c music.h 
	cc68x -g -c music.c

effects.o:  effects.c effects.h
	cc68x -g -c effects.c

psg.o:  psg.c psg.h
	cc68x -g -c psg.c

tst_mus.o: tst_mus.c music.h psg.h
	cc68x -g -c tst_mus.c

tst_eff.o: tst_eff.c effects.h psg.h
	cc68x -g -c tst_eff.c

model.o: model.c model.h
	cc68x -g -c model.c

events.o: events.c events.h
	cc68x -g -c events.c -lm 

time.o: time.c time.h
	cc68x -g -c time.c -lm 

raster.o: raster.c raster.h
	cc68x -g -c raster.c

bitmaps.o: bitmaps.c bitmaps.h
	cc68x -g -c bitmaps.c

game.o: game.c game.h
	cc68x -g -c game.c

input.o: input.c input.h
	cc68x -g -c input.c



clean:
	$(RM) *.o
	$(RM) *.prg
