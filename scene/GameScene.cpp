#include "GameScene.h"

GameScene::~GameScene(){
	delete player_;
	delete enemy1_;
	delete enemy2_;
	delete enemy3_;
}

void GameScene::Initialize(){
	textureManager_ = TextureManager::GetInstance();
	textureManager_->Initialize();

	input_ = Input::GetInsTance();
	input_->Initialize();

	camera_ = new Camera();
	camera_->Initialize();

	title = new Sprite();
	title->Initialize();

	player_ = new Player();
	player_->Init();

	enemy1_ = new Enemy();
	enemy1_->Init(0.0f);

	enemy2_ = new Enemy();
	enemy2_->Init(2.0f);

	enemy3_ = new Enemy();
	enemy3_->Init(-2.0f);

	uv = textureManager_->Load("Resources/aa.png");
	a = textureManager_->Load("Resources/a.png");
	mato = textureManager_->Load("Resources/mato.png");

	isTitle = true;
}

void GameScene::Update(){
	input_->Update();
	camera_->Update();
	player_->Update();
	enemy1_->Update();
	enemy2_->Update();
	enemy3_->Update();

}

void GameScene::Draw(){

	if (isTitle) {
		title->Draw(uv);
	}

	if (input_->PushKey(DIK_SPACE)) {
		isTitle = false;
	}

	player_->Draw(camera_, a);

	enemy1_->Draw(camera_, mato);
	enemy2_->Draw(camera_, mato);
	enemy3_->Draw(camera_, mato);
	
}

void GameScene::Release() {
}
