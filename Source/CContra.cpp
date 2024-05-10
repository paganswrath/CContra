#include "CoreLogic.hpp"
#include "Runtime.hpp"

/*
	This Project uses https://github.com/vermiceli/nes-contra-us
	as a Reference for the game logic.
*/


int main(int argc, char **argv)
{

	if (IsFolderEmpty("Runtime/Assets/")){
		DumpAssets();
	}
	
	return 0;
}

