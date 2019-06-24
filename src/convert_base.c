/*
** EPITECH PROJECT, 2018
** palindrome
** File description:
** fonction convert base
*/

#include "my.h"

char *find_base(int nbr)
{
    char *str = malloc(sizeof(char) * nbr + 1);
    int i = 0;

    if (nbr <= 1 || nbr > 10)
        exit (84);
    for (i = 0; nbr > 0; i++){
        str[i] = i + 48;
        nbr--;
    }
    str[i] = '\0';
    return (str);
}

int my_compute_power_rec(int nb, int p)
{
    int result;

    if (nb == 0 || p < 0)
        return (0);
    if (nb == 1 || p == 0)
        return (1);
    result = my_compute_power_rec(nb, p-1)* nb;
    nb = result;
    return (nb);
}

char *affichage(char *res)
{
    int count = 0;

    while (res[count] == '0' || res[count] == '\0')
        count = count + 1;
    return (&res[count]);
}

int test_maj(char *str)
{
    unsigned int count = 0;

    while (str[count] != '\0') {
        if (65 <= str[count] && str[count] <= 90)
            return (1);
        count = count + 1;
    }
    return (0);
}

int convert_base(int nbr, char *base)
{
    int size = strlen(base);
    char *res;
    int count = 0;
    int count2 = 0;
    int digit;
    int result;

    for (count = 0; my_compute_power_rec(size, count) < nbr; count++);
    res = malloc(sizeof(char) * count + 1);
    for (count = count; count >= 0; count--){
        digit = nbr/my_compute_power_rec(size, count);
        nbr = nbr - my_compute_power_rec(size, count)*digit;
            if (digit + 48 > 57)
                digit = digit + 39;
        res[count2] = digit + 48;
        count2 = count2 + 1;
    }
    result = atoi(affichage(res));
    free (res);
    return (result);
}
