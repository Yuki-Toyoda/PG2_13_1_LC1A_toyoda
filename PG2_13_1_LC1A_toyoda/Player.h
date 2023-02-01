#pragma once
#include <Novice.h>
#include "Struct.h"
#include "Bullet.h"

class Player
{
public:

	Player();

	void Update(char* keys, char* preKeys);
	void Draw();

	Transform player;
	int playerSpeed;

	Bullet bullet_[10];

};



