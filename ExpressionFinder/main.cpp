#include <iostream>
#include <vector>
#include "GENETICS/chromo.h"
#include "GENETICS/genetics.h"
#include <time.h>
#include <stdlib.h>
#include <cmath>

#define POPULATION_SIZE 100
#define GENES_COUNT 30
#define GENE_LENGTH 4
#define CROSSOVER_RATE 0.7f
#define MUTATION_RATE 0.01f
#define MAX_GENERATIONS 1000

using namespace std;

float CalculateFitness(string, float);
vector<int> DecodeGenes(string);
int BinToDec(string);
void PrintSolution(string);

int main()
{
	srand(time(NULL));
	vector<chromosome_t> population;
	vector<chromosome_t> tmp;
	bool end = false;
	float target  = 0;
	int generations = 0;

	cin >> target;

	int i;
	
	for (i = 0; i < POPULATION_SIZE; ++i)
	{
		chromosome_t chromo(get_random_chromo(GENES_COUNT * GENE_LENGTH), 0);
		population.push_back(chromo);
	}

	while(!end)
	{
		generations ++;

		PrintSolution(population.front().get_genes());
		if(generations > MAX_GENERATIONS)
		{
			break;
		}

		tmp.clear();
		vector<chromosome_t>::iterator it;

		for (it = population.begin(); it != population.end(); ++it)
		{

			it->set_fitness(CalculateFitness(it->get_genes(), target));

			if(it->get_fitness() > 999.0f)
			{
				end = true;
				PrintSolution(it->get_genes());
				break;
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

float CalculateFitness(string genes, float target)
{
	float fitness = 0;

	vector<int> decoded = DecodeGenes(genes);

	if(decoded.empty())
	{
		return 0;
	}

	fitness = decoded.front();

	vector<int>::iterator i;	

	for (i = decoded.begin() + 1; i != decoded.end(); ++i)
	{		
		switch(*i)
		{
			case 10:
				fitness += *(++i);
				break;

			case 11:
				fitness -= *(++i);
				break;

			case 12:
				fitness *= *(++i);
				break;

			case 13:
				int numb = *(++i);

				if(numb != 0)
				{
					fitness /= numb;
				}
				else
				{
					return 0;
				}

				break;
		}
	}

	// PrintSolution(genes);
	// cout << "f" << fitness << endl;

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
	bool operTime = false;
	int i;
	int curr_gene;

	for (i = 0; i < GENES_COUNT - 1; ++i)
	{
		curr_gene = BinToDec(genes.substr(i * GENE_LENGTH, GENE_LENGTH));

		if(operTime && curr_gene >= 10 && curr_gene < 14)
		{
			decoded.push_back(curr_gene);
			operTime = false;
		}
		else if(!operTime && curr_gene < 10)
		{
			decoded.push_back(curr_gene);
			operTime = true;
		}
	}

	if(!decoded.empty() && decoded.size() % 2 == 0)
	{
		decoded.pop_back();
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

void PrintSolution(string genes)
{
	vector<int> decoded = DecodeGenes(genes);

	int i;
	
	for (i = 0; i < decoded.size(); ++i)
	{
		if(decoded[i] < 10)
		{
			cout << decoded[i];
		}
		else
		{
			switch(decoded[i])
			{
				case 10:
					cout << "+";
					break;

				case 11:
					cout << "-";
					break;

				case 12:
					cout << "*";
					break;

				case 13:
					cout << "/";
					break;
			}
		}

		cout << " ";
	}

	cout << endl;
}