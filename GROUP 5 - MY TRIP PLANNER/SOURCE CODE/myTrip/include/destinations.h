#ifndef DESTINATIONS_H
#define DESTINATIONS_H

int addNewDestination(char destinationName[], int tripCost, int tripDuration);
void displayDestinationDetails();
int writeToDestinationsFile();
int appendToDestinationsFile();
int displayDestinationsFileData();
int delete(char *data);
void modifyDestinationDetails(char destinationName, int tripCost, int tripDuration);
int insertModifiedDestData();
#endif
