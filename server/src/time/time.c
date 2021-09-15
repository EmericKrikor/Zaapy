/*
** EPITECH PROJECT, 2021
** Zappy
** File description:
** time handler for cooldowns between clients requests
*/

#include "zappy_server.h"

bool is_cooldown_ready(client_t *client)
{
    uint64_t delta;
    float cooldown = 0;

    clock_gettime(CLOCK_MONOTONIC_RAW, &(client->cooldown_dest));
    delta = (client->cooldown_dest.tv_sec - client->cooldown_start.tv_sec) *
    1000000 + (client->cooldown_dest.tv_nsec - client->cooldown_start.tv_nsec)
    / 1000;
    cooldown = delta / 1000000.0;
    if (cooldown >= client->action_cooldown)
        return true;
    return false;
}

void reset_cooldown(client_t *client)
{
    clock_gettime(CLOCK_MONOTONIC_RAW, &(client->cooldown_start));
}

void set_cooldown(client_t *client, infos_t infos, float cooldown)
{
    client->action_cooldown = cooldown / infos.freq;
}

/*
** CHRONO
*/

bool chrono_is_cooldown_ready(chrono_t *chrono)
{
    uint64_t delta;
    float cooldown = 0;

    clock_gettime(CLOCK_MONOTONIC_RAW, &(chrono->cooldown_dest));
    delta = (chrono->cooldown_dest.tv_sec - chrono->cooldown_start.tv_sec) *
    1000000 + (chrono->cooldown_dest.tv_nsec - chrono->cooldown_start.tv_nsec)
    / 1000;
    cooldown = delta / 1000000.0;
    if (cooldown >= chrono->action_cooldown)
        return true;
    return false;
}

void chrono_start(chrono_t *chrono)
{
    clock_gettime(CLOCK_MONOTONIC_RAW, &(chrono->cooldown_start));
}

void chrono_set_cooldown(chrono_t *chrono, infos_t infos, float cooldown)
{
    chrono->action_cooldown = cooldown / infos.freq;
}