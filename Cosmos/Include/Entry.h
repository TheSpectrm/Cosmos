#pragma once

#ifdef CS_PLATFORM_WINDOWS

extern Cosmos::Application* Cosmos::CreateApplication();

int main(int argc, char* argv[])
{
	auto logger = new Cosmos::Logger("John");
	logger->Success("This is logger!");
	logger->Success("Hello, I am John %.3f %c", 69.420, 'f');

	auto app = Cosmos::CreateApplication();
	app->Run();

	delete logger;
	delete app;

	return 0;
}

#endif