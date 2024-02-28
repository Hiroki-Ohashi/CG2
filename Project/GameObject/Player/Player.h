#pragma once
#include "Model.h"
#include "MathFunction.h"
#include "Camera.h"
#include "Input.h"
#include "WorldTransform.h"
#include "TextureManager.h"

#include "PlayerBullet.h"

class Player {
public:
	~Player();

	void Init();
	void Update();
	void Draw(uint32_t index, Camera* camera, uint32_t index2);

	void Attack();
	void OnCollision();

	Vector3 GetPosition() { return transform.translate; }
	// 弾リストを取得
	const std::list<PlayerBullet*>& GetBullets() const { return bullets_; }

public:
	std::unique_ptr<Model> model_ = nullptr;
	std::unique_ptr<Model> model_2 = nullptr;
	Input* input_ = Input::GetInsTance();
	TextureManager* textureManager_ = TextureManager::GetInstance();

	Transform transform;
	Transform transform2;

	float speed = 0.02f;

	bool isAttack;

	std::list<PlayerBullet*> bullets_;

	int bulletTex;
};