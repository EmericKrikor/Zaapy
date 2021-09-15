/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** strip_copy
*/

#include <stdlib.h>
#include <string.h>
#include "raise.h"

char *strip_copy(const char *s)
{
    char *p = malloc(strlen(s) + 1);

    if (!p)
        raise("Syscall error");
    char *p2 = p;
    while (*s != '\0') {
        if (*s != '\r' && *s != '\n')
            (*p2++) = *s++;
        else
            ++s;
    }
    *p2 = '\0';
    return p;
}