#include "AGE.h"
#include "AGE_Graphics.h"

AGE_Vector::AGE_Vector():AGE_Vector(0){}

AGE_Vector::AGE_Vector(const AGE_Vector& obj)
{
	this->x = obj.x;
	this->y = obj.y;
}

AGE_Vector::AGE_Vector(float value):AGE_Vector(value, value) { }

AGE_Vector::AGE_Vector(float startX, float startY)
{
	this->x = startX;
	this->y = startY;
}

AGE_Vector 	AGE_Vector::Add(AGE_Vector v)
{
	AGE_Vector newVector;
	newVector.x = this->x + v.x;
	newVector.y = this->y + v.y;
	return newVector;
}

AGE_Vector AGE_Vector::Subtract(AGE_Vector v)
{
	AGE_Vector newVector;
	newVector.x = this->x - v.x;
	newVector.y = this->y - v.y;
	return newVector;
}

AGE_Vector AGE_Vector::Multiply(float value)
{
	AGE_Vector newVector;
	newVector.x = this->x * value;
	newVector.y = this->y * value;
	return newVector;
}

AGE_Vector AGE_Vector::Divide(float value)
{
	AGE_Vector newVector;
	newVector.x = this->x / value;
	newVector.y = this->y / value;
	return newVector;
}

float AGE_Vector::Distance(AGE_Vector v)
{
	float x = pow(v.x - this->x, 2);
	float y = pow(v.y - this->y, 2);
	return sqrt(x+y);
}

float AGE_Vector::Length()
{
	float x = pow(this->x, 2);
	float y = pow(this->y, 2);
	return sqrt(x+y);
}

AGE_Vector AGE_Vector::Normalize()
{
	return this->Divide(this->Length());
}

float AGE_Vector::GetX()
{
	return this->x;
}

void AGE_Vector::SetX(float newValue)
{
	this->x = newValue;
}

float AGE_Vector::GetY()
{
	return this->y;
}

void AGE_Vector::SetY(float newValue)
{
	this->y = newValue;
}

void AGE_Vector::AddX(float addValue)
{
	this->x += addValue;
}

void AGE_Vector::AddY(float addValue)
{
	this->y += addValue;
}