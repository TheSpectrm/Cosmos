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

int main()
{
	auto app = new Sandbox();
	app->Run();

	return 0;
}