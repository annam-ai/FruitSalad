#include <FruitSalad.h>

class KiwiMango : public FruitSalad::Application
{
public:
	KiwiMango() {

	}
	~KiwiMango() {

	}
};

FruitSalad::Application* FruitSalad::CreateApplication() {
	return new KiwiMango;
}