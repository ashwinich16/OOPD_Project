# Makefile for compiling the program

# Default target
all: my_program

my_program: wifi4.o wifi5.o wifi6.o main.o
	g++ -g -o output wifi4.o wifi5.o wifi6.o main.o
	g++ -O3 -o optimize wifi4.o wifi5.o wifi6.o main.o

# Object file targets for WiFi 4
wifi4.o: WiFi4.cpp Wifi4.h Commons.h
	g++ -c WiFi4.cpp

# Object file targets for WiFi 5
wifi5.o: WiFi5.cpp Wifi5.h Commons.h
	g++ -c WiFi5.cpp

# Object file targets for WiFi 6
wifi6.o: WiFi6.cpp Wifi6.h Commons.h
	g++ -c WiFi6.cpp


# Object file target for Main program
main.o: main.cpp Wifi4.h Wifi5.h Wifi6.h Commons.h
	g++ -c main.cpp

# Clean target to remove object files and executables
clean:
	rm -f *.o output optimize
