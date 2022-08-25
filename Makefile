# Makefile variables
CXX = g++
INC = Cosmos/Include

# Build the project (generate binaries)
build:
	mkdir bin\\Cosmos\\int
	mkdir bin\\Sandbox\\int

	$(CXX) -D CS_PLATFORM_WINDOWS -D CS_BUILD_DLL -I $(INC) -c Cosmos/Source/Application.cpp -o bin/Cosmos/int/Application.obj
	$(CXX) -D CS_PLATFORM_WINDOWS -D CS_BUILD_DLL -I $(INC) -c Cosmos/Source/Logger.cpp -o bin/Cosmos/int/Logger.obj
	$(CXX) -shared bin/Cosmos/int/Application.obj bin/Cosmos/int/Logger.obj -o bin/Cosmos/Cosmos.dll

	$(CXX) -D CS_PLATFORM_WINDOWS -I $(INC) -c Sandbox/Source/Sandbox.cpp -o bin/Sandbox/int/Sandbox.obj
	$(CXX) bin/Sandbox/int/Sandbox.obj bin/Cosmos/Cosmos.dll -o bin/Sandbox/Sandbox.exe

# Clean the project (remove binaries)
clean:
	rmdir /s /q bin