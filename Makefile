pro.exe: Barca.o Cjt_barcas.o Estacion.o main.o Rio.o
	g++ -o pro.exe Barca.o Cjt_barcas.o Estacion.o main.o Rio.o

Barca.o: Barca.cc Barca.hh
	g++ -c Barca.cc

Cjt_barcas.o: Cjt_barcas.cc Cjt_barcas.hh Barca.hh
	g++ -c Cjt_barcas.cc

Estacion.o: Estacion.cc Estacion.hh
	g++ -c Estacion.cc

main.o: main.cc
	g++ -c main.cc

Rio.o: Rio.cc Rio.hh Estacion.hh
	g++ -c Rio.cc

clean:
	rm -f pro.exe *.o *.out

tar:
	tar -cvf projecte.tar *

.PHONY: clean tar