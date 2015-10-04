#ifndef GENETICS_H
#define GENETICS_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include "chromo.h"

std::string get_random_chromo(int);
std::string roulette_selection(std::vector<chromosome_t> *, int);
void crossover(float, std::string *, std::string *);
void mutate(float, std::string *);

#endif