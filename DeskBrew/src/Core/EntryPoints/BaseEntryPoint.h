#pragma once

extern DeskBrew::Application* DeskBrew::CreateApplication();

int main(int argv, char** argc)
{
	auto app = DeskBrew::CreateApplication();
	app->Run();
	delete app;
}
