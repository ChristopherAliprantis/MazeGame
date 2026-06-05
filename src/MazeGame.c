#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef char* string;

typedef int coord[2];

typedef struct {
    coord start;
    coord end;
    coord player;
    string grid[15];
} Maze;

void PrintMaze(Maze maze)
{
    for (int i = 0; i < 15; i++)
    {
        printf("%s\n", maze.grid[i]);
    }
}

Maze CreateMaze()
{
    Maze maze;

    static char filledmaze[15][16] =
    {
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

    for (int i = 0; i < 15; i++)
    {
        maze.grid[i] = filledmaze[i];
    }

    int start_col = (rand() % 13) + 1;
    int end_col = (rand() % 13) + 1;

    maze.start[0] = start_col;
    maze.start[1] = 0;

    maze.end[0] = end_col;
    maze.end[1] = 14;

    maze.player[0] = maze.start[0];
    maze.player[1] = maze.start[1];

    coord currentmazemakingcoord;
    currentmazemakingcoord[0] = maze.player[0];
    currentmazemakingcoord[1] = maze.player[1];

    maze.grid[maze.start[1]][maze.start[0]] = ' ';
    maze.grid[maze.end[1]][maze.end[0]] = ' ';

    while (currentmazemakingcoord[0] != maze.end[0] || currentmazemakingcoord[1] != maze.end[1])
    {
        maze.grid[currentmazemakingcoord[1]][currentmazemakingcoord[0]] = ' ';

        if (currentmazemakingcoord[1] < maze.end[1] && (rand() % 2 == 0 || currentmazemakingcoord[0] == maze.end[0]))
        {
            currentmazemakingcoord[1]++;
        }
        else if (currentmazemakingcoord[0] < maze.end[0])
        {
            currentmazemakingcoord[0]++;
        }
        else if (currentmazemakingcoord[0] > maze.end[0])
        {
            currentmazemakingcoord[0]--;
        }
    }

    return maze;
}

int main(int argc, char* argv[])
{
    srand((unsigned int)time(NULL));

    if (argc > 1 && strcmp(argv[1], "--help") == 0)
    {
        printf("arrow keys to move\n");
        return 0;
    }

    Maze maze = CreateMaze();
    PrintMaze(maze);
    return 0;
}
