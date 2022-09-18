/* ENTRY POINT */
#pragma once

#ifdef PLATFORM_WINDOWS

extern Cosmos::Application* Cosmos::CreateApplication();

int main(int argc, char* argv[])
{
	LOG_INIT();
	CORE_WARN("Hello from Cosmos! Var=%d", 128);

	auto app = Cosmos::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif