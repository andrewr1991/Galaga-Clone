// Galaga Clone
// Author: Andrew Ridout

#include "stdafx.h"
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "PlayerMissile.h"

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

	Player player;
	player.setPlayerScale(spriteScalingFactor);
	player.initPlayerPosition(spriteScalingFactor, windowDimensions);

	PlayerMissile playerMissile;
	playerMissile.setPlayerMissileScale(spriteScalingFactor);
	playerMissile.initPlayerMissilePosition(spriteScalingFactor, windowDimensions);

	float playerMissileYPosition = (windowDimensions.y - player.getPlayerRect().height / 2.0) - playerMissile.getPlayerMissileRect().height / 4.0;

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
			playerMissile.setPlayerMissileFire(true);
		}

		if (playerMissile.getPlayerMissilePosition().y < (0 - (playerMissile.getPlayerMissileRect().height / 4.0)))
		{
			playerMissile.setPlayerMissileFire(false);
			playerMissile.setPlayerMissilePosition(500, 850);
			playerMissileYPosition = (windowDimensions.y - player.getPlayerRect().height / 2.0) - playerMissile.getPlayerMissileRect().height / 4.0;
		}

		if (playerMissile.getPlayerMissileFire())
		{
			playerMissile.setPlayerMissilePosition(player.getPlayerPosition().x, playerMissileYPosition);
			playerMissileYPosition -= (playerMissile.getPlayerMissileSpeed() * dt.asSeconds());
		}

		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			player.movePlayerLeft(dt);
		}

		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			player.movePlayerRight(dt);
		}

		window.clear();
		window.draw(playerMissile.getPlayerMissileSprite());
		window.draw(player.getPlayerSprite());
		window.display();
	}

    return 0;
}

