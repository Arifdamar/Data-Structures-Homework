hepsi: derle calistir
derle:
	g++ -I ./include/ -o ./lib/Kova.o -c ./src/Kova.cpp
	g++ -I ./include/ -o ./lib/Top.o -c ./src/Top.cpp
	g++ -I ./include/ -o ./lib/KovaKontrol.o -c ./src/KovaKontrol.cpp
	g++ -I ./include/ -o ./bin/Test ./lib/Kova.o ./lib/Top.o ./lib/KovaKontrol.o ./src/Test.cpp
calistir:
	./bin/Test