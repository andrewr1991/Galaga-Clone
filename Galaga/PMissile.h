#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class pMissile
{
public:
	pMissile();
	Vector2f getpMissilePosition();
	void setpMissileScale(float spriteScalingFactor);
	Sprite getpMissileSprite();
	FloatRect getpMissileRect();
	void initpMissilePosition(const float spriteScalingFactor, Vector2f windowDimensions);
	int getpMissileSpeed();
	void setpMissilePosition(float x, float y);
	void setpMissileFire(bool missileFire);
	bool getpMissileFire();
	void setPlayerYValue(float y);
	float getPlayerYValue();
	float getpMissileX();
	void setpMissileX(float x);

private:
	Sprite pMissileSprite;
	Texture pMissileTexture;
	int pMissileSpeed = 1000;
	Vector2f pMissilePosition;
	FloatRect pMissileRect;
	bool pMissileFire = false;
	float pMissileY = 0;
	float pMissileX = 0;
};