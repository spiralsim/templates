run () {
	echo "Running g++ for CP"
	g++ -std=gnu++17 "$1.cpp" -o "$1" && "./$1"
}