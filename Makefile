# MAKEFILE FOR COSMOS

# Makefile Variables & Macros
CXX = g++
SRC = Cosmos/src
DEPS = Cosmos/deps	
DEFINES = -D PLATFORM_WINDOWS -D BUILD_TYPE_DLL
OBJS = application.obj logger.obj window.obj model.obj vertex_array.obj vertex_buffer.obj index_buffer.obj shader.obj vec2.obj vec3.obj vec4.obj mat4.obj transform.obj glad.obj 
OBJLIST = $(patsubst %,bin/Cosmos/int/%,$(OBJS))

# Targets to be initialized
all: dirs bin/Cosmos/Cosmos.dll bin/Sandbox/Sandbox.exe

# Link the generated object files
# Link Cosmos
bin/Cosmos/Cosmos.dll: $(SRC)/cspch.h.gch $(OBJLIST)
	@$(info Cosmos: Linking shared library $@)
	@$(CXX) -shared -LCosmos/lib $(OBJLIST) -lglfw3 -lopengl32 -lgdi32 -o $@

# Link Sandbox
bin/Sandbox/Sandbox.exe: bin/Sandbox/int/sandbox.obj
	@$(info Sandbox: Linking executable $@)
	@$(CXX) $< bin/Cosmos/Cosmos.dll -o $@
	@$(info Make: Build finished)

# Build the project (generate binaries)
# Compilation for Cosmos
# Build precompiled header (PCH)
$(SRC)/cspch.h.gch: $(SRC)/cspch.h
	@$(info Cosmos: Generating precompiled header $@)
	@$(CXX) -std=c++2a $(DEFINES) -I $(SRC) -I $(DEPS) -c $<

# Build core
bin/Cosmos/int/%.obj: $(SRC)/core/%.cpp $(SRC)/core/%.h
	@$(info Cosmos: Building object $@)
	@$(CXX) -std=c++2a $(DEFINES) -I $(SRC) -I $(DEPS) -c $< -o $@

# Build graphics
bin/Cosmos/int/%.obj: $(SRC)/graphics/%.cpp $(SRC)/graphics/%.h
	@$(info Cosmos: Building object $@)
	@$(CXX) -std=c++2a $(DEFINES) -I $(SRC) -I $(DEPS) -c $< -o $@

# Build math
bin/Cosmos/int/%.obj: $(SRC)/math/%.cpp $(SRC)/math/%.h
	@$(info Cosmos: Building object $@)
	@$(CXX) -std=c++2a $(DEFINES) -I $(SRC) -I $(DEPS) -c $< -o $@

# Build GLAD dependency
bin/Cosmos/int/glad.obj: Cosmos/deps/glad/glad.cpp Cosmos/deps/glad/glad.h
	@$(info Cosmos: Building object $@)
	@$(CXX) -std=c++2a $(DEFINES) -I $(SRC) -I $(DEPS) -c $< -o $@

# Compilation for Sandbox
bin/Sandbox/int/sandbox.obj: Sandbox/src/sandbox.cpp
	@$(info Sandbox: Building object $@)
	@$(CXX) -std=c++2a -D PLATFORM_WINDOWS -I $(SRC) -I $(DEPS) -c $< -o $@

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