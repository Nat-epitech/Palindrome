/*
** EPITECH PROJECT, 2018
** palindrome
** File description:
** palindrome
*/

#include "my.h"

int my_reverse(int nbr)
{
    int i = 1;
    char *str;

    for (int d = 10; nbr/d != 0; d *= 10)
        i++;
    str = malloc(sizeof(char) * i + 1);
    sprintf(str, "%d", nbr);
    str = strreverse(str);
    i = atoi(str);
    free (str);
    return (i);
}

int test_palin(int nbr)
{
    char *str;
    int i = 1;
    int j = 0;

    for (int d = 10; nbr/d != 0; d *= 10)
        i++;
    str = malloc(sizeof(char) * i + 1);
    sprintf(str, "%d", nbr);
    for (i = 0; str[i + 1] != '\0'; i++);
    for (; j < i; i--){
        if (str[i] != str[j]){
            free (str);
            return (0);
        }
        j++;
    }
    free (str);
    return (1);
}

void find_pal(int nbr, flag_t info, int found)
{
    int res = nbr;
    int i;
    int save = nbr;

    nbr = convert_base(nbr, info.f_b);
    if (test_palin(nbr) != 1)
        exit (84);
    for (int j = 0; j <= save; j++){
        res = j;
        for (i = 0; convert_base(res, info.f_b) < nbr && i < info.flag_max; i++)
            res = res + \
            convert_to_ten(my_reverse(convert_base(res, info.f_b)), info.b_nbr);
        if (convert_base(res, info.f_b) == nbr && i >= info.flag_min){
            found = 1;
            printf("%d leads to %d in %d iteration(s) in base %d\n", j, res, \
            i, info.b_nbr);
        }
    }
    if (found == 0)
        printf("no solution\n");
}

void transf_int(int nbr, flag_t info)
{
    int res = nbr;
    int i = 0;

    for (i = 0; (test_palin(convert_base(res, info.f_b)) != 1 && \
    i < info.flag_max) || i < info.flag_min; i++)
        res = res + convert_to_ten(my_reverse(convert_base(res, info.f_b)), \
        info.b_nbr);
    if (i == info.flag_max && test_palin(convert_base(res, info.f_b)) != 1)
        printf("no solution\n");
    else
        printf("%d leads to %d in %d iteration(s) in base %d\n", nbr, \
        res, i, info.b_nbr);
}
