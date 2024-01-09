#pragma once
#include <Windows.h>
#include <cstdint>
#include <string>
#include <format>

#include "Function.h"
#include "ImGuiManeger.h"
#include "MathFunction.h"
#include "Camera.h"
#include "TextureManager.h"
#include "Input.h"
#include "imgui.h"

#include "Player.h"
#include "Enemy.h"
#include "Sprite.h"

#pragma comment(lib, "d3d12.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "dxcompiler.lib")


class GameScene {
public:
	~GameScene();

	// 初期化
	void Initialize();
	// 読み込み
	void Update();
	// 描画
	void Draw();
	// 解放
	void Release();

private:

	// 三角形の数
	static const int Max = 2;

	Input* input_ = nullptr;
	TextureManager* textureManager_ = nullptr;
	Camera* camera_ = nullptr;

	Sprite* title = nullptr;

	Player* player_ = nullptr;
	Enemy* enemy1_ = nullptr;
	Enemy* enemy2_ = nullptr;
	Enemy* enemy3_ = nullptr;

	uint32_t a;
	uint32_t moon;
	uint32_t uv;
	uint32_t mato;

	bool isTitle;
};
