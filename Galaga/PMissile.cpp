#include "stdafx.h"
#include "pMissile.h"


using namespace sf;

pMissile::pMissile()
{
	// Player missile sprite and texture
	pMissileTexture.loadFromFile("graphics/player_missile.png");
	pMissileSprite.setTexture(pMissileTexture);

	// Set player missile origin to center of player sprite
	FloatRect pMissileRect = pMissileSprite.getLocalBounds();
	pMissileSprite.setOrigin(pMissileRect.left + pMissileRect.width / 2.0f,
		pMissileRect.top + pMissileRect.height / 2.0f);
}

void pMissile::setpMissileScale(float spriteScalingFactor)
{
	pMissileSprite.setScale(spriteScalingFactor, spriteScalingFactor);
}

void pMissile::initpMissilePosition(const float spriteScalingFactor, Vector2f windowDimensions)
{
	pMissilePosition.x = (pMissileRect.width / (2.0 / spriteScalingFactor));
	pMissilePosition.y = windowDimensions.y - pMissileRect.height / (2.0 / spriteScalingFactor);
	pMissileSprite.setPosition(pMissilePosition);
}

void pMissile::setpMissilePosition(float x, float y)
{
	pMissilePosition.x = x;
	pMissilePosition.y = y;
	pMissileSprite.setPosition(x, y);

}

Vector2f pMissile::getpMissilePosition()
{
	return pMissilePosition;
}

Sprite pMissile::getpMissileSprite()
{
	return pMissileSprite;
}

FloatRect pMissile::getpMissileRect()
{
	return pMissileRect;
}

int pMissile::getpMissileSpeed()
{
	return pMissileSpeed;
}

void pMissile::setpMissileFire(bool missileFire)
{
	pMissileFire = missileFire;
}
bool pMissile::getpMissileFire()
{
	return pMissileFire;
}

void pMissile::setPlayerYValue(float y)
{
	pMissilePosition.y -= y;
}

float pMissile::getPlayerYValue()
{
	return pMissilePosition.y;
}

float pMissile::getpMissileX()
{
	return pMissileX;
}

void pMissile::setpMissileX(float x)
{
	pMissileX = x;
}