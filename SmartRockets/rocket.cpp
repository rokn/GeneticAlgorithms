#include "rocket.h"
#include "main.h"

float get_random_angle()
{
	return 360.0f * RANDOM_NUM;
}

rocket_t::rocket_t(float new_speed)
	:rocket_t(DNA_t(get_random_angle, ROCKET_LIFETIME), AGE_Vector(35.0f), new_speed) {}

rocket_t::rocket_t(const AGE_Vector& new_position, float new_speed)
	:rocket_t(DNA_t(get_random_angle, ROCKET_LIFETIME), new_position, new_speed) {}

rocket_t::rocket_t(const DNA_t& new_dna, const AGE_Vector& new_position, float new_speed)
{
	this->dna = new DNA_t();
	*this->dna = new_dna;
	this->position = new AGE_Vector();
	*this->position = new_position;
	this->origin = new AGE_Vector();
	this->speed = new_speed;
	this->dna_update_timer = new AGE_Timer();
	this->sprite = new AGE_Sprite();
	this->lifetime = 0;

	this->change_rotation_by_dna();

	this->dna_update_timer->Start();
}

void rocket_t::load(AGE_Engine* engine)
{
	this->sprite->Load(engine, "Resources/rocket.png");
	this->origin->SetX(this->sprite->GetWidth()/2.0f);
	this->origin->SetY(this->sprite->GetHeight()/2.0f);
}

void rocket_t::update(AGE_Engine* engine)
{	
	this->update_timer();
	*this->position = AGE_Helper_RotatedVectorMove(*this->position, this->rotation, this->speed);
}

DNA_t* rocket_t::get_dna()
{
	return this->dna;
}

void rocket_t::draw(AGE_SpriteBatch* spriteBatch)
{
	spriteBatch->Render(this->sprite, this->position, NULL, DRAW_DEPTH_ROCKET, this->rotation, origin, SDL_FLIP_NONE);
}

void rocket_t::destroy()
{
	delete this->position;
	delete this->origin;
	delete this->dna;
	delete this->dna_update_timer;
	delete this->sprite;
}

void rocket_t::update_timer()
{
	if(this->dna_update_timer->GetTicks() >= ROCKET_TICK_TIME)
	{
		this->dna_update_timer->Reset();
		this->dna_update_timer->Start();
		change_rotation_by_dna();
	}
}

void rocket_t::change_rotation_by_dna()
{
	this->rotation = this->dna->get_genes().at(lifetime++);
}

int rocket_t::get_lifetime()
{
	return this->lifetime;
}

void rocket_t::calculate_fitness(const AGE_Vector& target)
{
	float distance = this->position->Distance(target);
	float fitness = 0;

	fitness = 1/(distance * distance);

	this->dna->set_fitness(1);
}

void rocket_t::mutate(float rate)
{
	this->dna->mutate(rate, get_random_angle);
}

void rocket_t::crossover(float rate, rocket_t *mate)
{
	this->dna->crossover(rate, mate->dna);
}