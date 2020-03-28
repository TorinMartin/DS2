#ifndef _MAZE_H
#define _MAZE_H

#include <iostream>
#include <fstream>
#include <string>
#include "stack.h"

class Maze
{
private:
	int cols;
	int rows;
	char** maze;
	string mazeFile;

	void Create();
	void Read();

public:
	Maze();
	Maze(string filename);
	virtual ~Maze();
	void Solve();
	void Print();
};

#endif

