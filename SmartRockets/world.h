#ifndef WORLD_H
#define WORLD_H

#include "rocket.h"

#define MAX_GENERATIONS 100
#define MUTATION_RATE 0.01
#define CROSSOVER_RATE 0.7

using namespace std;

class world_t
{
	vector<rocket_t> population;
	int generations;
	int population_size;

public:
	world_t(int, AGE_Engine*);
	void reset(AGE_Engine*);
	void load(AGE_Engine *);
	void update(AGE_Engine *);
	void draw(AGE_SpriteBatch *);
	void destroy();
};

#endif