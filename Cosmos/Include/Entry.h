#pragma once

#ifdef CS_PLATFORM_WINDOWS

extern Cosmos::Application* Cosmos::CreateApplication();

int main(int argc, char* argv[])
{
	auto logger = new Cosmos::Logger("Tester");
	logger->Success("%d | This is SUCCESS!", 1);
	logger->Info("%d | This is INFO!", 2);
	logger->Warn("%d | This is WARN!", 3);
	logger->Error("%d | This is ERROR!", 4);

	auto app = Cosmos::CreateApplication();
	app->Run();

	delete logger;
	delete app;

	return 0;
}

#endif