#pragma once
#include <Windows.h>
#include <cstdint>

class WinApp {
public:
	WinApp(const wchar_t* title);
	~WinApp();

	WNDCLASS wc{};

	// クライアント領域のサイズ
	static const int32_t kClientWidth = 1280;
	static const int32_t kClientHeight = 720;

	HWND hwnd = nullptr;
};