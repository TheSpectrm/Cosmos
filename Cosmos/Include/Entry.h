#pragma once

#ifdef CS_PLATFORM_WINDOWS

extern Cosmos::Application* Cosmos::CreateApplication();

int main(int argc, char* argv[])
{
	auto logger = new Cosmos::Logger("Tester");
	logger->Success("This is SUCCESS!");
	logger->Info("This is INFO!");
	logger->Warn("This is WARN!");
	logger->Error("This is ERROR!");

	auto app = Cosmos::CreateApplication();
	app->Run();

	delete logger;
	delete app;

	return 0;
}

#endif