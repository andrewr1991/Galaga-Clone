// HelloSFML.cpp : Defines the entry point for the console application.
//

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





	while (window.isOpen())
	{
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		window.clear();
		window.draw(player);
		window.display();
	}

    return 0;
}

