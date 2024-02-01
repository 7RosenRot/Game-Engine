#include <DirectX3D/Window/Window.h>

INT WindowHeight;
INT WindowWidth;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	
	switch (msg) {
	case WM_DESTROY: {
		Window* window = (Window *)GetWindowLongPtr(hwnd, GWLP_USERDATA);
		window->onDestroy();
		break;
	}	
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}

	return NULL;
}

Window::Window() {
	
	WindowHeight = 768;
	WindowWidth = 1024;
	
	WNDCLASSEX wc = {};
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.lpszClassName = L"DirectXWindow";
	wc.lpfnWndProc = &WndProc;

	assert(RegisterClassEx(&wc));
	
	RECT rc = {0, 0, WindowWidth, WindowHeight};
	AdjustWindowRect(&rc, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, false);

	m_handle = CreateWindowEx(NULL, L"DirectXWindow", L"RosenRot | DirectX 3D Game", WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, CW_USEDEFAULT, CW_USEDEFAULT, rc.right-rc.left, rc.bottom-rc.top, NULL, NULL, NULL, NULL);

	assert(m_handle);

	SetWindowLongPtr((HWND)m_handle, GWLP_USERDATA, (LONG_PTR)this);

	ShowWindow((HWND)m_handle, SW_SHOW);
	UpdateWindow((HWND)m_handle);
}

Window::~Window() {
	DestroyWindow((HWND)m_handle);
}

void Window::onDestroy() {
	m_handle = nullptr;
}

bool Window::isClosed() {
	return !m_handle;
}