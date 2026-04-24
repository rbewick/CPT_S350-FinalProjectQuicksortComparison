main: hoaresQuicksort.o hq.o
	g++ hoaresQuicksort.o hq.o -o main
hoaresQuicksort.o: hoaresQuicksort.cpp
	g++ -c hoaresQuicksort.cpp -o hoaresQuicksort.o
hq.o: hq.h hq.cpp
	g++ -c hq.cpp -o hq.o

