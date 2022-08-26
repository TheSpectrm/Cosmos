#pragma once

#ifdef CS_PLATFORM_WINDOWS

extern Cosmos::Application* Cosmos::CreateApplication();

int main(int argc, char* argv[])
{
	CS_LOG_INIT();

	CS_CORE_SUCCESS("SUCCESS from the core! %d %c", 420, 'f');
	CS_CORE_INFO("INFO from the core! %d %c", 420, 'f');
	CS_CORE_WARN("WARN from the core! %d %c", 420, 'f');
	CS_CORE_ERROR("ERROR from the core! %d %c", 420, 'f');

	auto app = Cosmos::CreateApplication();
	app->Run();

	delete app;

	return 0;
}

#endif