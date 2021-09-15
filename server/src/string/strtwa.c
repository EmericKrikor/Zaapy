/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** string
*/

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char **my_str_to_wordtab(char *str)
{
    int i = 0;
    char **tab = malloc(sizeof(char *));
    char *alfa_tab = strtok(str, " ");
    bool stop = false;

    if (!str || !tab || !alfa_tab)
        return (NULL);
    while (stop == false) {
        tab[i] = strdup(alfa_tab);
        i++;
        tab = realloc(tab, (sizeof(char *) * (i + 1)));
        alfa_tab = strtok(NULL, " ");
        alfa_tab == NULL ? tab[i] = alfa_tab, stop = true : false;
    }
    free(alfa_tab);
    return (tab);
}