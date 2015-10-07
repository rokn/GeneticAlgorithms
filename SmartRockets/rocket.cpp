#include "rocket.h"
#include "main.h"

float get_random_angle()
{
	return 360.0f * RANDOM_NUM;
}

rocket_t::rocket_t(AGE_Vector position, float new_speed)
	:rocket_t(DNA_t(get_random_angle, ROCKET_LIFETIME), position, new_speed){}

rocket_t::rocket_t(const DNA_t& new_dna, const AGE_Vector& new_position, float new_speed)
{
	this->dna = new DNA_t();
	this->dna = new_dna;
	this->position = new AGE_Vector();
	this->position = new_position;
	this->origin = new AGE_Vector();
	this->speed = new_speed;
}

void rocket_t::update()
{	
	*this->position = AGE_Helper_RotatedVectorMove(*this->position, this->rotation, this->speed);
}

DNA_t rocket_t::get_dna()
{
	return *this->dna;
}

void rocket_t::draw(AGE_SpriteBatch *spriteBatch)
{
	spriteBatch.Render(this->sprite, this->position, NULL, 1 this->rotation, this->origin, SDL_FLIP_NONE);
}

void rocket_t::destroy()
{
	delete this->position;
	delete this->dna;
	delete this->origin;
}