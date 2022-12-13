#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<commonMacros.h>

struct destinationsNode{

	char destinationName[MAX_SIZE_NAME];
	int tripCost;
	int tripDuration;
	
	struct destinationNode *address;
};
typedef struct destinationsNode destNode;

destNode *head = NULL;
destNode *tail = NULL;

int addNewDestination(char destinationName[MAX_SIZE_NAME], int tripCost, int tripDuration)
{
	destNode *temp = malloc(sizeof(destNode));
	
        strcpy(temp->destinationName, destinationName);
	temp->tripCost = tripCost;
	temp->tripDuration = tripDuration;

	if(head == NULL)
	{
		head = tail = temp; //add first node , head and tail point to first node
 		temp->address = NULL;
	}
	else
	{
		tail->address = temp;  // add at the end of linked list
		temp->address = NULL;
		tail = temp;
	}
	return 1;
}

void displayDestinationDetails()
{
	for(destNode *traverse=head; traverse!=NULL;traverse=traverse->address)
	{
		int len = strlen(traverse->destinationName);
		if(traverse->destinationName[len-1] == '\n' )
			traverse->destinationName[len-1] = 0;

		printf("\n\t\t\tDestination Name: ");
		puts(traverse->destinationName);
		printf("\t\t\tCost of Trip: %d\n", traverse->tripCost);
		printf("\t\t\tDuration of Trip: %d\n",traverse->tripDuration);
	}
	getchar();
}

int writeToDestinationsFile()
{
	destNode *temp = head;
       	FILE* file; 
	file = fopen ("destinations.txt", "w+");
	if (file == NULL)
	{
		fprintf(stderr, "\nCouldn't Open File'\n");
		exit (1);
	}

	for(destNode *traverse = head; traverse != NULL; traverse=traverse->address)
	{
		int len = strlen(traverse->destinationName);
                if(traverse->destinationName[len-1] == '\n' )
			traverse->destinationName[len-1] = 0;
		fprintf(file,"\n%s," "%d," "%d\n", traverse->destinationName, traverse->tripCost, traverse->tripDuration );
	}
	    fclose(file);	
	return 1;    
}


int appendToDestinationsFile()
{
	destNode *temp = head;
       	FILE* file; 
	file = fopen ("destinations.txt", "a");
	if (file == NULL)
	{
		fprintf(stderr, "\nCouldn't Open File'\n");
		exit (1);
	}

	for(destNode *traverse = head; traverse != NULL; traverse=traverse->address)
	{
		int len = strlen(traverse->destinationName);
                if(traverse->destinationName[len-1] == '\n' )
			traverse->destinationName[len-1] = 0;
		fprintf(file,"\n%s," "%d," "%d\n", traverse->destinationName, traverse->tripCost, traverse->tripDuration );
	}
	    fclose(file);	
	return 1;    
}


void modifyDestinationDetails(char destinationName, int tripCost, int tripDuration)
{
	if(head==NULL) {
		printf("Linked List not initialized");
		return;
	} 
	tail = head;
	while(tail->address!=NULL) {
	
		if(strcpy(tail->destinationName, destinationName) == 0) {
			
			strcpy(tail->destinationName, destinationName);
			tail->tripCost = tripCost;
			tail->tripDuration = tripDuration;
			return;
		}

		tail = tail->address;
	}

	printf("%d does not exist in the list\n", destinationName);
}

int insertModifiedDestData()
{
	int destinationCount;  //No. of Destinations Admin wants to update
	char destinationName[MAX_SIZE_NAME];    //Name of Destination
	int tripCost;    //Cost for whole Trip
	int tripDuration;   //Duration of the Trip

	printf("\n\t\t\tEnter the no of destinations you want data to be modified for: ");
	scanf("%d", &destinationCount);
	
	for(int i = 0; i < destinationCount; i++)
	{

		printf("\n\t\t\tEnter the details of Destination %d", i+1);
		printf("\n\t\t\t\tName of Destination: ");
		fgets(destinationName, MAX_SIZE_NAME, stdin);      //Input for name of destination from admin
	
		printf("\n\t\t\t\tCost of Trip (Rs): ");      //Input for cost of trip from admin
		scanf("%d", &tripCost);

		printf("\n\t\t\t\tTrip Duration(in days): ");     //Input for duration of trip from admin
		scanf("%d", &tripDuration);
		getchar();
		modifyDestinationDetails(destinationName, tripCost, tripDuration);
	}
	return 1;
}

int displayDestinationsFileData()
{
	FILE *fp;
	int i = 0; //Count no of lines in file
	fp = fopen("destinations.txt", "r");
	if(fp == NULL){
		printf("Empty file");
		exit(0);
	}
	char name[MAX_SIZE_NAME];
	int cost, duration, c;
	while(!feof(fp))   // Checking for end of file
	{
		c = fgetc(fp);   // Taking input single character at a time
		if(c == '\n')
			++i;
	}
	rewind(fp);  // Line I added
	// read each line

    	while(fscanf(fp, "%s, %d, %d ", name, cost, duration) > 0)
	{
		addNewDestination(name, cost, duration);

		char* token ;
		token =	strtok(name, ",");
		while(token != NULL)
		{
			printf("%s\t", token);
		 	token = strtok(NULL, ",");
		}
		printf("\n");
	}
	fclose(fp);
	return 1;			  
}


int delete(char *data) 
{
	destNode *prev = NULL, *temp = NULL;
	for (temp = head; temp != tail->address; temp = temp->address)
	{
		if (strcmp(temp->destinationName, data) == 0)
			break;
		prev = temp;
	}
	if (temp == NULL) { 
		printf("%s not found!", data);
		return 0;
	}
	if (temp == head)
		head = head->address;
	else { 
		if (temp == tail)
		{  
			prev->address = NULL;
			tail = prev;   
		}
		else { 
			prev->address = temp->address;
		}
	}

	free(temp);
	return 1;
} 
				
