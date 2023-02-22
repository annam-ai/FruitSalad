#pragma once

#include "Core.h"

namespace FruitSalad {
	
	class FRUITSALAD_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// Will be defined in Client
	Application* CreateApplication();

}


