#pragma once

#ifdef FS_PLATFORM_WINDOWS

extern FruitSalad::Application* FruitSalad::CreateApplication();

// the main function is now created by the Engine instead of the client
int main(int argc, char** argv) {

	FruitSalad::Log::Init();
	FS_CORE_TRACE("Initialized Log!");
	int a = 5;
	FS_INFO("Hello I'm logging for the client!! Var={0}", a);

	auto app = FruitSalad::CreateApplication();
	app->Run(); // will be handled by Engine
	delete app;

}
#endif