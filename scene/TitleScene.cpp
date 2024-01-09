#include "TitleScene.h"

TitleScene::~TitleScene()
{
	delete title;
}

void TitleScene::Init()
{
	textureManager_ = TextureManager::GetInstance();
	textureManager_->Initialize();

	title = new Sprite();
	title->Initialize();

	uv = textureManager_->Load("Resources/uvChecker.png");
}

void TitleScene::Update()
{
	title->Draw(uv);
}
