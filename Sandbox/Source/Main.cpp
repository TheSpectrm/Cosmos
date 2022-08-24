namespace Cosmos
{
	class __declspec(dllimport) Application
	{
	public:
		Application();
		~Application();

		void Run();
	};
}

int main()
{
	auto app = new Cosmos::Application();
	app->Run();

	return 0;
}