# Makefile variables
CXX = g++
INC = Cosmos/Include
VENDOR = Cosmos/Vendor

# Build the project (generate binaries)
build:
	mkdir bin\\Sandbox\\int
	mkdir bin\\Cosmos\\int\\Core
	mkdir bin\\Cosmos\\int\\Graphics
	mkdir bin\\Cosmos\\int\\Math

	$(CXX) -D CS_PLATFORM_WINDOWS -D CS_BUILD_DLL -I $(INC) -I $(VENDOR) -c Cosmos/Source/cspch.cpp -o bin/Cosmos/int/cspch.gch
	$(CXX) -D CS_PLATFORM_WINDOWS -D CS_BUILD_DLL -I $(INC) -I $(VENDOR) -c Cosmos/Source/Core/Application.cpp -o bin/Cosmos/int/Core/Application.obj
	$(CXX) -D CS_PLATFORM_WINDOWS -D CS_BUILD_DLL -I $(INC) -I $(VENDOR) -c Cosmos/Source/Core/Logger.cpp -o bin/Cosmos/int/Core/Logger.obj
	$(CXX) -D CS_PLATFORM_WINDOWS -D CS_BUILD_DLL -I $(INC) -I $(VENDOR) -c Cosmos/Source/Core/Window.cpp -o bin/Cosmos/int/Core/Window.obj

	$(CXX) -D CS_PLATFORM_WINDOWS -D CS_BUILD_DLL -I $(INC) -I $(VENDOR) -c Cosmos/Source/Graphics/VAOLoader.cpp -o bin/Cosmos/int/Graphics/VAOLoader.obj
	$(CXX) -D CS_PLATFORM_WINDOWS -D CS_BUILD_DLL -I $(INC) -I $(VENDOR) -c Cosmos/Source/Graphics/Shader.cpp -o bin/Cosmos/int/Graphics/Shader.obj

	$(CXX) -D CS_PLATFORM_WINDOWS -D CS_BUILD_DLL -I $(INC) -I $(VENDOR) -c Cosmos/Source/Math/vec2.cpp -o bin/Cosmos/int/Math/vec2.obj
	$(CXX) -D CS_PLATFORM_WINDOWS -D CS_BUILD_DLL -I $(INC) -I $(VENDOR) -c Cosmos/Source/Math/vec3.cpp -o bin/Cosmos/int/Math/vec3.obj
	$(CXX) -D CS_PLATFORM_WINDOWS -D CS_BUILD_DLL -I $(INC) -I $(VENDOR) -c Cosmos/Source/Math/vec4.cpp -o bin/Cosmos/int/Math/vec4.obj

	$(CXX) -D CS_PLATFORM_WINDOWS -D CS_BUILD_DLL -I $(INC) -I $(VENDOR) -c $(VENDOR)/GLAD/glad.cpp -o bin/Cosmos/int/glad.obj

	$(CXX) -shared -LCosmos/Lib bin/Cosmos/int/Core/Application.obj bin/Cosmos/int/Core/Logger.obj bin/Cosmos/int/Core/Window.obj bin/Cosmos/int/Graphics/VAOLoader.obj bin/Cosmos/int/Graphics/Shader.obj bin/Cosmos/int/Math/vec2.obj bin/Cosmos/int/Math/vec3.obj bin/Cosmos/int/Math/vec4.obj bin/Cosmos/int/glad.obj bin/Cosmos/int/cspch.gch -lglfw3 -lopengl32 -lgdi32 -o bin/Cosmos/Cosmos.dll

	$(CXX) -D CS_PLATFORM_WINDOWS -I $(INC) -I $(VENDOR) -c Sandbox/Source/Sandbox.cpp -o bin/Sandbox/int/Sandbox.obj
	$(CXX) bin/Sandbox/int/Sandbox.obj bin/Cosmos/Cosmos.dll -o bin/Sandbox/Sandbox.exe

# Clean the project (remove binaries)
clean:
	del Cosmos\\Source\\Core\\cspch.h.gch
	rmdir /s /q bin