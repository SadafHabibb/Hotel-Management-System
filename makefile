hotelFinder.out: main.o hotel.o hashtable.o
	g++ main.o hotel.o hashtable.o -o hotelFinder.out

main.o: main.cpp bst.hpp hashtable.hpp
	g++ -c main.cpp

hotel.o: hotel.cpp hotel.hpp
	g++ -c hotel.cpp

hashtable.o: hashtable.cpp hashtable.hpp
	g++ -c hashtable.cpp

clean:
	rm main.o hotel.o hashtable.o hotelFinder.out


