tst_mod: model.o bitmaps.o events.o tst_mod.o 
	cc68x -g tst_mod.o bitmaps.o model.o events.o -lm -o tst_mod.prg

tst_rast: raster.o bitmaps.o tst_rast.o 
	cc68x -g tst_rast.o bitmaps.o raster.o -o tst_rast.prg

tst_mod.o: tst_mod.c model.h bitmaps.h
	cc68x -g -c tst_mod.c
	
tst_rast.o: tst_rast.c raster.h bitmaps.h
	cc68x -g -c tst_rast.c

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
