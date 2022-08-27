# Makefile variables
CXX = g++
INC = Cosmos/Include
VENDOR = Cosmos/Vendor

# Build the project (generate binaries)
build:
	mkdir bin\\Cosmos\\int\\Core
	mkdir bin\\Sandbox\\int

	$(CXX) -D CS_PLATFORM_WINDOWS -D CS_BUILD_DLL -I $(INC) -I $(VENDOR) -c $(INC)/cspch.h -o Cosmos/Source/Core/cspch.h.gch
	$(CXX) -D CS_PLATFORM_WINDOWS -D CS_BUILD_DLL -I $(INC) -I $(VENDOR) -c Cosmos/Source/Core/Application.cpp -o bin/Cosmos/int/Core/Application.obj
	$(CXX) -D CS_PLATFORM_WINDOWS -D CS_BUILD_DLL -I $(INC) -I $(VENDOR) -c Cosmos/Source/Core/Logger.cpp -o bin/Cosmos/int/Core/Logger.obj
	$(CXX) -D CS_PLATFORM_WINDOWS -D CS_BUILD_DLL -I $(INC) -I $(VENDOR) -c Cosmos/Source/Core/Window.cpp -o bin/Cosmos/int/Core/Window.obj
	$(CXX) -shared -LCosmos/Lib bin/Cosmos/int/Core/Application.obj bin/Cosmos/int/Core/Logger.obj bin/Cosmos/int/Core/Window.obj -lglfw3 -lopengl32 -lgdi32 -o bin/Cosmos/Cosmos.dll

	$(CXX) -D CS_PLATFORM_WINDOWS -I $(INC) -I $(VENDOR) -c Sandbox/Source/Sandbox.cpp -o bin/Sandbox/int/Sandbox.obj
	$(CXX) bin/Sandbox/int/Sandbox.obj bin/Cosmos/Cosmos.dll -o bin/Sandbox/Sandbox.exe

# Clean the project (remove binaries)
clean:
	del Cosmos\\Source\\Core\\cspch.h.gch
	rmdir /s /q bin