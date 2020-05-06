APPNAME=main

OBJS=main.o the_lift.o floor.o

CXX=g++
CPPFLAGS=-std=c++11 -g -ggdb -O0
LDFLAGS=-g -ggdb -O0


all: $(APPNAME)

$(APPNAME): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $(OBJS)

%.o: %.c
	$(CXX) $(CPPFLAGS) -c $<

clean:
	rm -rf *.o main
