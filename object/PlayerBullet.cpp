#include "PlayerBullet.h"

PlayerBullet::PlayerBullet()
{
}

PlayerBullet::~PlayerBullet()
{
	delete model_;
}

void PlayerBullet::Init(Vector3 pos)
{
	transform = { { 0.03f,0.03f,0.1f},{0.0f,0.0f,0.0f},{pos.x,pos.y,pos.z} };
	modelData = texture_->LoadObjFile("resources", "cube.obj");

	model_ = new Model();
	model_->Initialize(modelData, transform);
}

void PlayerBullet::Update()
{

	transform.translate.z += 1.0f;

	model_->worldTransform_.translate = transform.translate;

	// 時間経過でデス
	if (--deathTimer_ <= 0) {
		isDead_ = true;
	}
}

void PlayerBullet::Draw(Camera* camera, uint32_t index)
{
	model_->Draw(camera, index);
}
