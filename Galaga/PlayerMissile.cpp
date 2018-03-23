#include "stdafx.h"
#include "PlayerMissile.h"


using namespace sf;

PlayerMissile::PlayerMissile()
{
	// Player missile sprite and texture
	playerMissileTexture.loadFromFile("graphics/player_missile.png");
	playerMissileSprite.setTexture(playerMissileTexture);

	// Set player missile origin to center of player sprite
	FloatRect playerMissileRect = playerMissileSprite.getLocalBounds();
	playerMissileSprite.setOrigin(playerMissileRect.left + playerMissileRect.width / 2.0f,
		                          playerMissileRect.top + playerMissileRect.height / 2.0f);
}

void PlayerMissile::setPlayerMissileScale(float spriteScalingFactor)
{
	playerMissileSprite.setScale(spriteScalingFactor, spriteScalingFactor);
}

void PlayerMissile::initPlayerMissilePosition(const float spriteScalingFactor, Vector2f windowDimensions)
{
	playerMissilePosition.x = (playerMissileRect.width / (2.0 / spriteScalingFactor));
	playerMissilePosition.y = windowDimensions.y - playerMissileRect.height / (2.0 / spriteScalingFactor);
	playerMissileSprite.setPosition(playerMissilePosition);
}

void PlayerMissile::setPlayerMissilePosition(float x, float y)
{
	playerMissileSprite.setPosition(x, y);
}

Sprite PlayerMissile::getPlayerMissileSprite()
{
	return playerMissileSprite;
}

FloatRect PlayerMissile::getPlayerMissileRect()
{
	return playerMissileRect;
}

Vector2f PlayerMissile::getPlayerMissilePosition()
{
	return playerMissilePosition;
}

int PlayerMissile::getPlayerMissileSpeed()
{
	return playerMissileSpeed;
}

void PlayerMissile::setPlayerMissileFire(bool missileFire)
{
	playerMissileFire = missileFire;
}
bool PlayerMissile::getPlayerMissileFire()
{
	return playerMissileFire;
}