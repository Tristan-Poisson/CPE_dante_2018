/*
** EPITECH PROJECT, 2019
** dante
** File description:
** main
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

void dig_maze(int x, int y, char **maze);
void unperfect(char **maze);

char **gen_base(int x, int y)
{
    char **maze = malloc(sizeof(char *) * (y + 1));
    for (int i = 0; i < y; i++){
        maze[i] = malloc(sizeof(char) * (x + 1));
        maze[i][x] = '\0';
        memset(maze[i], 'X', x);
    }
    maze[y] = NULL;
    return (maze);
}

void display(char **maze)
{
    for (int i = 0; maze[i] != NULL; i++){
        if (i != 0)
            printf("\n");
        printf("%s", maze[i]);
    }
}

int main(int ac, char **av)
{
    srandom(time(NULL));
    int x = atoi(av[1]);
    int y = atoi(av[2]);
    int perfect = (ac == 4);
    if (x == 0 || y == 0)
        return (84);
    char **maze = gen_base(x, y);
    dig_maze(0, 0, maze);
    if (maze[y - 1][x - 1] == 'X'){
        for (int i = 0; i < y; i++)
            memset(maze[i], 'X', x);
        dig_maze(0, 0, maze);
    }
    if (perfect != 1)
        unperfect(maze);
    display(maze);
    return (0);
}
