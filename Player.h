#pragma once
#include "Object.h"
#include "Bullet.h"

class Player : public Object
{

	public:

		Player(float posX, float posY, int radius, int speed);
		~Player();
		
	public:
		Bullet Bullet_;
		void Draw()override;
		void Update(char* keys, char* preKeys);

};

