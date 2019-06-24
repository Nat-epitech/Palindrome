/*
** EPITECH PROJECT, 2018
** palindrome
** File description:
** palindrome
*/

#include "my.h"

void test_help(char **av)
{
    if (av[1] == NULL)
        exit (84);
    if (av[1][0] != '-' || av[1][1] != 'h')
        return;
    printf("USAGE\n\t./palindrome -n number -p palindrome [-b base] [-imin i]\
[-imax i]\nDESCRIPTION\n\n\t-n nb\t\tinteger to be transformed (≥ 0)\n\t-p \
pal\t\tpalindromic number to be obtained (incompatible with the −n option) \
(≥ 0) if defined, all fitting values of n will be output\n\t-b base\t\tbase in \
which the procedure will be executed (1 < b ≤ 10) [def: 10]\n\t-imin i\t\t\
minimum number of iterations, included (≥ 0) [def: 0]\n\t-imax i\t\tmaximum \
number of iterations, included (≥ 0) [def: 100]\n");
    exit (0);
}

int find_arg(int ac, char **av, char *str)
{
    for (int i = 1; i < ac; i++){
        if (strcmp(av[i], str) == 0)
            return (i);
    }
    return (0);
}

void find_all_flag(flag_t *info, int ac, char **av)
{
    if (find_arg(ac, av, "-b") != 0){
        if (ac > find_arg(ac, av, "-b") + 1){
            info->f_b = find_base(atoi(av[find_arg(ac, av, "-b") + 1]));
            info->b_nbr = atoi(av[find_arg(ac, av, "-b") + 1]);
        }
        else
            exit (84);
    }
    if (find_arg(ac, av, "-imin") != 0){
        if (ac > find_arg(ac, av, "-imin") + 1)
            info->flag_min = atoi(av[find_arg(ac, av, "-imin") + 1]);
        else
            exit (84);
    }
    if (find_arg(ac, av, "-imax") != 0){
        if (ac > find_arg(ac, av, "-imax") + 1)
            info->flag_max = atoi(av[find_arg(ac, av, "-imax") + 1]);
        else
            exit (84);
    }
}

int main(int ac, char **av)
{
    flag_t info = {"0123456789", 10, 0, 100};

    test_help(av);
    test_error(ac, av);
    find_all_flag(&info, ac, av);
    if (info.flag_max < info.flag_min || info.flag_min < 0 || info.flag_max < 0)
        return (84);
    if (find_arg(ac, av, "-n") != 0 && ac > find_arg(ac, av, "-n") + 1)
        transf_int(atoi(av[find_arg(ac, av, "-n") + 1]), info);
    else if (find_arg(ac, av, "-p") != 0 && ac > find_arg(ac, av, "-p") + 1)
        find_pal(atoi(av[find_arg(ac, av, "-p") + 1]), info, 0);
    else
        return (84);
    return (0);
}
