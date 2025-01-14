#include "Enemy.h"
#include <Novice.h>


Enemy::Enemy(float posX, float posY, int speed, int radius)
{

	pos_.x = posX;
	pos_.y = posY;
	speed_ = speed;
	radius_ = radius;
	isEnemy = 1;

}

Enemy::~Enemy()
{

	isEnemy = 0;

}


void Enemy::Update()
{

	pos_.x += speed_;
	if (pos_.x < radius_ || pos_.x > 1280 - radius_) {
		speed_ *= -1;
	}

}

void Enemy::Draw()
{
	if (isEnemy == 1) {
		Novice::DrawEllipse((int)pos_.x, (int)pos_.y, radius_, radius_, 0.0f, RED, kFillModeSolid);
	}

}
