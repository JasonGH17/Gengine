#include <DeskBrew.h>

class Sandbox : public DeskBrew::Application
{
public:
	Sandbox()
	{
	}

	~Sandbox()
	{
	}
};

DeskBrew::Application* DeskBrew::CreateApplication()
{
	return new Sandbox();
}