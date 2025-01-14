#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "Player.h"
#include "Enemy.h"

int Enemy::isEnemy;

const char kWindowTitle[] = "LC1B_04_オオシマ_タイガ_13-1";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	float a;
	float b;
	float c;

	Player* player = new Player(450, 450, 10, 10);

	Enemy* enemies[2];

	enemies[0] = new Enemy(100, 200, 4, 20);
	enemies[1] = new Enemy(450, 300, 6, 20);
	
	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///


		for (int i = 0; i < 2; i++) {

			a = static_cast<float>(enemies[i]->pos_.x - player->Bullet_.pos_.x);
			b = static_cast<float>(enemies[i]->pos_.y - player->Bullet_.pos_.y);

		}

		c = sqrtf(a * a + b * b);

		for (int i = 0; i < 2; i++) {

			if (c < enemies[i]->radius_ + player->Bullet_.radius_) {

				player->Bullet_.isShot_ = false;
				Enemy::isEnemy = false;
			}

			if (Enemy::isEnemy) {
				enemies[i]->Update();
			}
		}

		player->Update(keys,preKeys);

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		for (int i = 0; i < 2; i++) {
			if (Enemy::isEnemy) {
				enemies[i]->Draw();
			}
		}

		player->Draw();

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	delete player;
	delete enemies[0];
	delete enemies[1];

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
