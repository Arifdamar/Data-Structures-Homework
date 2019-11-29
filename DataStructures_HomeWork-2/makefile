hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/Dugum.o -c ./src/Dugum.cpp
	g++ -I ./include/ -o ./lib/Iterator.o -c ./src/Iterator.cpp
	g++ -I ./include/ -o ./lib/DoublyLinkedList.o -c ./src/DoublyLinkedList.cpp
	g++ -I ./include/ -o ./lib/Dosya.o -c ./src/Dosya.cpp
	g++ -I ./include/ -o ./bin/test ./lib/Iterator.o ./lib/Dugum.o ./lib/DoublyLinkedList.o ./lib/Dosya.o ./src/test.cpp
	
calistir:
	./bin/test