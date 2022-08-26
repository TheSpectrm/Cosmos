#pragma once

#ifdef CS_PLATFORM_WINDOWS

extern Cosmos::Application* Cosmos::CreateApplication();

int main(int argc, char* argv[])
{
	CS_LOG_INIT();
	CS_CORE_WARN("Hello from Cosmos! n = %d", 92);

	auto app = Cosmos::CreateApplication();
	app->Run();

	delete app;

	return 0;
}

#endif