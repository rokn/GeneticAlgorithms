#include <iostream>
#include <vector>
#include "chromo.h"
#include "genetics.h"
#include <time.h>
#include <stdlib.h>
#include <cmath>

#define POPULATION_SIZE 100
#define GENES_COUNT 5
#define GENE_LENGTH 4
#define CROSSOVER_RATE 0.7f
#define MUTATION_RATE 0.01f

using namespace std;

float CalculateFitness(string, float);
vector<int> DecodeGenes(string);
int BinToDec(string);

int main()
{
	srand(time(NULL));
	vector<chromosome_t> population;
	vector<chromosome_t> tmp;
	bool end = false;
	float target;

	cin >> target;

	int i;
	
	for (i = 0; i < POPULATION_SIZE; ++i)
	{
		chromosome_t chromo(get_random_chromo(GENES_COUNT * GENE_LENGTH), 0);
		population.push_back(chromo);
	}

	while(!end)
	{

		tmp.clear();
		vector<chromosome_t>::iterator it;

		for (it = population.begin(); it != population.end(); ++it)
		{

			it->set_fitness(CalculateFitness(it->get_genes(), target));

			if(it->get_fitness() > 100.0f)
			{
				end = true;
			}
		}

		for (i = 0; i < POPULATION_SIZE; ++i)
		{
			string offspring1 = roulette_selection(&population, POPULATION_SIZE);
			string offspring2 = roulette_selection(&population, POPULATION_SIZE);
			
			crossover(CROSSOVER_RATE, &offspring1, &offspring2);

			mutate(MUTATION_RATE, &offspring1);
			mutate(MUTATION_RATE, &offspring2);

			chromosome_t chromo1(offspring1, 0);
			chromosome_t chromo2(offspring2, 0);

			tmp.push_back(chromo1);
			tmp.push_back(chromo2);
		}		

		population = tmp;

		
	}

	return 0;
}

float CalculateFitness(string genes, float target)
{
	float fitness;

	vector<int> decoded = DecodeGenes(genes);

	vector<int>::iterator i;	

	for (i = decoded.begin(); i != decoded.end(); ++i)
	{
		switch(*i)
		{
			case 10:
				fitness += decoded[*(++i)];
				break;

			case 11:
				fitness -= decoded[*(++i)];
				break;

			case 12:
				fitness *= decoded[*(++i)];
				break;

			case 13:
				fitness /= decoded[*(++i)];
				break;
		}
	}	

	if(fitness == target)
	{
		return 1000.0f;
	}
	else
	{
		fitness = 1 / (target - fitness);
	}

	return fitness;
}

vector<int> DecodeGenes(string genes)
{
	vector<int> decoded;
	bool operTime = true;
	int i;
	int curr_gene;

	for (i = 0; i < GENES_COUNT - 1; ++i)
	{
		curr_gene = BinToDec(genes.substr(i * GENE_LENGTH, GENE_LENGTH));

		if(operTime && curr_gene >= 10 && curr_gene < 14)
		{
			decoded.push_back(curr_gene);
		}
		else if(!operTime && curr_gene < 10)
		{
			decoded.push_back(curr_gene);
		}
	}

	return decoded;
}

int BinToDec(string binary)
{
	int numb = 0;
	int i;
	
	for (i = binary.length() - 1; i >= 0; --i)
	{
		if(binary[i] == '1')
		{
			numb += pow(2, (binary.length() - 1) - i);
		}
	}

	return numb;
}