build:
	g++-8 -w -std=c++17 -Wfatal-errors \
	-g \
    src/*.cpp \
    src/core/*.hpp \
    test/*.cpp \
    test/core/*.hpp \
	-o ecs \
	-I"./lib/catch2" \
	-L"./lib/catch2" \
	-lSDL2 \
	-lSDL2_image \
	-lSDL2_ttf \
	-lSDL2_mixer;

build-test:
	g++-8 -w -std=c++17 -Wfatal-errors \
    test/*.cpp \
    src/core/*.hpp \
    src/components/*.hpp \
    test/core/*.hpp \
    lib/catch2/*.hpp \
    lib/catch2/*.cpp \
	-o tests;

build-dev:
	g++-8 -w -std=c++17 -Wfatal-errors \
	-g \
	-O0 \
	./src/*.cpp \
	-o game-dev \
	-lSDL2 \
	-lSDL2_image \
	-lSDL2_ttf \
	-lSDL2_mixer;

test:
	make build-test && ./tests;

memcheck:
	valgrind --leak-check=full \
	--show-leak-kinds=all \
	--log-file=valgrind-out.txt \
	--track-origins=yes \
	--verbose \
	./game-dev;

cachegrind:
	valgrind --tool=cachegrind \
	--branch-sim=yes \
	./game;

clean:
	rm ./game;

run:
	./game;
