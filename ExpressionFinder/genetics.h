#ifndef GENETICS_H
#define GENETICS_H

#include <string>
#include <stdlib.h>

chromosome_t roulette_selection(chromosome_t *, int);
void crossover(float, std::string &, std::string &);
void mutate(float, std::string &);

#endif