#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class PlayerMissile
{
private:
	Sprite playerMissileSprite;
	Texture playerMissileTexture;
	const int playerMissileSpeed = 1200;
	Vector2f playerMissilePosition;
	FloatRect playerMissileRect;
	bool playerMissileFire = false;
	float playerMissileY = 0;

public:
	PlayerMissile();
	Vector2f getPlayerMissilePosition();
	void setPlayerMissileScale(float spriteScalingFactor);
	Sprite getPlayerMissileSprite();
	FloatRect getPlayerMissileRect();
	void initPlayerMissilePosition(const float spriteScalingFactor, Vector2f windowDimensions);
	int getPlayerMissileSpeed();
	void setPlayerMissilePosition(float x, float y);
	void setPlayerMissileFire(bool missileFire);
	bool getPlayerMissileFire();
	void setPlayerYValue(float y);
	float getPlayerYValue();
};