# MAKEFILE FOR COSMOS

# Makefile Variables & Macros
CXX = g++
SRC = Cosmos/src
DEPS = Cosmos/deps	
DEFINES = -D PLATFORM_WINDOWS -D BUILD_TYPE_DLL
OBJS = application.obj logger.obj window.obj model.obj vertex_array.obj vertex_buffer.obj index_buffer.obj shader.obj vec2.obj vec3.obj vec4.obj mat4.obj transform.obj glad.obj 
OBJLIST = $(patsubst %,bin/Cosmos/int/%,$(OBJS))

# Targets to be initialized
all: dirs Cosmos/src/cspch.h.gch bin/Cosmos/Cosmos.dll bin/Sandbox/Sandbox.exe

# Link the generated object files
# Link Cosmos
bin/Cosmos/Cosmos.dll: $(OBJLIST)
	@$(info Cosmos: Linking shared library $@)
	@$(CXX) -shared -LCosmos/lib $(OBJLIST) -lglfw3 -lopengl32 -lgdi32 -o $@

# Link Sandbox
bin/Sandbox/Sandbox.exe: bin/Sandbox/int/sandbox.obj
	@$(info Sandbox: Linking executable $@)
	@$(CXX) bin/Sandbox/int/sandbox.obj bin/Cosmos/Cosmos.dll -o $@
	@$(info Make: Build finished)

# Build the project (generate binaries)
# Compilation for Cosmos
# Build precompiled header (PCH)
$(SRC)/cspch.h.gch: $(SRC)/cspch.h
	@$(info Cosmos: Generating precompiled header $@)
	@$(CXX) -std=c++2a $(DEFINES) -I $(SRC) -I $(DEPS) -c $(SRC)/cspch.h

# Build core
bin/Cosmos/int/application.obj: $(SRC)/core/application.cpp $(SRC)/core/application.h
	@$(info Cosmos: Building object $@)
	@$(CXX) -std=c++2a $(DEFINES) -I $(SRC) -I $(DEPS) -c $(SRC)/core/application.cpp -o $@

bin/Cosmos/int/logger.obj: $(SRC)/core/logger.cpp $(SRC)/core/logger.h
	@$(info Cosmos: Building object $@)
	@$(CXX) -std=c++2a $(DEFINES) -I $(SRC) -I $(DEPS) -c $(SRC)/core/logger.cpp -o $@

bin/Cosmos/int/window.obj: $(SRC)/core/window.cpp $(SRC)/core/window.h
	@$(info Cosmos: Building object $@)
	@$(CXX) -std=c++2a $(DEFINES) -I $(SRC) -I $(DEPS) -c $(SRC)/core/window.cpp -o $@

# Build graphics
bin/Cosmos/int/model.obj: $(SRC)/graphics/model.cpp $(SRC)/graphics/model.h
	@$(info Cosmos: Building object $@)
	@$(CXX) -std=c++2a $(DEFINES) -I $(SRC) -I $(DEPS) -c $(SRC)/graphics/model.cpp -o $@

bin/Cosmos/int/vertex_array.obj: $(SRC)/graphics/vertex_array.cpp $(SRC)/graphics/vertex_array.h
	@$(info Cosmos: Building object $@)
	@$(CXX) -std=c++2a $(DEFINES) -I $(SRC) -I $(DEPS) -c $(SRC)/graphics/vertex_array.cpp -o $@

bin/Cosmos/int/vertex_buffer.obj: $(SRC)/graphics/vertex_buffer.cpp $(SRC)/graphics/vertex_buffer.h
	@$(info Cosmos: Building object $@)
	@$(CXX) -std=c++2a $(DEFINES) -I $(SRC) -I $(DEPS) -c $(SRC)/graphics/vertex_buffer.cpp -o $@

bin/Cosmos/int/index_buffer.obj: $(SRC)/graphics/index_buffer.cpp $(SRC)/graphics/index_buffer.h
	@$(info Cosmos: Building object $@)
	@$(CXX) -std=c++2a $(DEFINES) -I $(SRC) -I $(DEPS) -c $(SRC)/graphics/index_buffer.cpp -o $@

bin/Cosmos/int/shader.obj: $(SRC)/graphics/shader.cpp $(SRC)/graphics/shader.h
	@$(info Cosmos: Building object $@)
	@$(CXX) -std=c++2a $(DEFINES) -I $(SRC) -I $(DEPS) -c $(SRC)/graphics/shader.cpp -o $@

# Build math
bin/Cosmos/int/vec2.obj: $(SRC)/math/vec2.cpp $(SRC)/math/vec2.h
	@$(info Cosmos: Building object $@)
	@$(CXX) -std=c++2a $(DEFINES) -I $(SRC) -I $(DEPS) -c $(SRC)/math/vec2.cpp -o $@

bin/Cosmos/int/vec3.obj: $(SRC)/math/vec3.cpp $(SRC)/math/vec3.h
	@$(info Cosmos: Building object $@)
	@$(CXX) -std=c++2a $(DEFINES) -I $(SRC) -I $(DEPS) -c $(SRC)/math/vec3.cpp -o $@

bin/Cosmos/int/vec4.obj: $(SRC)/math/vec4.cpp $(SRC)/math/vec4.h
	@$(info Cosmos: Building object $@)
	@$(CXX) -std=c++2a $(DEFINES) -I $(SRC) -I $(DEPS) -c $(SRC)/math/vec4.cpp -o $@

bin/Cosmos/int/mat4.obj: $(SRC)/math/mat4.cpp $(SRC)/math/mat4.h
	@$(info Cosmos: Building object $@)
	@$(CXX) -std=c++2a $(DEFINES) -I $(SRC) -I $(DEPS) -c $(SRC)/math/mat4.cpp -o $@

bin/Cosmos/int/transform.obj: $(SRC)/math/transform.cpp $(SRC)/math/transform.h
	@$(info Cosmos: Building object $@)
	@$(CXX) -std=c++2a $(DEFINES) -I $(SRC) -I $(DEPS) -c $(SRC)/math/transform.cpp -o $@

# Build GLAD dependency
bin/Cosmos/int/glad.obj: Cosmos/deps/glad/glad.cpp Cosmos/deps/glad/glad.h
	@$(info Cosmos: Building object $@)
	@$(CXX) -std=c++2a $(DEFINES) -I $(SRC) -I $(DEPS) -c Cosmos/deps/glad/glad.cpp -o $@

# Compilation for Sandbox
bin/Sandbox/int/sandbox.obj: Sandbox/src/sandbox.cpp
	@$(info Sandbox: Building object $@)
	@$(CXX) -std=c++2a -D PLATFORM_WINDOWS -I $(SRC) -I $(DEPS) -c Sandbox/src/sandbox.cpp -o $@

# Generate binary directories
.PHONY: dirs
dirs:
	@$(info Make: Build started)
	@$(info Make: Creating directory bin/Cosmos/int/)
	@mkdir bin\\Cosmos\\int\\
	@$(info Make: Creating directory bin/Sandbox/int/)
	@mkdir bin\\Sandbox\\int\\

# Clean the project (remove binaries)
.PHONY: clean
clean:
	@$(info Make: Clean started)
	@$(info Make: Deleting precompiled header $(SRC)/cspch.h.gch)
	@del Cosmos\\src\\cspch.h.gch
	@$(info Make: Deleting directory bin/)
	@rmdir /s /q bin
	@$(info Make: Clean finished)