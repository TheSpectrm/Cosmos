# Makefile variables
CXX = g++
SRC = Cosmos/src
DEPS = Cosmos/deps	
DEFINES = -D CS_PLATFORM_WINDOWS -D CS_BUILD_DLL
OBJS = application.obj logger.obj window.obj vao_loader.obj shader.obj vec2.obj vec3.obj vec4.obj mat4.obj transform.obj glad.obj
OLIST = $(patsubst %,bin/Cosmos/int/%,$(OBJS))

# Link the generated object files
# Link Cosmos
bin/Cosmos/Cosmos.dll: dirs\
					   bin/Cosmos/int/application.obj\
					   bin/Cosmos/int/logger.obj\
					   bin/Cosmos/int/window.obj\
					   bin/Cosmos/int/vao_loader.obj\
					   bin/Cosmos/int/shader.obj\
					   bin/Cosmos/int/vec2.obj\
					   bin/Cosmos/int/vec3.obj\
					   bin/Cosmos/int/vec4.obj\
					   bin/Cosmos/int/mat4.obj\
					   bin/Cosmos/int/transform.obj\
					   bin/Cosmos/int/glad.obj

	$(CXX) -shared -LCosmos/lib $(OLIST) -lglfw3 -lopengl32 -lgdi32 -o bin/Cosmos/Cosmos.dll
	make bin/Sandbox/Sandbox.exe

# Link Sandbox
bin/Sandbox/Sandbox.exe: bin/Sandbox/int/sandbox.obj
	$(CXX) bin/Sandbox/int/sandbox.obj bin/Cosmos/Cosmos.dll -o bin/Sandbox/Sandbox.exe

# Build the project (generate binaries)
# Compilation for precompiled header
Cosmos/src/cspch.h.gch: $(SRC)/cspch.h
	$(CXX) -std=c++2a $(DEFINES) -I $(SRC) -I $(DEPS) -c $(SRC)/cspch.h

# Compilation for core
bin/Cosmos/int/application.obj: $(SRC)/core/application.cpp $(SRC)/core/application.h $(SRC)/cspch.h.gch
	$(CXX) -std=c++2a $(DEFINES) -I $(SRC) -I $(DEPS) -c $(SRC)/core/application.cpp -o bin/Cosmos/int/application.obj

bin/Cosmos/int/logger.obj: $(SRC)/core/logger.cpp $(SRC)/core/logger.h $(SRC)/cspch.h.gch
	$(CXX) -std=c++2a $(DEFINES) -I $(SRC) -I $(DEPS) -c $(SRC)/core/logger.cpp -o bin/Cosmos/int/logger.obj

bin/Cosmos/int/window.obj: $(SRC)/core/window.cpp $(SRC)/core/window.h $(SRC)/cspch.h.gch
	$(CXX) -std=c++2a $(DEFINES) -I $(SRC) -I $(DEPS) -c $(SRC)/core/window.cpp -o bin/Cosmos/int/window.obj

# Compilation for graphics
bin/Cosmos/int/vao_loader.obj: $(SRC)/graphics/vao_loader.cpp $(SRC)/graphics/vao_loader.h $(SRC)/cspch.h.gch
	$(CXX) -std=c++2a $(DEFINES) -I $(SRC) -I $(DEPS) -c $(SRC)/graphics/vao_loader.cpp -o bin/Cosmos/int/vao_loader.obj

bin/Cosmos/int/shader.obj: $(SRC)/graphics/shader.cpp $(SRC)/graphics/shader.h $(SRC)/cspch.h.gch
	$(CXX) -std=c++2a $(DEFINES) -I $(SRC) -I $(DEPS) -c $(SRC)/graphics/shader.cpp -o bin/Cosmos/int/shader.obj

# Compilation for math
bin/Cosmos/int/vec2.obj: $(SRC)/math/vec2.cpp $(SRC)/math/vec2.h $(SRC)/cspch.h.gch
	$(CXX) -std=c++2a $(DEFINES) -I $(SRC) -I $(DEPS) -c $(SRC)/math/vec2.cpp -o bin/Cosmos/int/vec2.obj

bin/Cosmos/int/vec3.obj: $(SRC)/math/vec3.cpp $(SRC)/math/vec3.h $(SRC)/cspch.h.gch
	$(CXX) -std=c++2a $(DEFINES) -I $(SRC) -I $(DEPS) -c $(SRC)/math/vec3.cpp -o bin/Cosmos/int/vec3.obj

bin/Cosmos/int/vec4.obj: $(SRC)/math/vec4.cpp $(SRC)/math/vec4.h $(SRC)/cspch.h.gch
	$(CXX) -std=c++2a $(DEFINES) -I $(SRC) -I $(DEPS) -c $(SRC)/math/vec4.cpp -o bin/Cosmos/int/vec4.obj

bin/Cosmos/int/mat4.obj: $(SRC)/math/mat4.cpp $(SRC)/math/mat4.h $(SRC)/cspch.h.gch
	$(CXX) -std=c++2a $(DEFINES) -I $(SRC) -I $(DEPS) -c $(SRC)/math/mat4.cpp -o bin/Cosmos/int/mat4.obj

bin/Cosmos/int/transform.obj: $(SRC)/math/transform.cpp $(SRC)/math/transform.h $(SRC)/cspch.h.gch
	$(CXX) -std=c++2a $(DEFINES) -I $(SRC) -I $(DEPS) -c $(SRC)/math/transform.cpp -o bin/Cosmos/int/transform.obj

# Compilation for GLAD Dependency
bin/Cosmos/int/glad.obj: Cosmos/deps/glad/glad.cpp Cosmos/deps/glad/glad.h $(SRC)/cspch.h.gch
	$(CXX) -std=c++2a $(DEFINES) -I $(SRC) -I $(DEPS) -c Cosmos/deps/glad/glad.cpp -o bin/Cosmos/int/glad.obj

# Compilation for Sandbox
bin/Sandbox/int/sandbox.obj: Sandbox/src/sandbox.cpp
	$(CXX) -std=c++2a -D CS_PLATFORM_WINDOWS -I $(SRC) -I $(DEPS) -c Sandbox/src/sandbox.cpp -o bin/Sandbox/int/sandbox.obj

# Generate binary folders
.PHONY: dirs
dirs:
	@mkdir bin\\Sandbox\\int
	@mkdir bin\\Cosmos\\int

# Clean the project (remove binaries)
.PHONY: clean
clean:
	@del Cosmos\\src\\cspch.h.gch
	@rmdir /s /q bin