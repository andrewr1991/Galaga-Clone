#include "stdafx.h"
#include "Player.h"


using namespace sf;

Player::Player()
{
	// Player sprite and texture
	playerTexture.loadFromFile("graphics/player.png");
	playerSprite.setTexture(playerTexture);

	// Set player origin to center of player sprite
	playerRect = playerSprite.getLocalBounds();
	playerSprite.setOrigin(playerRect.left + playerRect.width / 2.0f,
	                       playerRect.top + playerRect.height / 2.0f);
}

void Player::setPlayerScale(float spriteScalingFactor)
{
	playerSprite.setScale(spriteScalingFactor, spriteScalingFactor);
}

void Player::initPlayerPosition(const float spriteScalingFactor, Vector2f windowDimensions)
{
	playerPosition.x = (playerRect.width / (2.0 / spriteScalingFactor));
	playerPosition.y = windowDimensions.y - playerRect.height / (2.0 / spriteScalingFactor);
	playerSprite.setPosition(playerPosition);
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

void Player::movePlayerLeft(Time dt)
{
	playerPosition.x -= (playerSpeed * dt.asSeconds());
	playerSprite.setPosition(playerPosition);
}

void Player::movePlayerRight(Time dt)
{
	playerPosition.x += (playerSpeed * dt.asSeconds());
	playerSprite.setPosition(playerPosition);
}