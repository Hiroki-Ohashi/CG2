#pragma once
#include <Windows.h>
#include <cstdint>
#include <string>
#include <format>
#include <d3d12.h>
#include <dxgi1_6.h>
#include <cassert>
#include <dxgidebug.h>
#include <dxcapi.h>
#include "externals/DirectXTex/DirectXTex.h"

struct Vector4 final {
	float x;
	float y;
	float z;
	float w;
};

class Convert {
public:
	static std::wstring ConvertString(const std::string& str);

	static std::string ConvertString(const std::wstring& str);

	static void Log(const std::string& message);

	static IDxcBlob* CompileShader(
		// CompilerするShaderファイルへのパス
		const std::wstring& filePath,
		// Compilerに使用するProfile
		const wchar_t* profile,
		// 初期化で生成したものを3つ
		IDxcUtils* dxcUtils,
		IDxcCompiler3* dxcCompiler,
		IDxcIncludeHandler* includeHandler);

	static DirectX::ScratchImage LoadTexture(const std::string& filePath);
};
