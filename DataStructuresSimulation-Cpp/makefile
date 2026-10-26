hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/Dugum.o -c ./src/Dugum.cpp
	g++ -I ./include/ -o ./lib/Agac.o -c ./src/Agac.cpp
	g++ -I ./include/ -o ./lib/Kuyruk.o -c ./src/Kuyruk.cpp
	g++ -I ./include/ -o ./lib/Hucre.o -c ./src/Hucre.cpp
	g++ -I ./include/ -o ./lib/Yonetici.o -c ./src/Yonetici.cpp
	g++ -I ./include/ -o ./bin/main ./lib/Dugum.o ./lib/Agac.o ./lib/Kuyruk.o ./lib/Hucre.o ./lib/Yonetici.o ./src/main.cpp

calistir:
	./bin/main