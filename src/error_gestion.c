/*
** EPITECH PROJECT, 2018
** palindrome
** File description:
** palindrome
*/

#include "my.h"

int strisnum(char *str)
{
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] < '0' || str[i] > '9')
            return (-1);
    }
    return (0);
}

void test_error(int ac, char **av)
{
    if (ac < 3 || ac > 9)
        exit (84);
    if (find_arg(ac, av, "-n") != 0 && find_arg(ac, av, "-p") != 0)
        exit (84);
    if (find_arg(ac, av, "-n") != 0)
        if (strisnum(av[find_arg(ac, av, "-n") + 1]) == -1)
            exit (84);
    if (find_arg(ac, av, "-p") != 0)
        if (strisnum(av[find_arg(ac, av, "-p") + 1]) == -1)
            exit (84);
    for (int i = 1; i < ac; i++){
        if (!strcmp(av[i], "-p") && !strcmp(av[i], "-n") && \
        !strcmp(av[i], "-b") && !strcmp(av[i], "-imax") && \
        !strcmp(av[i], "-imin") && strisnum(av[i]) == -1)
            exit (84);
    }
}
