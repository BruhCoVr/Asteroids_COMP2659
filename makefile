
tst_rast: raster.o bitmaps.o tst_rast.o 
	cc68x -g tst_rast.o bitmaps.o raster.o -o tst_rast.prg

tst_rast.o: tst_rast.c raster.h bitmaps.h
	cc68x -g -c tst_rast.c

raster.o: raster.c raster.h
	cc68x -g -c raster.c

bitmaps.o: bitmaps.c bitmaps.h
	cc68x -g -c bitmaps.c

clean:
	$(RM) *.o
