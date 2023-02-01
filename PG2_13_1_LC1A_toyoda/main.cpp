#include <Novice.h>
#include "Player.h"
#include "Enemy.h"

/*********************************
	定数宣言ここから
*********************************/

/******** ウィンドウ名の設定 **********/
const char kWindowTitle[] = "LC1A_16_トヨダユウキ_課題";

/******** ウィンドウサイズの指定 **********/
const int kWindowWidth = 1280; //x
const int kWindowHeight = 720; //y

/*********************************
	定数宣言ここまで
*********************************/

bool Enemy::isAlive = true;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	/*********************************
		変数宣言ここから
	*********************************/

	Player* player = new Player();
	Enemy* enemy[2];
	for (int i = 0; i < 2; i++) {
		enemy[i] = new Enemy;
	}

	enemy[0]->SetPos(640, 250);
	enemy[1]->SetPos(750, 100);

	/*********************************
		変数宣言ここまで
	*********************************/

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		/*********************************
			更新処理ここから
		*********************************/

		player->Update(keys, preKeys);
		for (int i = 0; i < 10; i++) {
			player->bullet_[i].Update();
			for (int j = 0; j < 2; j++) {
				player->bullet_[i].isHitEnemy(enemy[j]);
			}
		}

		for (int i = 0; i < 2; i++) {
			enemy[i]->Update();
		}

		if (keys[DIK_R] && preKeys[DIK_R]) {
			Enemy::isAlive = true;
		}

		/*********************************
			更新処理ここまで
		*********************************/

		/*********************************
			描画処理ここから
		*********************************/

		player->Draw();
		for (int i = 0; i < 10; i++) {
			player->bullet_[i].Draw();
		}

		for (int i = 0; i < 2; i++) {
			enemy[i]->Draw();

			Novice::ScreenPrintf(0, 20 * i, "enemy%d isAlive = %d", i, enemy[i]->isAlive);
			Novice::ScreenPrintf(0, 40, "WASD : player Move");
			Novice::ScreenPrintf(0, 60, "SPACE : shot");
			Novice::ScreenPrintf(0, 80, "R : enemy Respawn");

		}

		/*********************************
			描画処理ここまで
		*********************************/

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
