#include "AGE.h"
#include "AGE_Graphics.h"

AGE_Rect::AGE_Rect():AGE_Rect(0,0){}

AGE_Rect::AGE_Rect(int startX, int startY):AGE_Rect(startX, startY, 0, 0){}

AGE_Rect::AGE_Rect(int startX, int startY, int startWidth, int startHeight)
{
    this->x = startX;
    this->y = startY;
    this->width = startWidth;
    this->height = startHeight;
}

void AGE_Rect::SetPosition(int x, int y)
{
	this->x = x;
	this->y = y;
}

bool AGE_Rect::Intersects(AGE_Rect rect)
{
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    leftA = this->x;
    rightA = this->x + this->width;
    topA = this->y;
    bottomA = this->y + this->height;

    leftB = rect.x;
    rightB = rect.x + rect.width;
    topB = rect.y;
    bottomB = rect.y + rect.height;

    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }

    return true;
}

void AGE_Rect::Print()
{
    printf("AGE_Rect: {x:%d, y:%d, Width:%d, height:%d}\n", this->x, this->y, this->width, this->height);
}

bool AGE_Rect::Contains(AGE_Vector point)
{
    int left;
    int right;
    int top;
    int bottom;

    left = this->x;
    right = this->x + this->width;
    top = this->y;
    bottom = this->y + this->height;

    if(point.GetX() < left || point.GetX() > right)
    {
        return false;
    }

    if(point.GetY() < top || point.GetY() > bottom)
    {
        return false;
    }

    return true;
}

bool AGE_Rect::Contains(AGE_Rect rect)
{
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    leftA = this->x;
    rightA = this->x + this->width;
    topA = this->y;
    bottomA = this->y + this->height;

    leftB = rect.x;
    rightB = rect.x + rect.width;
    topB = rect.y;
    bottomB = rect.y + rect.height;

    if(leftB > leftA && rightB < rightA && topB > topA && bottomB < bottomA)
    {
        return true;
    }
    
    return false;
}

int AGE_Rect::GetX()
{
    return this->x;
}

void AGE_Rect::SetX(int newX)
{
    this->x = newX;
}

int AGE_Rect::GetY()
{
    return this->y;
}

void AGE_Rect::SetY(int newY)
{
    this->y = newY;
}

int AGE_Rect::GetWidth()
{
    return this->width;
}

void AGE_Rect::SetWidth(int newWidth)
{
    this->width = newWidth;
}

int AGE_Rect::GetHeight()
{
    return this->height;
}

void AGE_Rect::SetHeight(int newHeight)
{
    this->height = newHeight;
}