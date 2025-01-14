#pragma once
#include <Vector2.h>

class Object
{

public:

	Vector2 pos_;
	int speed_;
	int radius_;

public:

	virtual void Update();
	virtual void Draw();


};

