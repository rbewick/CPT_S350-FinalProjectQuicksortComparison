main: QuicksortMain.o hq.o
	g++ QuicksortMain.o hq.o -o main

QuicksortMain.o: QuicksortMain.cpp
	g++ -c QuicksortMain.cpp

hq.o: hq.cpp
	g++ -c hq.cpp
clean:
	rm -f *.o 