#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <cmath>
#include "chromo.h"
#include "genetics.h"

#define POPULATION_SIZE 300
#define GENE_LENGTH 5
#define CROSSOVER_RATE 0.7f
#define MUTATION_RATE 0.001f
#define MAX_GENERATIONS 10000

using namespace std;

int GENES_COUNT;

float CalculateFitness(chromosome_t<char>, string);
string DecodeGenes(chromosome_t<char>);
void PrintSolution(chromosome_t<char>);
bool contains(string, char);
char get_random_gene();

int main()
{	
	srand(time(NULL));
	vector<chromosome_t<char> > population;
	vector<chromosome_t<char> > tmp;
	bool end = false;
	string target;
	int generations = 0;

	getline(cin, target);
	GENES_COUNT = target.length();	

	int i;
	
	for (i = 0; i < POPULATION_SIZE; ++i)
	{
		chromosome_t<char> chromo(get_random_gene, GENES_COUNT);
		population.push_back(chromo);
	}

	while(!end)
	{
		generations ++;

		PrintSolution(population.front());
		if(generations > MAX_GENERATIONS)
		{
			break;
		}

		tmp.clear();
		vector<chromosome_t<char> >::iterator it;

		for (it = population.begin(); it != population.end(); ++it)
		{

			it->set_fitness(CalculateFitness(*it, target));

			if(it->get_fitness() > 99999.0f)
			{
				end = true;
				PrintSolution(*it);
				break;
			}
		}

		for (i = 0; i < POPULATION_SIZE; ++i)
		{
			chromosome_t<char> offspring1 = roulette_selection(&population, POPULATION_SIZE);
			chromosome_t<char> offspring2 = roulette_selection(&population, POPULATION_SIZE);
			
			offspring1.crossover(CROSSOVER_RATE, &offspring2);

			offspring1.mutate(MUTATION_RATE, get_random_gene);
			offspring2.mutate(MUTATION_RATE, get_random_gene);

			tmp.push_back(offspring1);
			tmp.push_back(offspring2);
		}		

		population = tmp;

		
	}

	if(generations <= MAX_GENERATIONS)
	{
		cout << "Found in " << generations << " generations!"<< endl;
	}
	else
	{
		cout << "The program could not find a solution in over " << MAX_GENERATIONS << " generations" << endl;
	}

	return 0;
}

float CalculateFitness(chromosome_t<char> genes, string target)
{
	float fitness = 0;

	string decoded = DecodeGenes(genes);

	if(decoded.empty())
	{
		return 0;
	}

	if(decoded == target)
	{
		return 100000.0f;
	}

	int i;
	
	for (i = 0; i < decoded.length(); ++i)
	{
		if(decoded.at(i) == target.at(i))
		{
			fitness += 5;
		}
		else if (contains(target, decoded.at(i)))
		{
			fitness++;
		}
	}

	fitness *= fitness;
	// PrintSolution(genes);
	// cout << "f" << fitness << endl;	

	return fitness;
}

string DecodeGenes(chromosome_t<char> genes)
{
	string decoded;
	
	int i;

	for (i = 0; i < GENES_COUNT; ++i)
	{
		decoded.push_back(genes.get_genes().at(i));
	}

	return decoded;
}

void PrintSolution(chromosome_t<char> genes)
{
	string decoded = DecodeGenes(genes);

	cout << decoded << endl;
}

bool contains(string str, char ch)
{
	int i;
	
	for (i = 0; i < str.length(); ++i)
	{
		if(ch == str.at(i))
		{
			return true;
		}
	}

	return false;
}


char get_random_gene()
{
	return (char)(rand() % 91 + 32);
}