// Galaga Clone
// Author: Andrew Ridout

#include "stdafx.h"
#include "SFML/Graphics.hpp"

using namespace sf;

int main()
{
	// Window variables
	Vector2f windowDimensions;
	windowDimensions.x = 1000;
	windowDimensions.y = 800;

	VideoMode vm(windowDimensions.x, windowDimensions.y);
	RenderWindow window(vm, "Galaga");

	const float spriteScalingFactor = 0.5;

	// Player sprite and texture
	Sprite player;
	Texture playerTexture;
	playerTexture.loadFromFile("graphics/player.png");
	player.setTexture(playerTexture);

	// Set player origin to center of player sprite
	FloatRect playerRect = player.getLocalBounds();
	player.setOrigin(playerRect.left + playerRect.width / 2.0f,
					 playerRect.top + playerRect.height / 2.0f);

	player.setScale(spriteScalingFactor, spriteScalingFactor);
	player.setPosition(playerRect.width / (2.0 / spriteScalingFactor), windowDimensions.y - playerRect.height / (2.0 / spriteScalingFactor));

	// Player missile sprite and texture
	Sprite playerMissile;
	Texture playerMissileTexture;
	playerMissileTexture.loadFromFile("graphics/player_missile.png");
	playerMissile.setTexture(playerMissileTexture);

	// Set player missile origin to center of player sprite
	FloatRect playerMissileRect = playerMissile.getLocalBounds();
	playerMissile.setOrigin(playerMissileRect.left + playerMissileRect.width / 2.0f,
							playerMissileRect.top + playerMissileRect.height / 2.0f);

	playerMissile.setScale(spriteScalingFactor, spriteScalingFactor);
	bool playerMissileFire = false;
	const int missileSpeed = 1200;
	float playerMissileYPosition = (windowDimensions.y - playerRect.height / 2.0) - playerMissileRect.height / 4.0;

	Clock clock;

	while (window.isOpen())
	{
		Time dt = clock.restart();

		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			playerMissileFire = true;
		}

		if (playerMissileFire)
		{
			playerMissile.setPosition(player.getPosition().x, playerMissileYPosition);
			playerMissileYPosition -= (missileSpeed * dt.asSeconds());
		}

		window.clear();
		window.draw(player);
		window.draw(playerMissile);
		window.display();
	}

    return 0;
}

