#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace FruitSalad {
	Application::Application()
	{

	}

	Application::~Application() 
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			FS_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			FS_TRACE(e);
		}
		while (true);
	}

}