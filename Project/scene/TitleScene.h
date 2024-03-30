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



class TitleScene : public IScene {
public:
	~TitleScene();

	void Initialize() override;
	void Update() override;
	void Draw() override;

private:

	TextureManager* textureManager_ = TextureManager::GetInstance();
	Camera* camera_ = nullptr;

	std::unique_ptr<Sprite> sprite_ = nullptr;
	std::unique_ptr<Sprite> sprite2_ = nullptr;

	std::unique_ptr<Sphere> sphere_ = nullptr;

	Transform transform;
	Transform transform2;

	uint32_t monsterBall;
	uint32_t moon;
	uint32_t uv;
	uint32_t kusa;
	uint32_t circle;
};