#include "Enemy.h"

// コンストラクタ
Enemy::Enemy() {
	// 座標初期化
	posX_ = 640.0f;
	posY_ = 360.0f;

	// スピード初期化
	speedX_ = 5.0f;
	speedY_ = 0.0f;

	// 半径初期化
	radius_ = 20.0f;

	// 色初期化
	color_ = RED;
}

// 更新処理
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

// 描画
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
