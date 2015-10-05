#include "chromo.h"

chromosome_t::chromosome_t() : genes(""), fitness(0) {}

chromosome_t::chromosome_t(std::string new_genes, float new_fitness) : genes(new_genes), fitness(new_fitness) {} 


void chromosome_t::set_fitness(float new_fitness)
{
	this->fitness = new_fitness;
}

float chromosome_t::get_fitness()
{
	return this->fitness;
}

std::string chromosome_t::get_genes()
{
	return this->genes;
}