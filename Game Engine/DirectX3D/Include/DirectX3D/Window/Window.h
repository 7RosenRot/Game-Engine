#include <Windows.h>
#include <assert.h>
#pragma once

class Window {
public:
	Window();
	~Window();

	void onDestroy();
	bool isClosed();
private:
	void* m_handle = nullptr;
};