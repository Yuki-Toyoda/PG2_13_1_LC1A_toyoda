#include<Novice.h>
#include "Bullet.h"

Bullet::Bullet() {
	bullet = {
		{0, 0},
		10
	};
	bulletSpeed = 10;
	isShot = false;

}

void Bullet::Update() {
	if (isShot == true) {
		bullet.translate.y -= bulletSpeed;
	}

	if (bullet.translate.y < 0) {
		isShot = false;
	}

}

void Bullet::Draw() {
	if (isShot == true) {
		Novice::DrawEllipse(
			bullet.translate.x, bullet.translate.y,
			bullet.radius, bullet.radius, 0.0f,
			WHITE, kFillModeSolid
		);
	}
}

void Bullet::isHitEnemy(Enemy* enemy) {

	float b2eX = enemy->GetPosX() - bullet.translate.x;
	float b2eY = enemy->GetPosY() - bullet.translate.y;

	float length = sqrt(pow(b2eX, 2) + pow(b2eY, 2));

	if (length <= (enemy->GetRadius() / 2) + bullet.radius / 2) {

		bullet.translate = { 10000, 10000};
		isShot = false;
		enemy->isAlive = false;

	}

}