hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/Dugum.o -c ./src/Dugum.cpp
	g++ -I ./include/ -o ./lib/IkiliAramaAgaci.o -c ./src/IkiliAramaAgaci.cpp
	g++ -I ./include/ -o ./lib/Dosya.o -c ./src/Dosya.cpp
	g++ -I ./include/ -o ./bin/test ./lib/Dugum.o ./lib/IkiliAramaAgaci.o ./lib/Dosya.o ./src/test.cpp
	
	
calistir:
	./bin/test
	