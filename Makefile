CXX := g++
CFLAGS := -O2 -Wall -std=c++11
SRC_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/, $(notdir $(SRC_FILES:.cpp=.o)))
EXE := ParticleExplosion
INDIR := -Iinclude
LIBDIR := -L/usr/lib/x86_64-linux-gnu
LIBS := -lSDL2 -lOpenCL

all: $(EXE)

run: $(EXE)
	./$(EXE)

$(EXE): $(OBJ_FILES)
	$(CXX) $^ $(LIBDIR) $(LIBS) -o $@

obj/%.o: src/%.cpp
	$(CXX) $(CFLAGS) $(INDIR) -c -o $@ $<

.PHONY: clean

clean:
	rm $(OBJ_FILES) $(EXE)
