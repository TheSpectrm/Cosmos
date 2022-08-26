# Makefile variables
CXX = g++
INC = Cosmos/Include

# Build the project (generate binaries)
build:
	mkdir bin\\Cosmos\\int\\Core
	mkdir bin\\Sandbox\\int

	$(CXX) -D CS_PLATFORM_WINDOWS -D CS_BUILD_DLL -I $(INC) -c Cosmos/Source/Core/Application.cpp -o bin/Cosmos/int/Core/Application.obj
	$(CXX) -D CS_PLATFORM_WINDOWS -D CS_BUILD_DLL -I $(INC) -c Cosmos/Source/Core/Logger.cpp -o bin/Cosmos/int/Core/Logger.obj
	$(CXX) -shared bin/Cosmos/int/Core/Application.obj bin/Cosmos/int/Core/Logger.obj -o bin/Cosmos/Cosmos.dll

	$(CXX) -D CS_PLATFORM_WINDOWS -I $(INC) -c Sandbox/Source/Sandbox.cpp -o bin/Sandbox/int/Sandbox.obj
	$(CXX) bin/Sandbox/int/Sandbox.obj bin/Cosmos/Cosmos.dll -o bin/Sandbox/Sandbox.exe

# Clean the project (remove binaries)
clean:
	rmdir /s /q bin