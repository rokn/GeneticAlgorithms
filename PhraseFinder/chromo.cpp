#include "chromo.h"
#include <vector>

#define RANDOM_NUM	((float)rand()/(RAND_MAX+1) + 1)

using namespace std;

template <class T>
chromosome_t<T>::chromosome_t(T (*get_random_gene)(), int gene_count) 
{
	int i;
	
	for (i = 0; i < gene_count; ++i)
	{
		this->genes.push_back(get_random_gene());
	}
}

template <class T>
chromosome_t<T>::chromosome_t(vector<T> new_genes, float new_fitness) : genes(new_genes), fitness(new_fitness) {} 

template <class T>
void chromosome_t<T>::set_fitness(float new_fitness)
{
	this->fitness = new_fitness;
}

template <class T>
float chromosome_t<T>::get_fitness()
{
	return this->fitness;
}

template <class T>
vector<T> chromosome_t<T>::get_genes()
{
	return this->genes;
}

template <class T>
void chromosome_t<T>::crossover(float rate, chromosome_t *offspring)
{
	if(rate >= RANDOM_NUM)
	{
		int i;
		vector<T> tmp;

		for (i = 0; i < this->genes.length(); i++)
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

		for (i = 0; i < this->genes.length(); i++)
		{
			if(RANDOM_NUM >= 0.5)
			{
				offspring->at(i) = this->genes.at(i);
			}
		}

		this->genes = tmp;
	}
}

template <class T>
void chromosome_t<T>::mutate(float rate, T (*get_random_gene)())
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