#include "only_smiths.h"

t_agent *mx_create_agent(char *name, int power, int strength) {
    if (!name) return NULL;
    t_agent *agent= malloc(16);
    agent->name = malloc(8);
    agent->name = mx_strdup(name);
    agent->power = (int)malloc(4);
    agent->strength = (int)malloc(4);
    agent->power = power;
    agent->strength = strength;
    return agent;
}

