#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
	delete model_;
}

void Enemy::Init(float i)
{

	transform = { { 0.1f,0.1f,0.1f},{0.0f,0.0f,0.0f},{0.0f + i,0.0f,3.0f} };
	modelData = texture_->LoadObjFile("resources", "plane.obj");

	model_ = new Model();
	model_->Initialize(modelData, transform);
}

void Enemy::Update()
{
	transform.translate.y += speed;

	if (transform.translate.y >= 2.0f) {
		speed *= -1;
	}
	if (transform.translate.y <= -2.0f) {
		speed *= -1;
	}

	model_->worldTransform_.translate = transform.translate;

}

void Enemy::Draw(Camera* camera, uint32_t index)
{
	model_->Draw(camera, index);
}

void Enemy::OnCollision()
{
}
