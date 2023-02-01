#include "Player.h"

Player::Player() {

	player = {
		{640, 360},
		30
	};

	playerSpeed = 5;
}

void Player::Update(char* keys, char* preKeys) {
	if (keys[DIK_W]) {
		player.translate.y -= playerSpeed;
	}
	if (keys[DIK_A]) {
		player.translate.x -= playerSpeed;
	}
	if (keys[DIK_S]) {
		player.translate.y += playerSpeed;
	}
	if (keys[DIK_D]) {
		player.translate.x += playerSpeed;
	}

	for (int i = 0; i < 10; i++) {
		if (bullet_[i].isShot == false) {
			if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
				bullet_[i].bullet.translate.x = player.translate.x;
				bullet_[i].bullet.translate.y = player.translate.y;
				bullet_[i].isShot = true;
				break;
			}
		}
	}

}

void Player::Draw() {
	Novice::DrawEllipse(
		player.translate.x, player.translate.y,
		player.radius, player.radius, 0.0f,
		BLUE, kFillModeSolid
	);
}
