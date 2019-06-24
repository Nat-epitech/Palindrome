/*
** EPITECH PROJECT, 2018
** palindrome
** File description:
** fonction to base 10
*/

#include "my.h"

char *strreverse(char *str)
{
    char *save = malloc(sizeof(char) * strlen(str) + 1);
    int j = 0;

    for (int i = strlen(str) - 1; i >= 0; i--){
        save[j] = str[i];
        j++;
    }
    save[j] = '\0';
    free (str);
    return (save);
}

int convert_to_ten(int nbr, int base)
{
    int i = 1;
    int p = 0;
    int result = 0;

    for (int d = 10; nbr/d != 0; d *= 10)
        i++;
    for (; nbr != 0; nbr = nbr/10){
        result = result + (nbr % 10 * my_compute_power_rec(base, p));
        p++;
    }
    return (result);
}
