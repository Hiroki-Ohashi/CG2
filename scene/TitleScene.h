#pragma once
#include "Input.h"
#include "Sprite.h"
#include "TextureManager.h"


class TitleScene{
public:
	~TitleScene();

	void Init();
	void Update();
private:
	TextureManager* textureManager_ = nullptr;
	Sprite* title = nullptr;

	uint32_t uv;
};