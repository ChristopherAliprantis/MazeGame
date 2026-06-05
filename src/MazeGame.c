#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

typedef char* string;

typedef struct {
	string* grid; 
} Maze;


Maze CreateMaze()
{
	Maze maze;
	maze.grid = "###############",
				"###############",
				"###############",
				"###############",
				"###############",
				"###############",
				"###############",
				"###############",
				"###############",
				"###############",
				"###############",
				"###############",
				"###############",
				"###############",
				"###############";
	int start = (rand() % 14) + 1;
	int end = (rand() % 14) + 1;
	return maze;
}

int main(char** argv[])
{
	if (argv[0] == "--help")
	{
		printf("arrow keys to move\n");
		free(argv);
		return 0;
	}
	
}