#ifndef CHROMO_H
#define CHROMO_H

#include <string>

class chromosome_t
{
	float fitness;
	std::string genes;

public:
	chromosome_t();
	chromosome_t(std::string new_genes, float new_fitness);
	void set_fitness(float new_fitness);
	float get_fitness();
	std::string get_genes();
};

#endif