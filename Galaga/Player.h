#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Player
{
public:
	Player();
	Vector2f getPlayerPosition();
	void setPlayerScale(float spriteScalingFactor);
	Sprite getPlayerSprite();
	FloatRect getPlayerRect();
	void movePlayerLeft(Time dt);
	void movePlayerRight(Time dt);
	void initPlayerPosition(const float spriteScalingFactor, Vector2f windowDimensions);

private:
	Sprite playerSprite;
	Texture playerTexture;
	const int playerSpeed = 200;
	Vector2f playerPosition;
	FloatRect playerRect;
};