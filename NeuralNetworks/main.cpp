#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include "network.h"

using namespace std;

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	vector<int> layers;
	layers.push_back(3);
	layers.push_back(5);
	layers.push_back(5);
	layers.push_back(5);
	layers.push_back(5);
	layers.push_back(5);
	layers.push_back(5);
	layers.push_back(3);
	Network_t network(layers);

	vector<double> input;
	input.push_back(1);
	input.push_back(1);
	input.push_back(1);
	input = network.feed_forward(input);

	int i;
	
	for (i = 0; i < input.size(); ++i)
	{
		cout << input[i] << endl;
	}

	return 0;
}
































	// cout << "Layers : " << network.layers << endl;

	// cout << "biases.size : " << network.biases.size() << endl;
	// cout << "biases[0].size : " << network.biases.at(0).size() << endl;
	// cout << "biases[0][0] : " << network.biases.at(0).at(0) << endl;
	// cout << "biases[0][1] : " << network.biases.at(0).at(1) << endl;
	// cout << "biases[1].size : " << network.biases.at(1).size() << endl;
	// cout << "biases[1][0] : " << network.biases.at(1).at(0) << endl;
	// cout << "biases[1][1] : " << network.biases.at(1).at(1) << endl;
	// cout << "biases[1][2] : " << network.biases.at(1).at(2) << endl;
	// cout << "biases[1][3] : " << network.biases.at(1).at(3) << endl << endl;

	// cout << "weights.size : " << network.weights.size() << endl;
	// cout << "weights[0].size : " << network.weights.at(0).size() << endl;
	// cout << "weights[0][0].size : " << network.weights.at(0).at(0).size() << endl;
	// cout << "weights[0][0][0] : " << network.weights.at(0).at(0).at(0) << endl;
	// cout << "weights[0][0][1] : " << network.weights.at(0).at(0).at(1) << endl;
	// cout << "weights[0][0][2] : " << network.weights.at(0).at(0).at(2) << endl;
	// cout << "weights[0][1].size : " << network.weights.at(0).at(1).size() << endl;
	// cout << "weights[0][1][0] : " << network.weights.at(0).at(1).at(0) << endl;
	// cout << "weights[0][1][1] : " << network.weights.at(0).at(1).at(1) << endl;
	// cout << "weights[0][1][2] : " << network.weights.at(0).at(1).at(2) << endl;
	// cout << "weights[1].size : " << network.weights.at(1).size() << endl;
	// cout << "weights[1][0].size : " << network.weights.at(1).at(0).size() << endl;
	// cout << "weights[0][0][0] : " << network.weights.at(1).at(0).at(0) << endl;
	// cout << "weights[1][0][1] : " << network.weights.at(1).at(0).at(1) << endl;
	// cout << "weights[1][1].size : " << network.weights.at(1).at(1).size() << endl;
	// cout << "weights[1][1][0] : " << network.weights.at(1).at(1).at(0) << endl;
	// cout << "weights[1][1][1] : " << network.weights.at(1).at(1).at(1) << endl;
	// cout << "weights[1][2].size : " << network.weights.at(1).at(2).size() << endl;
	// cout << "weights[1][2][0] : " << network.weights.at(1).at(2).at(0) << endl;
	// cout << "weights[1][2][1] : " << network.weights.at(1).at(2).at(1) << endl;
	// cout << "weights[1][3].size : " << network.weights.at(1).at(3).size() << endl;
	// cout << "weights[1][3][0] : " << network.weights.at(1).at(3).at(0) << endl;
	// cout << "weights[1][3][1] : " << network.weights.at(1).at(3).at(1) << endl;