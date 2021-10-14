#ifndef ONLY_SMITHS
#define ONLY_SMITHS

#include <stdlib.h>
#include "agent.h"

typedef struct s_agent t_agent;

void mx_exterminate_agents(t_agent ***agents);

t_agent **mx_only_smiths(t_agent **agents, int strength);
t_agent *mx_create_agent(char *name, int power, int strength);

char *mx_strcpy(char *, const char *);
char *mx_strnew(const int);
int mx_strlen(const char *);
char *mx_strdup(const char *str);
int mx_strcmp(const char *s1, const char *s2);

#endif
