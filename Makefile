pro.exe: barca.o bintree.o cjt_barcas.o estacion.o main.o rio.o
	g++ -o pro.exe barca.o bintree.o cjt_barcas.o estacion.o main.o rio.o

bintree.o: bintree.hh
	g++ -c bintree.hh

barca.o: Barca.cc Barca.hh
	g++ -c Barca.cc

cjt_barcas.o: Cjt_barcas.cc Cjt_barcas.hh
	g++ -c Cjt_barcas.cc

estacion.o: Estacion.cc Estacion.hh
	g++ -c Estacion.cc

main.o: main.cc
	g++ -c main.cc

rio.o: Rio.cc Rio.hh
	g++ -c Rio.cc

clean:
	rm -f pro.exe *.o

tar:
	tar -cvf projecte.tar *

.PHONY: clean tar