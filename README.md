# OOPD_Project
# Description

This project simulates WiFi communication for WiFi 4, WiFi 5, and WiFi 6, focusing on throughput, average latency, and maximum latency under various user and access point configurations. The simulations include CSMA/CA for WiFi 4, MU-MIMO for WiFi 5, and OFDMA for WiFi 6. The program models transmission processes for 1, 10, and 100 users communicating with a single access point (AP).

with Parameters
Bandwidth: 20 MHz
Modulation: 256-QAM
Coding rate: 5/6
Packet size: 1 KB
Random backoff time when the channel is busy.
Users communicate in parallel for 15ms after channel state information exchange.(Wifi5)
Channel subdivided into 2 MHz, 4 MHz, or 10 MHz sub-channels.(Wifi6)
Each sub-channel used for 5ms before reallocation.(Wifi6)
Output: Throughput, average latency, and maximum latency for each user scenario.

# Commands to build
all: my_program

my_program: wifi4.o wifi5.o wifi6.o main.o
g++ -g -o output wifi4.o wifi5.o wifi6.o main.o
	g++ -O3 -o optimize wifi4.o wifi5.o wifi6.o main.o

wifi4.o: WiFi4.cpp Wifi4.h Commons.h
	g++ -c WiFi4.cpp

wifi5.o: WiFi5.cpp Wifi5.h Commons.h
	g++ -c WiFi5.cpp

wifi6.o: WiFi6.cpp Wifi6.h Commons.h
	g++ -c WiFi6.cpp
main.o: main.cpp Wifi4.h Wifi5.h Wifi6.h Commons.h
	g++ -c main.cpp
	
# Command
Open Terminal and enter
    make

    ./ouput
