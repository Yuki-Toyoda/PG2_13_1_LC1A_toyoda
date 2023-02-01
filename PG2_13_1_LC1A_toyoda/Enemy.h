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

	// ���W
	float posX_;
	float posY_;

	// �X�s�[�h
	float speedX_;
	float speedY_;

	// ���a
	float radius_;

	// �F
	unsigned int color_;

};

