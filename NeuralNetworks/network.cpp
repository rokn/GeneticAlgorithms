#include "network.h"
#include <iostream>
#include "helper.h"
#include "main.h"

Network_t::Network_t(vector<int> layerSizes)
{
	this->layers = layerSizes.size();
	this->sizes = layerSizes;
	
	int i;
	int b;
	int c;

	for (i = 1; i < layers; ++i)
	{		
		vector<double> tmp;

		for (b = 0; b < sizes[i]; ++b)
		{
			tmp.push_back(RANDOM_NUM2);
		}

		this->biases.push_back(tmp);
	}

	for (i = 0; i < layers - 1; ++i)
	{
		vector<vector<double> > tmp;

		for (b = 0; b < sizes[i+1]; ++b)
		{
			vector<double> tmp2;

			
			for (c = 0; c < sizes[i]; ++c)
			{
				tmp2.push_back(RANDOM_NUM2);
			}

			tmp.push_back(tmp2);
		}

		this->weights.push_back(tmp);
	}

	generate_dna();
}

double Network_t::sigmoid(double z)
{	
	return 1.0 / (1.0 + exp(-z));
}

vector<double> Network_t::feed_forward(vector<double> a)
{
	int i;
	vector<double> tmp;
	
	for (i = 0; i < this->biases.size(); ++i)
	{
		tmp.clear();
		int j;
		
		for (j = 0; j < this->biases[i].size(); ++j)
		{
			tmp.push_back( sigmoid( dot_product( a, weights[i][j] ) + biases[i][j] ) );
		}

		a = tmp;
	}

	// for (i = 0; i < a.size() ; ++i)
	// {
	// 	if(a.at(i) < 0.1)
	// 	{
	// 		a.at(i) = 0;
	// 	}
	// 	else if(a.at(i) > 0.9)
	// 	{
	// 		a.at(i) = 1;
	// 	}
	// }

	return a;
}

void Network_t::generate_dna()
{
	vector<float> new_dna;

	int i,b,j;
	
	for (i = 0; i < weights.size(); ++i)
	{		
		for (j = 0; j < weights[i].size(); ++j)
		{
			for (b = 0; b < weights[i][j].size(); ++b)
			{
				new_dna.push_back(weights[i][j][b]);
			}
		}
	}

	for (i = 0; i < biases.size(); ++i)
	{				
		for (b = 0; b < biases[i].size(); ++b)
		{
			new_dna.push_back(biases[i][b]);
		}
	}

	dna = new DNA_t(new_dna, 0);
}

DNA_t Network_t::get_dna()
{
	return *dna;
}

void Network_t::update_dna(DNA_t new_dna)
{
	*dna = new_dna;
	int c = 0;
	int i,b,j;
	
	for (i = 0; i < weights.size(); ++i)
	{		
		for (j = 0; j < weights[i].size(); ++j)
		{
			for (b = 0; b < weights[i][j].size(); ++b)
			{
				weights[i][j][b] = new_dna.get_genes()[c++];
			}
		}
	}

	for (i = 0; i < biases.size(); ++i)
	{				
		for (b = 0; b < biases[i].size(); ++b)
		{
			biases[i][b] = new_dna.get_genes()[c++];
		}
	}
}

// [np.random.randn(y, x) for x, y in zip(sizes[:-1], sizes[1:])]

// [(3, 2), (2, 4)]

// [
// array([
// 		[ 0.25933943,  0.59855688,  0.49055744],
//        	[ 0.94602292, -0.8012292 ,  0.56352986]
//      ]), 
// array([
// 		[ 0.81328847, -0.53234407],
//     	[-0.272656  , -1.24978881],
//     	[-1.2306653 ,  0.56038948],
//     	[ 1.15837792,  1.19408038]
//     ])
// ]


