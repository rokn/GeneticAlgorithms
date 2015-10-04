#include "genetics.h"

#define RANDOM_NUM	((float)rand()/(RAND_MAX+1))

chromosome_t roulette_selection(chromosome_t *population, int pop_size)
{
	float total_fitness = 0;

	int i;
	
	for (i = 0; i < pop_size; ++i)
	{
		total_fitness += population[i].get_fitness();
	}

	float random_fitness = RANDOM_NUM * total_fitness;

	float curr_fitness = 0;
	
	for (i = 0; i < pop_size; ++i)
	{
		curr_fitness += population[i].get_fitness();

		if(curr_fitness >= random_fitness)
		{
			return population[i];
		}
	}
}

void crossover(float rate, std::string &offspring1, std::string &offspring1)
{
	if(rate >= RANDOM_NUM)
	{
		int random_bit = (int) (RANDOM_NUM * offspring1.length());

		std::string tmp = offspring1.substr(random_bit, offspring1.length() - random_bit);
		offspring1.replace(random_bit, offspring1.length() - random_bit, offspring2, random_bit, offspring2.length() - random_bit);
		offspring2.replace(random_bit, offspring2.length() - random_bit, tmp);
	}
}

void mutate(float rate, std::string &genes)
{
	int i;
	
	for (i = 0; i < genes.length; ++i)
	{
		if(rate >= RANDOM_NUM)
		{
			if(genes[i] == '0')
			{
				genes[i] = '1';
			}
			else
			{
				genes[i] = '0';
			}
		}
	}
}