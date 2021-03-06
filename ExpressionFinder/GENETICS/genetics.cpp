#include "genetics.h"

#define RANDOM_NUM	((float)rand()/(RAND_MAX+1) + 1)

std::string get_random_chromo(int length)
{
	std::string genes;

	int i;
	
	for (i = 0; i < length; ++i)
	{
		if(RANDOM_NUM >= 0.5)
		{
			genes.push_back('0');
		}
		else
		{
			genes.push_back('1');
		}
	}

	return genes;
}

std::string roulette_selection(std::vector<chromosome_t> *population, int pop_size)
{
	float total_fitness = 0;

	std::vector<chromosome_t>::iterator i;
	
	for (i = population->begin(); i != population->end(); ++i)
	{
		total_fitness += (*i).get_fitness();
	}

	float random_fitness = RANDOM_NUM * total_fitness;

	float curr_fitness = 0;
	
	for (i = population->begin(); i != population->end(); ++i)
	{
		curr_fitness += (*i).get_fitness();

		if(curr_fitness >= random_fitness)
		{
			return (*i).get_genes();
		}
	}

	return NULL;
}

void crossover(float rate, std::string *offspring1, std::string *offspring2)
{
	if(rate >= RANDOM_NUM)
	{
		int random_bit = (int) (RANDOM_NUM * offspring1->length());

		std::string tmp = offspring1->substr(random_bit, offspring1->length() - random_bit);
		offspring1->replace(random_bit, offspring1->length() - random_bit, *offspring2, random_bit, offspring2->length() - random_bit);
		offspring2->replace(random_bit, offspring2->length() - random_bit, tmp);
	}
}

void mutate(float rate, std::string *genes)
{
	int i;
	for (i = 0; i < genes->length(); ++i)
	{
		float r = RANDOM_NUM;
		if(rate >= r)
		{
			if(genes->at(i) == '0')
			{
				genes->replace(i, 1, "1");
			}
			else
			{
				genes->replace(i, 1, "0");
			}
		}
	}
}