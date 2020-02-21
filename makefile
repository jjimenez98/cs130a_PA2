All: prog1.out
prog1.out: HashTable.cpp Heap.cpp Quash.cpp
	g++ -o prog1.out Heap.cpp HashTable.cpp Quash.cpp
