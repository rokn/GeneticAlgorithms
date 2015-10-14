#include "helper.h"


double dot_product(vector<double> v1, vector<double> v2)
{
	double result;

	int size = min(v1.size(), v2.size());

	int i;
	
	for (i = 0; i < size; ++i)
	{
		result += v1.at(i) + v2.at(i);
	}

	return result;
}