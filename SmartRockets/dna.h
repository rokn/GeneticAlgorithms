#ifndef DNA_H
#define DNA_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include "AGE/AGE.h"

using namespace std;

class DNA_t
{
	float fitness;
	vector<float> genes;

public:
	DNA_t();
	DNA_t( const DNA_t &obj);
	DNA_t(float (*)(), int);
	DNA_t(vector<float>, float new_fitness);
	void set_fitness(float new_fitness);
	float get_fitness();
	vector<float> get_genes();
	void crossover(float, DNA_t *);
	void mutate(float rate, float (*)());
	// void crossover_each(float, std::string *, std::string *, int);
};

#endif