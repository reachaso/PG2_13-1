#include "Bullet.h"
#include <Novice.h>

Bullet::Bullet()
{
}

Bullet::Bullet(float posX, float posY, int radius) {

	pos_.x = posX;
	pos_.y = posY;
	radius_ = radius;

}

Bullet::~Bullet() {};


void Bullet::Draw() {

	if (isShot_) {
		Novice::DrawEllipse((int)pos_.x, (int)pos_.y, (int)radius_, (int)radius_, 0.0f, GREEN, kFillModeSolid);
	}
}

void Bullet::Update() {

	if (isShot_) {
		pos_.y -= 8;
	}

	if (pos_.y < 0) {
		isShot_ = false;
	}
}