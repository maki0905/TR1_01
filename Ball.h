#pragma once
#include "MathFunction.h"
#include "Vector2.h"

class Ball
{
public:

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(Vector2 pos, Vector2 radius, float weight, Vector2 speed);

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	Vector2 GetPosition() { return position_; }
	Vector2 GetRadius() { return radius_; }
	Vector2 GetSpeed() { return speed_; }
	void SetSpeed(Vector2 speed) { speed_ = speed; }

private:
	Vector2 position_;
	Vector2 radius_;
	float weight_;
	Vector2 speed_;
	float angle_;
};

