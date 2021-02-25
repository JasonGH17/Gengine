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

int main()
{
	Sandbox* sandbox = new Sandbox();
	sandbox->Run();
	delete sandbox;
}