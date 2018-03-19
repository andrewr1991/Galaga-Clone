#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Player
{
private:
	Sprite playerSprite;

	Texture playerTexture;
	const int playerSpeed = 100;
	Vector2f playerPosition;
	FloatRect playerRect;

public:
	Player();

	Vector2f getPlayerPosition();
	void setPlayerScale(float spriteScalingFactor);
	void setPlayerPosition(const float spriteScalingFactor, Vector2f windowDimensions);
	Sprite getPlayerSprite();
	FloatRect getPlayerRect();
};