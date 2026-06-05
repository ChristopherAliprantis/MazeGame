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
    for (int i = 0; i < 7; i++)
    {
        printf("%s\n", maze.grid[i]);
    }
}

void GrowBranch(Maze* maze, int start_x, int start_y)
{
    int cx = start_x;
    int cy = start_y;

    for (int i = 0; i < 8; i++)
    {
        int directions[4][2] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };
        int valid_dirs[4];
        int valid_count = 0;

        for (int d = 0; d < 4; d++)
        {
            int nx = cx + directions[d][0];
            int ny = cy + directions[d][1];

            if (nx >= 1 && nx <= 13 && ny >= 1 && ny <= 5)
            {
                if (maze->grid[ny][nx] == '#')
                {
                    int open_neighbors = 0;
                    for (int n = 0; n < 4; n++)
                    {
                        int nnx = nx + directions[n][0];
                        int nny = ny + directions[n][1];
                        if (nnx >= 0 && nnx <= 14 && nny >= 0 && nny <= 6)
                        {
                            if (maze->grid[nny][nnx] == ' ')
                            {
                                open_neighbors++;
                            }
                        }
                    }

                    if (open_neighbors <= 1)
                    {
                        valid_dirs[valid_count] = d;
                        valid_count++;
                    }
                }
            }
        }

        if (valid_count == 0) break;

        int chosen_dir = valid_dirs[rand() % valid_count];
        cx += directions[chosen_dir][0];
        cy += directions[chosen_dir][1];

        maze->grid[cy][cx] = ' ';

        if (rand() % 10 < 3)
        {
            GrowBranch(maze, cx, cy);
        }
    }
}

Maze CreateMaze()
{
    Maze maze;

    static char filledmaze[7][16] =
    {
        "###############",
        "###############",
        "###############",
        "###############",
        "###############",
        "###############",
        "###############",
    };

    for (int i = 0; i < 7; i++)
    {
        maze.grid[i] = filledmaze[i];
    }

    int start_col = (rand() % 13) + 1;
    int end_col = (rand() % 13) + 1;

    maze.start[0] = start_col;
    maze.start[1] = 0;

    maze.end[0] = end_col;
    maze.end[1] = 6;

    maze.player[0] = maze.start[0];
    maze.player[1] = maze.start[1];

    coord currentmazemakingcoord;
    currentmazemakingcoord[0] = maze.start[0];
    currentmazemakingcoord[1] = 1;

    maze.grid[maze.start[1]][maze.start[0]] = ' ';
    maze.grid[maze.end[1]][maze.end[0]] = ' ';

    while (currentmazemakingcoord[0] != maze.end[0] || currentmazemakingcoord[1] != 5)
    {
        maze.grid[currentmazemakingcoord[1]][currentmazemakingcoord[0]] = ' ';

        int next_x = currentmazemakingcoord[0];
        int next_y = currentmazemakingcoord[1];

        if (currentmazemakingcoord[1] < 5 && (rand() % 2 == 0 || currentmazemakingcoord[0] == maze.end[0]))
        {
            next_y++;
        }
        else if (currentmazemakingcoord[0] < maze.end[0])
        {
            next_x++;
        }
        else if (currentmazemakingcoord[0] > maze.end[0])
        {
            next_x--;
        }

        if (next_x >= 1 && next_x <= 13 && next_y >= 1 && next_y <= 5)
        {
            currentmazemakingcoord[0] = next_x;
            currentmazemakingcoord[1] = next_y;
        }
    }

    maze.grid[5][maze.end[0]] = ' ';

    for (int y = 1; y <= 5; y++)
    {
        for (int x = 1; x <= 13; x++)
        {
            if (maze.grid[y][x] == ' ')
            {
                if (rand() % 100 < 40)
                {
                    GrowBranch(&maze, x, y);
                }
            }
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
