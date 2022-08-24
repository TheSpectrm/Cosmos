CXX = g++
INC = Cosmos/Include

build:
	mkdir bin\\Cosmos\\int
	mkdir bin\\Sandbox\\int

	$(CXX) -I $(INC) -c Cosmos/Source/Test.cpp -o bin/Cosmos/int/Test.obj
	$(CXX) -shared bin/Cosmos/int/Test.obj -o bin/Cosmos/Cosmos.dll

	$(CXX) -c Sandbox/Source/Main.cpp -o bin/Sandbox/int/Main.obj
	$(CXX) bin/Sandbox/int/Main.obj bin/Cosmos/Cosmos.dll -o bin/Sandbox/Sandbox.exe

clean:
	rmdir /s /q bin