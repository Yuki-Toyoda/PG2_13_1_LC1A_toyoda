#pragma once
#include <Novice.h>
class Enemy
{
public:

	Enemy();

	void Update();

	void Draw();

	void SetPos(float posX, float posY) { posX_ = posX, posY_ = posY; }

	float GetPosX() { return this->posX_; }
	float GetPosY() { return this->posY_; }

	float GetRadius() { return this->radius_; }

	static bool isAlive;

private:

	// 座標
	float posX_;
	float posY_;

	// スピード
	float speedX_;
	float speedY_;

	// 半径
	float radius_;

	// 色
	unsigned int color_;

};

