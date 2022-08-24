CXX = g++
INC = Cosmos/Include

build:
	mkdir bin\\Cosmos\\int

	$(CXX) -I $(INC) -c Cosmos/Source/Main.cpp -o bin/Cosmos/int/Main.obj
	$(CXX) -I $(INC) -c Cosmos/Source/Test.cpp -o bin/Cosmos/int/Test.obj

	$(CXX) bin/Cosmos/int/Main.obj bin/Cosmos/int/Test.obj -o bin/Cosmos/Cosmos.exe

clean:
	rmdir /s /q bin