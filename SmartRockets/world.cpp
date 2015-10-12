#include "world.h"
#include "genetics.h"
#include "AGE/AGE.h"

using namespace std;

world_t::world_t(int pop_size, AGE_Engine* engine)
{
	population_size = pop_size;
	this->generations = 1;
	
	int w,h;
	engine->GetDesktopResolution(w,h);
	AGE_Vector startPos(w/2.0f, h/2.0f);

	int i;
	
	for (i = 0; i < population_size; ++i)
	{
		this->population.push_back(rocket_t(startPos, 1.0f));
	}
}

void world_t::reset(AGE_Engine* engine)
{
	vector<rocket_t> tmp;

	int i;	

	this->generations ++;	

	if(generations > MAX_GENERATIONS)
	{
		cout << "Max generations reached";
		exit(1);
	}

	vector<rocket_t>::iterator it;

	for (it = this->population.begin(); it != this->population.end(); ++it)
	{		
		it->calculate_fitness(AGE_Vector(0,0));
	}

	for (i = 0; i < this->population_size; ++i)
	{
		rocket_t offspring1 = roulette_selection(&population, population_size);
		rocket_t offspring2 = roulette_selection(&population, population_size);
		
		cout << offspring1.get_dna()->get_genes().at(0) << endl;

		offspring1.crossover(CROSSOVER_RATE, &offspring2);

		offspring1.mutate(MUTATION_RATE);
		offspring2.mutate(MUTATION_RATE);

		tmp.push_back(offspring1);
		tmp.push_back(offspring2);
	}

	this->population.clear();
	this->population = tmp;

	this->load(engine);
}

void world_t::load(AGE_Engine *engine)
{
	for (std::vector<rocket_t>::iterator it = this->population.begin(); it != this->population.end(); ++it)
	{
		it->load(engine);
	}
}

void world_t::update(AGE_Engine *engine)
{
	bool clear = false;

	for (std::vector<rocket_t>::iterator it = this->population.begin(); it != this->population.end(); ++it)
	{
		it->update(engine);

		if(it->get_lifetime() >= ROCKET_LIFETIME)
		{
			it->destroy();
			clear = true;
		}
	}

	if(clear)
	{
		this->reset(engine);		
	}
}

void world_t::draw(AGE_SpriteBatch *spriteBatch)
{
	for (std::vector<rocket_t>::iterator it = this->population.begin(); it != this->population.end(); ++it)
	{
		it->draw(spriteBatch);
	}
}

void world_t::destroy()
{
	for (std::vector<rocket_t>::iterator it = this->population.begin(); it != this->population.end(); ++it)
	{
		it->destroy();
	}

	this->population.clear();
}