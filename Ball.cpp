#include "Ball.h"
#include "Novice.h"

void Ball::Initialize(Vector2 pos, Vector2 radius, float weight, Vector2 speed) {
	position_ = pos;
	radius_ = radius;
	weight_ = weight;
	speed_ = speed;
	angle_ = 0.0f;
}

void Ball::Update() {
	position_ = Add(position_, speed_);
	if (position_.x < radius_.x || position_.x > 1280.0f - radius_.x) {
		speed_.x *= -1;
	}
	if (position_.y < radius_.y || position_.y > 720.0f - radius_.y) {
		speed_.y *= -1;
	}
}

void Ball::Draw() {
	Novice::DrawEllipse(int(position_.x), int(position_.y), int(radius_.x), int(radius_.y), angle_, WHITE, kFillModeSolid);
}

