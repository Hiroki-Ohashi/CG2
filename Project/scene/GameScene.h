#pragma once
#include <Windows.h>
#include <cstdint>
#include <string>
#include <format>

#include "Function.h"
#include "Triangle.h"
#include "Sprite.h"
#include "ImGuiManeger.h"
#include "MathFunction.h"
#include "Camera.h"
#include "Sphere.h"
#include "Model.h"
#include "TextureManager.h"
#include "imgui.h"

#include "Particle.h"
#include "IScene.h"

#pragma comment(lib, "d3d12.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "dxcompiler.lib")


class GameScene : public IScene {
public:
	~GameScene();

	// 初期化
	void Initialize() override;
	// 読み込み
	void Update() override;
	// 描画
	void Draw() override;
	// 解放
	void Release();

private:

	// 三角形の数
	static const int Max = 2;

	TextureManager* textureManager_ = nullptr;
	Camera* camera_ = nullptr;

	std::unique_ptr<Sphere> sphere_ = nullptr;

	std::unique_ptr<Model> model_;
	std::unique_ptr<Model> model2_;

	Particles* particle_ = nullptr;
	Particles* particle2_ = nullptr;

	CameraForGpu camera;
	Transform transform;
	Transform transform2;

	Vector3 pos = { -1.0f, 0.0f, 10.0f };
	Vector3 pos2 = { 1.0f, 0.0f, 10.0f };

	uint32_t monsterBall;
	uint32_t moon;
	uint32_t uv;
	uint32_t kusa;
	uint32_t circle;
};
