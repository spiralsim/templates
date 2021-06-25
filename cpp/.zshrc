run () {
	g++ -std=gnu++17 "$1.cpp" -o "$1" && "./$1"
}