#ifndef CHROMO_H
#define CHROMO_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

template <class T>
class chromosome_t
{
	float fitness;
	vector<T> genes;

public:
	chromosome_t(T (*)(), int);
	chromosome_t(vector<T>, float new_fitness);
	void set_fitness(float new_fitness);
	float get_fitness();
	vector<T> get_genes();
	void crossover(float, chromosome_t *);
	void mutate(float rate, T (*)());
	// void crossover_each(float, std::string *, std::string *, int);
};

#endif