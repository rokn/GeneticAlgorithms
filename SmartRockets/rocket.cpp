#include "rocket.h"
#include "main.h"

float get_random_angle()
{
	return 360.0f * RANDOM_NUM;
}

rocket_t::rocket_t(float new_speed) 
{
	this->speed = new_speed;
	this->rotation = 0;
	this->position = new AGE_Vector(0.0f,0.0f);
	this->dna = new DNA_t(get_random_angle, ROCKET_LIFETIME);
}

rocket_t::rocket_t(DNA_t new_dna, AGE_Vector new_position, float new_speed)
{
	this->rotation = 0;
	this->dna = &new_dna;
	this->position = &new_position;
	this->speed = new_speed;
}

void rocket_t::update()
{	
	*this->position = AGE_Helper_RotatedVectorMove(*this->position, this->rotation, this->speed);
}

DNA_t rocket_t::get_dna()
{

}

void rocket_t::draw(AGE_SpriteBatch)
{

}

void rocket_t::destroy()
{
	delete this->position;
	delete this->dna;
}