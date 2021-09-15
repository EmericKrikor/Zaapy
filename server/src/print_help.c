/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** usage
*/

#include <stdio.h>

#define HELP "USAGE: ./zappy_server -p port -x width -y height \
-n name1 name2 ... -c clientsNb -f freq\n\
\tport        is the port number\n\
\twidth       is the width of the world\n\
\theight      is the height of the world\n\
\tnameX       is the name of the team X\n\
\tclientsNb   is the number of authorized clients per team\n\
\tfreq        is the reciprocal of time unit for execution of actions\n"

int print_help(void)
{
    printf(HELP);
    return 0;
}