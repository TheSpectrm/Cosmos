#pragma once

#ifdef CS_PLATFORM_WINDOWS

extern Cosmos::Application* Cosmos::CreateApplication();

int main(int argc, char* argv[])
{
	auto app = Cosmos::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif