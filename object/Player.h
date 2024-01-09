#pragma once
#include "TextureManager.h"
#include "Model.h"
#include "WorldTransform.h"
#include "Camera.h"
#include "Input.h"
#include "PlayerBullet.h"

#include <list>

class Player {
public:
	Player();
	~Player();

	void Init();
	void Update();
	void Draw(Camera* camera, uint32_t index);
	void Release();

	void Attack();

private:
	Model* model_;
	TextureManager* texture_ = TextureManager::GetInstance();
	WorldTransform worldTransform_;
	Input* input_ = Input::GetInsTance();

	ModelData modelData;
	Transform transform;

	bool isAttack;

	std::list<PlayerBullet*> bullets_;
};