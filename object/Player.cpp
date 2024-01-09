#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
	delete model_;
	
	// bullet_の解放
	for (PlayerBullet* bullet : bullets_) {
		delete bullet;
	}
}

void Player::Init()
{
	input_->Initialize();

	transform = { { 0.1f,0.1f,0.1f},{0.0f,0.0f,0.0f},{0.0f,0.0f,0.0f} };
	modelData = texture_->LoadObjFile("resources", "cube.obj");

	model_ = new Model();
	model_->Initialize(modelData, transform);
}

void Player::Update()
{
	input_->Update();

	// デスフラグんお立った弾を排除
	bullets_.remove_if([](PlayerBullet* bullet) {
		if (bullet->IsDead()) {
			delete bullet;
			return true;
		}
		return false;
		});

	model_->worldTransform_.translate = transform.translate;

	if (input_->PushKey(DIK_W)) {
		transform.translate.y += 0.01f;
	}
	if (input_->PushKey(DIK_S)) {
		transform.translate.y -= 0.01f;
	}
	if (input_->PushKey(DIK_A)) {
		transform.translate.x -= 0.01f;
	}
	if (input_->PushKey(DIK_D)) {
		transform.translate.x += 0.01f;
	}

	Attack();

	// 弾更新
	for (PlayerBullet* bullet : bullets_) {
		bullet->Update();
	}
}

void Player::Draw(Camera* camera, uint32_t index)
{
	model_->Draw(camera, index);

	// 弾描画
	for (PlayerBullet* bullet : bullets_) {
		bullet->Draw(camera, index);
	}
}

void Player::Release()
{
}

void Player::Attack() {
	if (input_->TriggerKey(DIK_SPACE)) {

		// 弾を生成し、初期化
		PlayerBullet* newBullet = new PlayerBullet();
		newBullet->Init(transform.translate);

		// 弾を登録
		bullets_.push_back(newBullet);
	}
}
