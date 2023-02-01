#pragma once
#include "Struct.h"
#include "Enemy.h"
#include <math.h>
class Bullet
{
public:
	Bullet();
	
	void Update();
	void Draw();

	void isHitEnemy(Enemy* enemy);

	Transform bullet;
	int bulletSpeed;
	bool isShot;

};

