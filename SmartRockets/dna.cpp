#include "dna.h"
#include "main.h"

#define RANDOM_NUM	((float)rand()/(RAND_MAX+1) + 1)

using namespace std;

DNA_t::DNA_t() : fitness(0) {}

DNA_t::DNA_t( const DNA_t &obj)
{
	int i;
	
	for (i = 0; i < obj.genes.size(); ++i)
	{
		this->genes.push_back(obj.genes.at(i));
	}
}

DNA_t::DNA_t(float (*get_random_gene)(), int gene_count) 
{
	int i;
	
	for (i = 0; i < gene_count; ++i)
	{
		this->genes.push_back(get_random_gene());
	}
}

DNA_t::DNA_t(vector<float> new_genes, float new_fitness) : fitness(new_fitness) 
{
	int i;
	
	for (i = 0; i < new_genes.size(); ++i)
	{
		this->genes.push_back(new_genes.at(i));
	}
}

void DNA_t::set_fitness(float new_fitness)
{
	this->fitness = new_fitness;
}

float DNA_t::get_fitness()
{
	return this->fitness;
}

vector<float> DNA_t::get_genes()
{
	return this->genes;
}

void DNA_t::crossover(float rate, DNA_t *offspring)
{
	if(rate >= RANDOM_NUM)
	{
		int i;
		vector<float> tmp;

		for (i = 0; i < this->genes.size(); i++)
		{
			if(RANDOM_NUM >= 0.5)
			{
				tmp.push_back(this->genes.at(i));
			}
			else
			{
				tmp.push_back(offspring->genes.at(i));
			}
		}

		for (i = 0; i < this->genes.size(); i++)
		{
			if(RANDOM_NUM >= 0.5)
			{
				offspring->genes.at(i) = this->genes.at(i);
			}
		}

		this->genes = tmp;
	}
}

void DNA_t::mutate(float rate, float (*get_random_gene)())
{
	int i;
	for (i = 0; i < this->genes.size(); ++i)
	{
		float r = RANDOM_NUM;

		if(rate >= r)
		{
			this->genes.at(i) = get_random_gene();
		}
	}
}