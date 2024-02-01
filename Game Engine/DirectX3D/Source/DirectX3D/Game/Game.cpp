#include <DirectX3D/Game/Game.h>
#include <DirectX3D/Window/Window.h>

Game::Game() {
	m_display = std::unique_ptr<Window>(new Window());
}

Game::~Game() {}

void Game::run() {

	MSG msg;
	while (m_isRunning && !m_display->isClosed()) {
		if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		Sleep(1);
	}
}

void Game::quit() {
	m_isRunning = false;
}