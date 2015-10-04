#include <iostream>
#include <vector>
#include "GENETICS/chromo.h"
#include "GENETICS/genetics.h"
#include <time.h>
#include <stdlib.h>
#include <cmath>

#define POPULATION_SIZE 200
#define GENE_LENGTH 5
#define CROSSOVER_RATE 0.7f
#define MUTATION_RATE 0.01f
#define MAX_GENERATIONS 10000

using namespace std;

int GENES_COUNT;

float CalculateFitness(string, string);
string DecodeGenes(string);
int BinToDec(string);
void PrintSolution(string);
bool contains(string, char);

int main()
{
	srand(time(NULL));
	vector<chromosome_t> population;
	vector<chromosome_t> tmp;
	bool end = false;
	string target;
	int generations = 0;

	getline(cin, target);
	GENES_COUNT = target.length();	

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

			if(it->get_fitness() > 99999.0f)
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
			
			crossover_each(CROSSOVER_RATE, &offspring1, &offspring2, GENE_LENGTH);

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

float CalculateFitness(string genes, string target)
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
			fitness += 10;
		}
		else if (contains(target, decoded.at(i)))
		{
			fitness++;
		}
	}

	// PrintSolution(genes);
	// cout << "f" << fitness << endl;	

	return fitness;
}

string DecodeGenes(string genes)
{
	string decoded;
	
	int i;
	int curr_gene;

	for (i = 0; i < GENES_COUNT; ++i)
	{
		curr_gene = BinToDec(genes.substr(i * GENE_LENGTH, GENE_LENGTH));

		if(curr_gene < 26)
		{
			decoded.push_back('a' + curr_gene);			
		}
		else if(curr_gene == 27)
		{
			decoded.push_back(' ');
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

void PrintSolution(string genes)
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