/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** header for palindrome
*/

#ifndef MY_H_
#define MY_H_
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ncurses.h>
#include <sys/wait.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <string.h>
#include "struct.h"

void transf_int(int nbr, flag_t info);
void find_pal(int nbr, flag_t info, int found);
int convert_base(int nbr, char *base);
char *find_base(int nbr);
int convert_to_ten(int nbr, int base);
int my_compute_power_rec(int nb, int p);
int my_addition(int nbr_o, int nbr_two, int base);
char *strreverse(char *str);
int strisnum(char *str);
int find_arg(int ac, char **av, char *str);
void test_error(int ac, char **av);
#endif
