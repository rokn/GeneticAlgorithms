#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include <cmath>
#include <stdlib.h>
#include "dna.h"

#define RANDOM_WEIGHT (rand() % 255 + (-127))

using namespace std;

class Network_t
{	
	public:
	int layers;
	vector<int> sizes;
	vector< vector<double> > biases;
	vector< vector< vector <double> > > weights;
	DNA_t* dna;

	void generate_dna();


	Network_t(vector<int>);
	double sigmoid(double z);
	DNA_t get_dna();
	void update_dna(DNA_t);
	vector<double> feed_forward(vector<double> inputs);
};

#endif