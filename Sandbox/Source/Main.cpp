namespace Cosmos
{
	class __declspec(dllimport) Application
	{
	public:
		Application();
		~Application();
	};
}

int main()
{
	auto app = new Cosmos::Application();
	return 0;
}