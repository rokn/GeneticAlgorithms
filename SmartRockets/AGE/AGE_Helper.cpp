#include "AGE.h"
#include "AGE_Graphics.h"

AGE_Vector AGE_Helper_RotatedVectorMove(AGE_Vector position, float rotation, float speed)
{
    position.AddX(speed * (float)cos(rotation));
    position.AddY(speed * (float)sin(rotation));
    return position;
}

float AGE_Helper_FindRotation(AGE_Vector position, AGE_Vector targetPosition)
{
	AGE_Vector place(targetPosition.GetX() - position.GetX(), targetPosition.GetY() - position.GetY());
	// printf("place:%f,%f\n",place.X,place.Y);
    float rotation = (float)atan2(place.GetY(), place.GetX());
	// printf("rotation:%f\n",rotation);
	rotation *= 180.0 / M_PI;
    return rotation;
}

AGE_Vector AGE_Helper_AngleToVector(float angle)
{
	AGE_Vector vector((float)cos(angle), (float)sin(angle));

	return vector;
}

AGE_Vector AGE_Helper_FindDirection(AGE_Vector position, AGE_Vector targetPosition)
{
	AGE_Vector dir = targetPosition.Subtract(position);
	dir = dir.Normalize();
	return dir;
}

AGE_Vector AGE_Helper_RectCenter(AGE_Rect rect)
{
	AGE_Vector center(rect.GetX() + rect.GetWidth()/2, rect.GetY() + rect.GetHeight()/2);	
	return center;
}