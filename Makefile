# Makefile variables
CXX = g++
INC = Cosmos/src
VENDOR = Cosmos/vendor

# Build the project (generate binaries)
build:
	mkdir bin\\Sandbox\\int
	mkdir bin\\Cosmos\\int\\core
	mkdir bin\\Cosmos\\int\\graphics
	mkdir bin\\Cosmos\\int\\math

	$(CXX) -D CS_PLATFORM_WINDOWS -D CS_BUILD_DLL -I $(INC) -I $(VENDOR) -c Cosmos/src/cspch.cpp -o bin/Cosmos/int/cspch.gch
	$(CXX) -D CS_PLATFORM_WINDOWS -D CS_BUILD_DLL -I $(INC) -I $(VENDOR) -c Cosmos/src/core/application.cpp -o bin/Cosmos/int/core/application.obj
	$(CXX) -D CS_PLATFORM_WINDOWS -D CS_BUILD_DLL -I $(INC) -I $(VENDOR) -c Cosmos/src/core/logger.cpp -o bin/Cosmos/int/core/logger.obj
	$(CXX) -D CS_PLATFORM_WINDOWS -D CS_BUILD_DLL -I $(INC) -I $(VENDOR) -c Cosmos/src/core/window.cpp -o bin/Cosmos/int/core/window.obj

	$(CXX) -D CS_PLATFORM_WINDOWS -D CS_BUILD_DLL -I $(INC) -I $(VENDOR) -c Cosmos/src/graphics/vao_loader.cpp -o bin/Cosmos/int/graphics/vao_loader.obj
	$(CXX) -D CS_PLATFORM_WINDOWS -D CS_BUILD_DLL -I $(INC) -I $(VENDOR) -c Cosmos/src/graphics/shader.cpp -o bin/Cosmos/int/graphics/shader.obj

	$(CXX) -D CS_PLATFORM_WINDOWS -D CS_BUILD_DLL -I $(INC) -I $(VENDOR) -c Cosmos/src/math/vec2.cpp -o bin/Cosmos/int/math/vec2.obj
	$(CXX) -D CS_PLATFORM_WINDOWS -D CS_BUILD_DLL -I $(INC) -I $(VENDOR) -c Cosmos/src/math/vec3.cpp -o bin/Cosmos/int/math/vec3.obj
	$(CXX) -D CS_PLATFORM_WINDOWS -D CS_BUILD_DLL -I $(INC) -I $(VENDOR) -c Cosmos/src/math/vec4.cpp -o bin/Cosmos/int/math/vec4.obj
	$(CXX) -D CS_PLATFORM_WINDOWS -D CS_BUILD_DLL -I $(INC) -I $(VENDOR) -c Cosmos/src/math/mat4.cpp -o bin/Cosmos/int/math/mat4.obj

	$(CXX) -D CS_PLATFORM_WINDOWS -D CS_BUILD_DLL -I $(INC) -I $(VENDOR) -c $(VENDOR)/GLAD/glad.cpp -o bin/Cosmos/int/glad.obj

	$(CXX) -shared -LCosmos/lib bin/Cosmos/int/core/application.obj bin/Cosmos/int/core/logger.obj bin/Cosmos/int/core/window.obj bin/Cosmos/int/graphics/vao_loader.obj bin/Cosmos/int/graphics/shader.obj bin/Cosmos/int/math/vec2.obj bin/Cosmos/int/math/vec3.obj bin/Cosmos/int/math/vec4.obj bin/Cosmos/int/math/mat4.obj bin/Cosmos/int/glad.obj bin/Cosmos/int/cspch.gch -lglfw3 -lopengl32 -lgdi32 -o bin/Cosmos/Cosmos.dll

	$(CXX) -D CS_PLATFORM_WINDOWS -I $(INC) -I $(VENDOR) -c Sandbox/src/sandbox.cpp -o bin/Sandbox/int/sandbox.obj
	$(CXX) bin/Sandbox/int/sandbox.obj bin/Cosmos/Cosmos.dll -o bin/Sandbox/Sandbox.exe

# Clean the project (remove binaries)
clean:
	del Cosmos\\src\\core\\cspch.h.gch
	rmdir /s /q bin