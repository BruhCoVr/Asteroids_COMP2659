all: tst_mus

tst_mus: music.o psg.o music_test.o
	cc68x -g music.o psg.o music_test.o -lm -o music_test.prg

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

psg.o:  psg.c psg.h
	cc68x -g -c psg.c

music_test.o: music_test.c music.h psg.h
	cc68x -g -c music_test.c

model.o: model.c model.h
	cc68x -g -c model.c

events.o: events.c events.h
	cc68x -g -c events.c -lm 

raster.o: raster.c raster.h
	cc68x -g -c raster.c

bitmaps.o: bitmaps.c bitmaps.h
	cc68x -g -c bitmaps.c

clean:
	$(RM) *.o
	$(RM) *.prg
