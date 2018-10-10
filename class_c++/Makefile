main: main.cpp Utils.cpp
	# build sample1.cpp
	g++ $^ -o $@.out -O1 `pkg-config --cflags opencv` `pkg-config --libs opencv`
	# execute
	./$@.out
	# delete execution file
	rm $@.out