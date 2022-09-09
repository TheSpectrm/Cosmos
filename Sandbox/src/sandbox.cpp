// Sandbox (default Cosmos client)
#include <cosmos.h>

class Sandbox : public Cosmos::Application
{
public:
	Sandbox() = default;
};

Cosmos::Application* Cosmos::CreateApplication()
{
	return new Sandbox();
}