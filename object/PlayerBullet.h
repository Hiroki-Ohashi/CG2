#pragma once
#include "TextureManager.h"
#include "Model.h"
#include "WorldTransform.h"
#include "Camera.h"
#include "Input.h"

class PlayerBullet {     
public:
	PlayerBullet();
	~PlayerBullet();

	void Init(Vector3 pos);
	void Update();
	void Draw(Camera* camera, uint32_t index);

	bool IsDead() const { return isDead_; }
private:
	Model* model_;
	TextureManager* texture_ = TextureManager::GetInstance();

	ModelData modelData;
	Transform transform;

	static const int32_t kLifeTime = 60 * 5;
	// デスタイマー
	int32_t deathTimer_ = kLifeTime;

	bool isDead_ = false;
};