#include "maze.h"

using namespace std;

Maze::Maze() {
	this->mazeFile = "maze.txt";
	Create();
	Read();
}

Maze::Maze(string filename) {
	this->mazeFile = filename;
	Create();
	Read();
}

// Destructor - Iterate through array, deleting each subarray. Finally, delete the array.
Maze::~Maze() {
	for (int i=0;i<rows;i++) {
		delete[] maze[i];
	}
	delete[] maze;
}

// Iterate through the array, if character at index is not *, print it.
void Maze::Print() {
	for (int i = 0; i < rows - 1; i++) {
		for (int x = 0; x < cols; x++) {
			if (maze[i][x] != '*') {
				cout << maze[i][x];
			}
			else {
				cout << ' ';
			}
		}
	}
}

void Maze::Create() {
	string line;
	ifstream file(mazeFile);

	// Count each line in the maze file - lines represent rows.
	while (getline(file, line)) {
		rows++;
	}

	file.close();

	// Length of each line represents the columns.
	cols = line.length() + 1;
	rows += 1;

	// Create an array of chars
	maze = new char* [rows];

	// Iterate through the array, creating a new array of chars at each index, forming the 2d array.
	for (int i = 0; i < rows; i++) {
		maze[i] = new char[cols];
	}
}

// Iterate through the file, assigning each character to an index within the array
void Maze::Read() {
	char c = ' ';

	ifstream file;

	file.open(mazeFile);

	if (file.is_open())
	{
		for (int i = 0; i < rows; i++) {
			for (int x = 0; x < cols; x++) {
				file >> noskipws >> c;
				maze[i][x] = c;
			}
		}
	}
	file.close();
}

void Maze::Solve() {

	int count = 0;

	Stack row;
	Stack col;

	int r = 1;
	int c = 0;

	while (true) {
		if (r == (rows - 3) && c == (cols - 2)) { // Determine the end position of the maze
			maze[rows - 3][cols - 2] = '#'; // Mark the last position
			break; // Break from the loop as the maze has been solved.
		}

		// Check Up/Down/Left/Right to see if next space is available. 
		// If so, mark current position and push index to row/col stacks.
		// Increment row / column variable respectively.
		if (maze[r][c + 1] == ' ') { // Right
			row.Push(r);
			col.Push(c);
			maze[r][c] = '#';
			c++;
		}
		else if (maze[r][c - 1] == ' ') { // Left
			row.Push(r);
			col.Push(c);
			maze[r][c] = '#';
			c--;
		}
		else if (maze[r - 1][c] == ' ') { // Up
			row.Push(r);
			col.Push(c);
			maze[r][c] = '#';
			r--;
		}
		else if (maze[r + 1][c] == ' ') { // Down
			row.Push(r);
			col.Push(c);
			maze[r][c] = '#';
			r++;
		}
		// Ran into a dead end. Mark position with special character.
		// Set r / c variable to most recent valid position.
		// Remove most recent row / col from stack.
		else {
			maze[r][c] = '*';
			r = row.GetTop();
			c = col.GetTop();

			row.Pop();
			col.Pop();
		}
	}
}