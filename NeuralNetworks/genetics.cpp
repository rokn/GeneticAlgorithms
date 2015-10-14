#include "genetics.h"
#include "main.h"

// std::string get_random_chromo(int length)
// {
// 	std::string genes;

// 	int i;
	
// 	for (i = 0; i < length; ++i)
// 	{
// 		if(RANDOM_NUM >= 0.5)
// 		{
// 			genes.push_back('0');
// 		}
// 		else
// 		{
// 			genes.push_back('1');
// 		}
// 	}

// 	return genes;
// }

DNA_t roulette_selection(std::vector<DNA_t> *population, int pop_size)
{
	float total_fitness = 0;

	std::vector<DNA_t>::iterator i;
	
	for (i = population->begin(); i != population->end(); ++i)
	{
		total_fitness += i->get_fitness();
	}

	float random_fitness = RANDOM_NUM * total_fitness;

	float curr_fitness = 0;
	
	for (i = population->begin(); i != population->end(); ++i)
	{
		curr_fitness += i->get_fitness();

		if(curr_fitness >= random_fitness)
		{
			return *i;
		}
	}

	throw "Bad selection";	
}

// void crossover(float rate, std::string *offspring1, std::string *offspring2)
// {
// 	if(rate >= RANDOM_NUM)
// 	{
// 		int random_bit = (int) (RANDOM_NUM * offspring1->length());

// 		std::string tmp = offspring1->substr(random_bit, offspring1->length() - random_bit);
// 		offspring1->replace(random_bit, offspring1->length() - random_bit, *offspring2, random_bit, offspring2->length() - random_bit);
// 		offspring2->replace(random_bit, offspring2->length() - random_bit, tmp);
// 	}
// }

// void crossover_each(float rate, std::string *offspring1, std::string *offspring2 , int gene_length)
// {
// 	if(rate >= RANDOM_NUM)
// 	{
// 		int i;
// 		std::string tmp;

// 		for (i = 0; i < offspring1->length(); i += gene_length)
// 		{
// 			if(RANDOM_NUM >= 0.5)
// 			{
// 				int b;
				
// 				for (b = 0; b < gene_length; ++b)
// 				{
// 					tmp.push_back(offspring1->at(i+b));
// 				}
// 			}
// 			else
// 			{
// 				int b;
				
// 				for (b = 0; b < gene_length; ++b)
// 				{
// 					tmp.push_back(offspring2->at(i+b));
// 				}
// 			}
// 		}

// 		for (i = 0; i < offspring1->length(); i += gene_length)
// 		{
// 			if(RANDOM_NUM >= 0.5)
// 			{
// 				offspring2->replace(i, gene_length, *offspring1, i, gene_length);
// 			}
// 		}

// 		*offspring1 = tmp;
// 	}
// }

// void mutate(float rate, std::string *genes)
// {
// 	int i;
// 	for (i = 0; i < genes->length(); ++i)
// 	{
// 		float r = RANDOM_NUM;
// 		if(rate >= r)
// 		{
// 			if(genes->at(i) == '0')
// 			{
// 				genes->replace(i, 1, "1");
// 			}
// 			else
// 			{
// 				genes->replace(i, 1, "0");
// 			}
// 		}
// 	}
// }