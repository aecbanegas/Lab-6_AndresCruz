Main.out: Main.o Motor.o Chasis.o Pintura.o Carro.o
	g++ Main.o Motor.o Chasis.o Pintura.o Carro.o -o Main.out
Main.o: Main.cpp Carro.h Chasis.h Motor.h Pintura.h
	g++ -c Main.cpp
Motor.o: Motor.cpp Motor.h
	g++ -c Motor.cpp
Chasis.o: Chasis.cpp Chasis.h
	g++ -c Chasis.cpp
Pintura.o: Pintura.cpp Pintura.h
	g++ -c Pintura.cpp
Carro.o: Carro.cpp Carro.h Motor.h Motor.cpp Chasis.h Chasis.cpp Pintura.h Pintura.cpp
	g++ -c Carro.cpp