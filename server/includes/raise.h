/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** Raise error and exit
*/

#ifndef RAISE_H
# define RAISE_H

# include <stdio.h>
# include <stdlib.h>

# define raise(msg)                                             \
do {                                                            \
    fprintf(stderr, "%s: %u: %s\n", __FILE__, __LINE__, msg);   \
    exit(84);                                                   \
} while (0)

#endif
