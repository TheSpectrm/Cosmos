CXX = g++
INC = Cosmos/Include

build:
	mkdir bin\\Cosmos\\int
	mkdir bin\\Sandbox\\int

	$(CXX) -D CS_PLATFORM_WINDOWS -D CS_BUILD_DLL -I $(INC) -c Cosmos/Source/Application.cpp -o bin/Cosmos/int/Application.obj
	$(CXX) -shared bin/Cosmos/int/Application.obj -o bin/Cosmos/Cosmos.dll

	$(CXX) -D CS_PLATFORM_WINDOWS -I $(INC) -c Sandbox/Source/Sandbox.cpp -o bin/Sandbox/int/Sandbox.obj
	$(CXX) bin/Sandbox/int/Sandbox.obj bin/Cosmos/Cosmos.dll -o bin/Sandbox/Sandbox.exe

clean:
	rmdir /s /q bin