#include "AGE.h"
#include "AGE_Graphics.h"
#include "AGE_Input.h"

AGE_Camera::AGE_Camera(AGE_Vector offset)
{
	this->Offset = new AGE_Vector(Offset->GetX(), Offset->GetY());
	this->velocity = new AGE_Vector;
	this->focusRect = new AGE_Rect;
}

void AGE_Camera::SetTransform(AGE_Vector v)
{
	*this->Offset = v;
	AGE_ViewRect.SetX(this->Offset->GetX());
	AGE_ViewRect.SetY(this->Offset->GetY());
	
}

void AGE_Camera::ChangeTransform(AGE_Vector v)
{
	*this->Offset = this->Offset->Add(v);
	AGE_ViewRect.SetX(this->Offset->GetX());
	AGE_ViewRect.SetY(this->Offset->GetY());
	// AGE_Mouse.TransformedPosition.GetX() = AGE_Mouse.Position.x + this->Offset->GetX();
	// AGE_Mouse.TransformedPosition.GetY() = AGE_Mouse.Position.y + this->Offset->GetY();
	this->IsFocusing = false;
}

AGE_Vector AGE_Camera::GetOffsetMousePosition(AGE_Mouse *mouse)
{
	AGE_Vector pos(mouse->GetPosition().GetX() + this->Offset->GetX(), mouse->GetPosition().GetY() + this->Offset->GetY());
	return pos;
}

AGE_Vector AGE_Camera::GetOffset()
{
	return *this->Offset;
}

void AGE_Camera::Update()
{
	if(this->IsFocusing)
	{
		*this->velocity = this->velocity->Multiply(this->focusMultiplier);

		if(AGE_ViewRect.Contains(*this->focusRect))
		{
			this->IsFocusing = false;
		}		
	}
	else
	{
		if(this->velocity->Length() > 1)
		{
			*this->velocity = this->velocity->Divide(1.2);
		}
		else if(this->velocity->Length() > 0)
		{
			this->velocity->SetX(0);
			this->velocity->SetY(0);
		}	
	}

	*this->Offset = this->Offset->Add(*this->velocity);		
}

void AGE_Camera::FocusOn(AGE_Rect focusRect, float multiplier)
{
	if(AGE_ViewRect.Contains(focusRect))
	{
		return;
	}
	
	this->focusMultiplier = multiplier;
	*this->focusRect = focusRect;
	this->IsFocusing = true;
	AGE_Vector viewCenter = AGE_Helper_RectCenter(AGE_ViewRect);
	AGE_Vector targetCenter = AGE_Helper_RectCenter(focusRect);
	*this->velocity = AGE_Helper_FindDirection(viewCenter, targetCenter);
	*this->velocity = this->velocity->Multiply(2);
}