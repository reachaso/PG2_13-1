#pragma once
#include "Object.h"
class Enemy : public Object
{

public:

	Enemy(float posX, float posY, int speed, int radius);
	~Enemy();

	static int isEnemy;
	void Update()override;
	void Draw()override;

};

