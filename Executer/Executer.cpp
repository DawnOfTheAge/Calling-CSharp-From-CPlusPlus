// Executer.cpp : Defines the entry point for the console application.
//

#include "stdio.h"
#include "ContextDataManagerWrapper.h"

int main(int argc, char* argv[])
{
	ContextDataManagerWrapper _contextDataManagerWrapper;
	const char** properties;
	char *parameter = {"yosef:david:moshe"};

	printf("[C++ Main]: Calling GetContextData() with parameter(%s)\n", parameter);
	properties = _contextDataManagerWrapper.GetContextData(parameter);
    
	printf("[C++ Main]:\nProperty 1: %s\nProperty 2: %s\nProperty 3: %s\n", properties[0], properties[1], properties[2]);
	getchar();

	return 0;
}

