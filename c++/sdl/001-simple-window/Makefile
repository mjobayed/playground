CXX := g++
SRCS := main.cpp
FLAGS := $(shell pkg-config --cflags --libs sdl2)

output: $(SRCS)
	$(CXX) -o output $(SRCS) $(FLAGS)

run: output
	./output

clean:
	rm -f output
