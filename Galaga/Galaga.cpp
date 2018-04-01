// Galaga Clone
// Author: Andrew Ridout

#include "stdafx.h"
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "PMissile.h"
#include "Enemy.h"

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

	pMissile pMissile[6];
	int pMissileCounter = 0;

	float pMissileYPosition = (windowDimensions.y - player.getPlayerRect().height / 2.0) - pMissile[0].getpMissileRect().height / 4.0;

	Enemy enemy;
	enemy.setEnemyTexture("graphics/yellow_blue_enemy.png", spriteScalingFactor);
	enemy.setEnemyPosition(500, 500);

	for (int i = 0; i < 6; i++)
	{
		pMissile[i].setpMissileScale(spriteScalingFactor);
		pMissile[i].initpMissilePosition(spriteScalingFactor, windowDimensions);
		pMissile[i].setpMissileFire(false);
	}

	Time gameTimeTotal;
	Time lastPressed;

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
			if (gameTimeTotal.asMilliseconds() - lastPressed.asMilliseconds() > 400)
			{
				pMissile[pMissileCounter].setpMissileFire(true);
				pMissile[pMissileCounter].setpMissileX(player.getPlayerPosition().x);
				
				pMissileCounter++;
				lastPressed = gameTimeTotal;
			}

			if (pMissileCounter >= 6)
			{
				pMissileCounter = 0;
			}
		}

		for (int i = 0; i < 6; i++)
		{
			if (pMissile[i].getpMissileFire())
			{
				pMissile[i].setpMissilePosition(pMissile[i].getpMissileX(), pMissile[i].getPlayerYValue());
				pMissile[i].setPlayerYValue(pMissile[i].getpMissileSpeed() * dt.asSeconds());
			}

			if (pMissile[i].getpMissilePosition().y < (0 - (pMissile[pMissileCounter].getpMissileRect().height / 4.0)))
			{
				pMissile[i].setpMissileFire(false);
				pMissile[i].setpMissilePosition(500, 850);
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
			if (pMissile[i].getpMissileFire())
			{
				window.draw(pMissile[i].getpMissileSprite());
			}
		}
		window.draw(player.getPlayerSprite());
		window.draw(enemy.getEnemySprite());
		window.display();
	}

	return 0;
}