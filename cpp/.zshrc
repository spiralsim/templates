run () {
	echo "g++ -std=gnu++17 -O2 -Wall -Wl,-stack_size -Wl,0x10000000 $1.cpp -o $1 && ./$1"
	g++ -std=gnu++17 -O2 -Wall -Wl,-stack_size -Wl,0x10000000 $1.cpp -o $1
	echo "Running"
	./$1
}