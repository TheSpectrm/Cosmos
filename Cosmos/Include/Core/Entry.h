#pragma once

#ifdef CS_PLATFORM_WINDOWS

extern Cosmos::Application* Cosmos::CreateApplication();

int main(int argc, char* argv[])
{
	Cosmos::Log::Init();

	Cosmos::Log::GetCoreLogger()->Success("SUCCESS from the core! %c", 'f');
	Cosmos::Log::GetCoreLogger()->Info("INFO from the core! %c", 'f');
	Cosmos::Log::GetCoreLogger()->Warn("WARN from the core! %c", 'f');
	Cosmos::Log::GetCoreLogger()->Error("ERROR from the core! %c", 'f');

	auto app = Cosmos::CreateApplication();
	app->Run();

	delete app;

	return 0;
}

#endif