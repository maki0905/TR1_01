#include <Novice.h>
#include "Ball.h"
#include <math.h>

const char kWindowTitle[] = "LE1A_16_マキユキノリ_タイトル";

bool Collision(Vector2 pos1, Vector2 radius1,Vector2 pos2, Vector2 radius2);

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	Ball* ball1 = new Ball();
	Ball* ball2 = new Ball();
	ball1->Initialize({ 300.0f, 360.0f }, { 50.0f, 50.0f }, 0.0f, { 10.0f, 10.0f });
	ball2->Initialize({ 700.0f, 360.0f }, { 50.0f, 50.0f }, 0.0f, { -10.0f, -10.0f });

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
		ball1->Update();
		ball2->Update();

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		ball1->Draw();
		ball2->Draw();
		if (Collision(ball1->GetPosition(), ball1->GetRadius(), ball2->GetPosition(), ball2->GetRadius())) {
			ball1->SetSpeed(Multiply(-1.0f, ball1->GetSpeed()));
			ball2->SetSpeed(Multiply(-1.0f, ball2->GetSpeed()));
		}
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

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}

bool Collision(Vector2 pos1, Vector2 radius1, Vector2 pos2, Vector2 radius2) {
	float a = pos2.x - pos1.x;
	float b = pos2.y - pos1.y;
	float c = sqrtf(a * a + b * b);

	if (c <= radius1.x + radius2.x) {
		return true;
	}
	else if (c <= radius1.y + radius2.y) {
		return true;
	}
	
	return false;
}