#include "stdafx.h"
#include "String"
#include "Enemy.h"

void Enemy::setEnemyTexture(String filePath, float spriteScalingFactor)
{
	enemyTexture.loadFromFile(filePath);
	enemySprite.setTexture(enemyTexture);

	// Set enemy origin to center of player sprite
	enemyRect = enemySprite.getLocalBounds();
	enemySprite.setOrigin(enemyRect.left + enemyRect.width / 2.0f,
		enemyRect.top + enemyRect.height / 2.0f);

	enemySprite.setScale(spriteScalingFactor, spriteScalingFactor);
}

Sprite Enemy::getEnemySprite()
{
	return enemySprite;
}

void Enemy::setEnemyPosition(float x, float y)
{
	enemySprite.setPosition(x, y);
}