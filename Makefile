.PHONY = all clean

SCRS := matrixExploration.cpp, collectGold.cpp
BINS := matrixExploration.out, collectGold.out

all: matrixExploration.out, collectGold.out

matrixExploration.out:  matrixExploration.cpp
	g++ -Wall -O3 matrixExploration.cpp -o matrixExploration.out

collectGold.out: collectGold.cpp
	g++ -Wall -O3 collectGold.cpp -o collectGold.out

clean:
	rm *.out
