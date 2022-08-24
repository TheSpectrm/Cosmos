CXX = g++

build:
	mkdir bin\\Cosmos\\int
	$(CXX) -c Cosmos/Source/Main.cpp -o bin/Cosmos/int/Main.obj
	$(CXX) bin/Cosmos/int/Main.obj -o bin/Cosmos/Cosmos.exe

clean:
	rmdir /s /q bin