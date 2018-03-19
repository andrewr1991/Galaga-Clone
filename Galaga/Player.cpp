#include "stdafx.h"
#include "Player.h"


using namespace sf;

Player::Player()
{
	// Player sprite and texture
	playerTexture = playerTexture;
	playerTexture.loadFromFile("graphics/player.png");
	playerSprite.setTexture(playerTexture);

	// Set player origin to center of player sprite
	FloatRect playerRect = playerSprite.getLocalBounds();
	playerSprite.setOrigin(playerRect.left + playerRect.width / 2.0f,
	playerRect.top + playerRect.height / 2.0f);
}

void Player::setPlayerScale(float spriteScalingFactor)
{
	playerSprite.setScale(spriteScalingFactor, spriteScalingFactor);

}

void Player::setPlayerPosition(const float spriteScalingFactor, Vector2f windowDimensions)
{
	playerSprite.setPosition(500, 500); //playerRect.width / (2.0 / spriteScalingFactor), windowDimensions.y - playerRect.height / (2.0 / spriteScalingFactor));
}

Sprite Player::getPlayerSprite()
{
	return playerSprite;
}

FloatRect Player::getPlayerRect()
{
	return playerRect;
}

Vector2f Player::getPlayerPosition()
{
	return playerPosition;
}