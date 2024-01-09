#pragma once
#include "TextureManager.h"
#include "Model.h"
#include "WorldTransform.h"
#include "Camera.h"


class Enemy {
public:
	Enemy();
	~Enemy();

	void Init(float i);
	void Update();
	void Draw(Camera* camera, uint32_t index);

	void OnCollision();

private:
	Model* model_;
	TextureManager* texture_ = TextureManager::GetInstance();
	WorldTransform worldTransform_;

	ModelData modelData;
	Transform transform;

	float speed = 0.02f;
};
