#pragma once

#ifdef FS_PLATFORM_WINDOWS

extern FruitSalad::Application* FruitSalad::CreateApplication();

// the main function is now created by the Engine instead of the client
int main(int argc, char** argv) {

	auto app = FruitSalad::CreateApplication();
	app->Run(); // will be handled by Engine
	delete app;

}
#endif