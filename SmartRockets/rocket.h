#ifndef ROCKET_H
#define ROCKET_H

#include "dna.h"
#include "AGE/AGE.h"
#include "AGE/AGE_Graphics.h"

#define ROCKET_LIFETIME 3
#define ROCKET_TICK_TIME 1000

class rocket_t
{
	DNA_t* dna;
	float speed;
	float rotation;
	AGE_Vector* position;
	AGE_Vector* origin;
	AGE_Timer* dna_update_timer;
	AGE_Sprite* sprite;
	int lifetime;

	void update_timer();
	void change_rotation_by_dna();
public:
	rocket_t(float);
	rocket_t(const AGE_Vector&, float);
	rocket_t(const DNA_t& ,const AGE_Vector& , float);
	void load(AGE_Engine*);
	void update(AGE_Engine*);
	DNA_t* get_dna();
	void mutate(float);
	void crossover(float, rocket_t*);
	int get_lifetime();
	void calculate_fitness(const AGE_Vector&);
	void draw(AGE_SpriteBatch*);
	void destroy();
};

#endif 
//ROCKET_H