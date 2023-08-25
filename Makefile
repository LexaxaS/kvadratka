DFLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE


all: a.exe

a.exe: object/main.o object/quadratic.o object/tester.o object/tools.o
	g++ object/main.o object/quadratic.o object/tester.o object/tools.o

object/main.o: src/main.cpp
	g++ $(DFLAGS) -I./include/ -c src/main.cpp -o object/main.o

object/quadratic.o: src/quadratic.cpp
	g++ $(DFLAGS) -I./include/ -c src/quadratic.cpp -o object/quadratic.o

object/tester.o: src/tester.cpp
	g++ $(DFLAGS) -I./include/ -c src/tester.cpp -o object/tester.o

object/tools.o: src/tools.cpp
	g++ $(DFLAGS) -I./include/ -c src/tools.cpp -o object/tools.o
