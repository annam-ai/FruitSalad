#include <FruitSalad.h>

class Sandbox : public FruitSalad::Application
{
public:
	Sandbox() {

	}
	~Sandbox() {

	}
};

FruitSalad::Application* FruitSalad::CreateApplication() {
	return new Sandbox;
}