#include <iostream>
#include "chromo.h"

int main()
{
	chromosome_t chromosome("10101010", 50);
	std::cout << chromosome.get_genes();	
	return 0;
}