#pragma once
#include "Object.h"
class Bullet : public Object
{
public:
	Bullet();
	Bullet(float posX, float posY, int radius);
	~Bullet();
	bool isShot_ = false;

public:

	void Update()override;
	void Draw()override;

};

