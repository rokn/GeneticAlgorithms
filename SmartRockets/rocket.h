#ifndef ROCKET_H
#define ROCKET_h

#include "dna.h"
#include "AGE/AGE.h"
#include "AGE/AGE_Graphics.h"

#define ROCKET_LIFETIME 10

class rocket_t
{
	DNA_t* dna;
	float speed;
	float rotation;
	AGE_Vector* position;

public:
	rocket_t(float);
	rocket_t(DNA_t ,AGE_Vector , float);
	void update();
	DNA_t get_dna();
	void draw(AGE_SpriteBatch);
	void destroy();
};

#endif 
//ROCKET_H