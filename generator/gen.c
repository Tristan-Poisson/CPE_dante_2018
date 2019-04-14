/*
** EPITECH PROJECT, 2019
** dante
** File description:
** gen
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

void unperfect(char **maze)
{
    maze[0][1] = '*';
    maze[1][0] = '*';
    maze[1][1] = '*';
}

int check_case(char **maze, int x, int y)
{
    int count = 0;

    if (x < 0 || y < 0 || maze[y] == NULL)
        return (0);
    if (maze[y][x] != 'X' || maze[y][x] == '\0')
        return (0);
    if (maze[y][x + 1] == '*')
        count++;
    if (maze[y + 1] != NULL && maze[y + 1][x] == '*')
        count++;
    if (x > 0 && maze[y][x - 1] == '*')
        count++;
    if (y > 0 && maze[y - 1][x] == '*')
        count++;
    if (count > 1)
        return (0);
    return (1);
}

void dig_maze(int x, int y, char **maze)
{
    int dirr = random() % 4;
    if (check_case(maze, x, y)){
        maze[y][x] = '*';
        for (int i = 0; i < 4; i++) {
            dirr = dirr % 4;
            if (dirr == 0)
                dig_maze(x + 1, y, maze);
            if (dirr == 1)
                dig_maze(x - 1, y, maze);
            if (dirr == 2)
                dig_maze(x, y + 1, maze);
            if (dirr == 3)
                dig_maze(x, y - 1, maze);
            dirr++;
        }
    }
}
