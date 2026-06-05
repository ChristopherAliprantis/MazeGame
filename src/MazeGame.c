#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* string;

typedef int coord[2];

typedef struct {
    coord start;
    coord end;
    string grid[15];
} Maze;

void PrintMaze()
{

}

Maze CreateMaze()
{
    Maze maze;

    string filledmaze[15] = {
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
        "###############",
        "###############"
    };

    for (int i = 0; i < 15; i++) {
        maze.grid[i] = filledmaze[i];
    }
    free(filledmaze);
    int start_row = (rand() % 14) + 1;
    int end_row = (rand() % 14) + 1;

    maze.start[0] = 0;
    maze.start[1] = start_row;

    maze.end[0] = 14;
    maze.end[1] = end_row;

    maze.grid[maze.start[1]][maze.start[0]] = ' ';
    maze.grid[maze.end[1]][maze.end[0]] = ' ';

    return maze;
}

int main(int argc, char* argv[])
{
    if (argc > 1 && strcmp(argv[1], "--help") == 0)
    {
        printf("arrow keys to move\n");
        return 0;
    }

    return 0;
}


int main(int argc, char** argv[])
{
	if (argv[1] == "--help" && argc > 1)
	{
		printf("arrow keys to move\n");
		free(argv);
		return 0;
	}
	
}