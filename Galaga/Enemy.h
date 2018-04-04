#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

class Enemy
{
public:
	void setEnemyPosition(float x, float y);
	void setEnemyScale();
	void setEnemyTexture(String filePath, float spriteScalingFactor);
	Sprite getEnemySprite();
	const int getEnemySpeed();
	FloatRect getEnemyRect();
	int getEnemyHealth();

private:
	Sprite enemySprite;
	Texture enemyTexture;
	Vector2f enemyPosition;
	FloatRect enemyRect;
	const int enemySpeed = 150;
	int enemyHealth = 100;
};