// Torin Martin - W0404679

#include <iostream>
#include "maze.h"

using namespace std;

string file = "mazex.txt";

int main(){
	Maze maze(file);
	maze.Solve();
	maze.Print();
}

