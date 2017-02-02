#include "Shield.h"
#include "Ship.h"


void Shield::Update(Ship & ship)
{
	if (isActive)
	{
		if (newShield)
		{
			meterWidth = 300;
			newShield = false;
		}
		x = ship.GetX() + (ship.GetWidth() / 2);
		y = ship.GetY() + (ship.GetHeight() / 2);

		meterCounter++;
		if (meterCounter == meterDecrease)
		{
			meterCounter = 0;
			meterWidth--;
		}
		
		if (meterWidth <= 0)
		{
			isActive = false;
			newShield = true;
		}
		if (shieldSize < radius)
		{
			shieldSize += 5;
			holeSize += 5;
		}
	}
	
}

void Shield::Draw(Graphics& gfx)
{
	if (isActive)
	{
		gfx.DrawAnnulus(int(x), int(y), shieldSize, holeSize, c);
		DrawMeter(gfx);
	}
}

void Shield::DrawMeter(Graphics& gfx)
{
	gfx.DrawSquare(meterX, meterY, meterWidth, meterHeight, c);
}

bool Shield::GetisActive() const
{
	return isActive;
}

void Shield::SetisActive(bool active)
{
	isActive = active;
}

float Shield::GetX()
{
	return x;
}

float Shield::GetY()
{
	return y;
}

int Shield::GetSize()
{
	return radius;
}
