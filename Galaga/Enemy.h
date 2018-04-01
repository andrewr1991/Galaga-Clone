#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

class Enemy
{
public:
	void setEnemyPosition(float x, float y);
	void setEnemyScale();
	Vector2f getEnemyPosition();
	void setEnemyTexture(String filePath, float spriteScalingFactor);
	Sprite getEnemySprite();

private:
	Sprite enemySprite;
	Texture enemyTexture;
	Vector2f enemyPosition;
	FloatRect enemyRect;
	const int enemySpeed = 300;
};