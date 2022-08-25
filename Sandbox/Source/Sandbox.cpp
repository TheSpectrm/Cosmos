#include <Cosmos.h>

class Sandbox : public Cosmos::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Cosmos::Application* Cosmos::CreateApplication()
{
	return new Sandbox();
}