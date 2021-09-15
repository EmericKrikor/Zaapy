/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** concat_tab
*/

#include <stdlib.h>
#include <string.h>

char *concat_tab(const char **tab)
{
    size_t total_len = 0;
    char *dest = NULL;

    for (int i = 0; tab[i]; i++)
        total_len += strlen(tab[i]) + 1;
    dest = malloc(sizeof(char) * (total_len + 1));
    for (int i = 0; tab[i]; i++) {
        if (i == 0) {
            strcpy(dest, tab[i]);
            strcat(dest, " ");
        }
        else {
            strcat(dest, tab[i]);
            strcat(dest, " ");
        }
    }
    dest[total_len] = 0;
    return dest;
}