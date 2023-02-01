#include "Enemy.h"

// �R���X�g���N�^
Enemy::Enemy() {
	// ���W������
	posX_ = 640.0f;
	posY_ = 360.0f;

	// �X�s�[�h������
	speedX_ = 5.0f;
	speedY_ = 0.0f;

	// ���a������
	radius_ = 20.0f;

	// �F������
	color_ = RED;
}

// �X�V����
void Enemy::Update() {

	if (isAlive == true) {
		posX_ += speedX_;
		posY_ += speedY_;
	}

	if (posX_ + radius_ > 1280.0f) {
		speedX_ *= -1.0f;
	}
	else if (posX_ - radius_ < 0.0f) {
		speedX_ *= -1.0f;
	}

	if (posY_ - radius_ > 720.0f) {
		speedY_ *= -1.0f;
	}
	else if (posY_ + radius_ < 0.0f) {
		speedY_ *= -1.0f;
	}
}

// �`��
void Enemy::Draw() {
	if (isAlive == true) {
		Novice::DrawEllipse(
			posX_, posY_,
			radius_, radius_,
			0.0f,
			color_,
			kFillModeSolid
		);
	}
}
