#include "Player.h"
#include <Novice.h>

Player::Player(float posX, float posY, int radius, int speed) {

	pos_.x = posX;
	pos_.y = posY;
	radius_ = radius;
	speed_ = speed;
	Bullet_ = Bullet(posX, posY, 5);

}


Player::~Player() {
	Bullet_.~Bullet();
};

void Player::Draw() {
	Novice::DrawEllipse((int)pos_.x, (int)pos_.y,radius_, radius_, 0.0f, WHITE, kFillModeSolid);
	Bullet_.Draw();
}


void Player::Update(char* keys, char* preKeys)
{

	if (keys[DIK_W]) {

		pos_.y -= speed_;

	}

	if (keys[DIK_A]) {

		pos_.x -= speed_;

	}
	if (keys[DIK_S]) {

		pos_.y += speed_;

	}
	if (keys[DIK_D]) {

		pos_.x += speed_;

	}

	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE] && !Bullet_.isShot_) {

		Bullet_.isShot_ = true;
		Bullet_.pos_.x = pos_.x;
		Bullet_.pos_.y = pos_.y;

	};

	Bullet_.Update();
}
