#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int width;
	int length;
	char** grid[];
} Maze;

Maze CreateMaze(int width, int length)
{
	Maze maze;
	maze.width = width;
	maze.length = length;
	char** grid = "";
	for (int i = 0; i < width; i++)
	{
		grid[i] = (char*)malloc(length * sizeof(char));
	}
	maze.grid = grid;
	return maze;
}

int main(char* argv[])
{
	if (argv[0] == "--help")
	{
		printf("arrow keys to move\n");
		return 0;
	}
	
}