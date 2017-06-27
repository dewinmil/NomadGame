CC=g++

LINKS=-lsfml-graphics -lsfml-window -lsfml-system -lX11

Nomad: Main.o Button.o Menu.o
	$(CC) Button.o Menu.o Main.o -o Nomad $(LINKS)

Button.o: Button.cpp Button.h
	$(CC) -c Button.cpp

Menu.o: Menu.cpp Menu.h
	$(CC) -c Menu.cpp

Main.o: Main.cpp Button.h Menu.h
	$(CC) -c Main.cpp

clean:
	rm *.o
