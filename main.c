/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** main
*/

#include "bsq.h"

int main(int ac, char **av)
{
    if (ac == 2)
        return bsq(av[1]);
    return 84;
}
