#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define DESTINATION_NAME 100
#define NOT_FOUND -2


typedef struct __Destination__ {
	char* Name ;

struct __Destination__ *nextDestinationPtr;
} Destination;


Destination* addDestination (Destination **destinations)
{
	Destination * desPtr;
	desPtr = (Destination*)malloc(sizeof(Destination));
	if(*destinations != NULL )
	{
		desPtr -> nextDestinationPtr = *destinations ;
		*destinations = desPtr;
	}
	else
	{
		*destinations = desPtr;
		desPtr -> nextDestinationPtr = NULL;
	}
	return *destinations ;

}

void initializeDestinations(Destination **destinations)
{
	int d = 0;
	Destination* newDestination ;
	newDestination = addDestination(destinations);
	newDestination->Name = strdup ("Shimla");
}


