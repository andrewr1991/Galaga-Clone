#include "Player.h"
#include "stdafx.h"

using namespace sf;

Player::Player()
{
	// Player sprite and texture
	Sprite player;
	playerSprite = player;

	/*
	Texture playerTexture;
	playerTexture = playerTexture;

	playerTexture.loadFromFile("graphics/player.png");
	player.setTexture(playerTexture);

	// Set player origin to center of player sprite
	FloatRect playerRect = player.getLocalBounds();
	player.setOrigin(playerRect.left + playerRect.width / 2.0f,
		playerRect.top + playerRect.height / 2.0f);
		*/
}
/*
void Player::setPlayerScale()
{

	//player.setScale(spriteScalingFactor, spriteScalingFactor);
	
}

void Player::setPlayerPosition(Sprite playerSprite, float spriteScalingFactor, Vector2f windowDimensions)
{
	playerSprite.setPosition(playerRect.width / (2.0 / spriteScalingFactor), windowDimensions.y - playerRect.height / (2.0 / spriteScalingFactor));
}

Sprite Player::getPlayerSprite()
{
	return playerSprite;
}
*/