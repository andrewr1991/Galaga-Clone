// Galaga Clone
// Author: Andrew Ridout

#include "stdafx.h"
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "PlayerMissile.h"

using namespace sf;
using namespace std;

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

	PlayerMissile playerMissile[6];
	int playerMissileCounter = 0;

	float playerMissileYPosition = (windowDimensions.y - player.getPlayerRect().height / 2.0) - playerMissile[0].getPlayerMissileRect().height / 4.0;

	for (int i = 0; i < 6; i++)
	{
		playerMissile[i].setPlayerMissileScale(spriteScalingFactor);
		playerMissile[i].initPlayerMissilePosition(spriteScalingFactor, windowDimensions);
		playerMissile[i].setPlayerMissileFire(false);
	}

	Time gameTimeTotal;
	Time lastPressed;

	float playerMissileX = 0.0;

	Clock clock;

	while (window.isOpen())
	{
		Time dt = clock.restart();
		gameTimeTotal += dt;

		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			if (gameTimeTotal.asMilliseconds() - lastPressed.asMilliseconds() > 250)
			{
				playerMissile[playerMissileCounter].setPlayerMissileFire(true);
				playerMissileX = player.getPlayerPosition().x;
				playerMissileCounter++;
				lastPressed = gameTimeTotal;
			}

			if (playerMissileCounter >= 6)
			{
				playerMissileCounter = 0;
			}
		}

		for (int i = 0; i < 6; i++)
		{
			if (playerMissile[i].getPlayerMissileFire())
			{
				playerMissile[i].setPlayerMissilePosition(playerMissileX, playerMissile[i].getPlayerYValue());
				playerMissile[i].setPlayerYValue(playerMissile[i].getPlayerMissileSpeed() * dt.asSeconds());
			}

			if (playerMissile[i].getPlayerMissilePosition().y < (0 - (playerMissile[playerMissileCounter].getPlayerMissileRect().height / 4.0)))
			{
				playerMissile[i].setPlayerMissileFire(false);
				playerMissile[i].setPlayerMissilePosition(500, 850);
			}
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

		for (int i = 0; i < 6; i++)
		{
			if (playerMissile[i].getPlayerMissileFire())
			{
				window.draw(playerMissile[i].getPlayerMissileSprite());
			}
		}
		
		window.draw(player.getPlayerSprite());
		window.display();
	}

    return 0;
}

