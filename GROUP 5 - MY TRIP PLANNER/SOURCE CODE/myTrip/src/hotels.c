#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<commonMacros.h>

struct hotelsNode{

	char hotelName[MAX_SIZE_NAME];
	int fare;
	int rating;
	
	struct hotelsNode *address;
};
typedef struct hotelsNode hotelsNode;

hotelsNode *hotelHead = NULL;
hotelsNode *hotelTail = NULL;

int addNewHotels(char hotelName[MAX_SIZE_NAME], int fare, int rating)
{
	hotelsNode *temp = malloc(sizeof(hotelsNode));
	
        strcpy(temp->hotelName, hotelName);
	temp->fare = fare;
	temp->rating = rating;

	if(hotelHead == NULL)
	{
		hotelHead = hotelTail = temp; //add first node , head and tail point to first node
 		temp->address = NULL;
	}
	else
	{
		hotelTail->address = temp;  // add at the end of linked list
		temp->address = NULL;
		hotelTail = temp;
	}
	return 1;
}

void displayHotelDetails()
{
	for(hotelsNode *traverse=hotelHead; traverse!=NULL;traverse=traverse->address)
	{
		int len = strlen(traverse->hotelName);
		if(traverse->hotelName[len-1] == '\n' )
			traverse->hotelName[len-1] = 0;

		printf("\n\t\t\tHotel Name: ");
		puts(traverse->hotelName);
		printf("\t\t\tFare of Room per Day: %d\n", traverse->fare);
		printf("\t\t\tHotel Ratings: %d\n",traverse->rating);
	}
	getchar();
}

int writeToHotelsFile()
{
	hotelsNode *temp = hotelHead;
       	FILE* file; 
	file = fopen ("hotels.txt", "a");
	if (file == NULL)
	{
		fprintf(stderr, "\nCouldn't Open File'\n");
		exit (1);
	}

	for(hotelsNode *traverse = hotelHead; traverse != NULL; traverse=traverse->address)
	{
		int len = strlen(traverse->hotelName);
                if(traverse->hotelName[len-1] == '\n' )
			traverse->hotelName[len-1] = 0;
		fprintf(file,"\n%s," "%d," "%d\n", traverse->hotelName, traverse->fare, traverse->rating);
	}
	    fclose(file);	
	return 1;    
}

void modifyHotelDetails(char hotelName, int fare, int rating)
{
	if(head==NULL) {
		printf("Linked List not initialized");
		return;
	} 
	while(tail->address!=NULL) {
	
		if(strcpy(tail->hotelName, hotelName) == 0) {
			
			strcpy(tail->hotelName, hotelName);
			tail->fare = fare;
			tail->rating = rating;
			return;
		}

		tail = tail->address;
		//pos++;
	}

	printf("%d does not exist in the list\n", hotelName);
}

int insertModifiedHotelData()
{
	int hotelCount;  //No. of hotels Admin wants to update
	char hotelName[MAX_SIZE_NAME];    //Name of hotel
	int fare;    //Cost for per day hotel room
	int rating;   //hotel rating out of 5

	printf("\n\t\t\tEnter the no of destinations you want data to be modified for: ");
	scanf("%d", &hotelCount);
	
	for(int i = 0; i < hotelCount; i++)
	{

		printf("\n\t\t\tEnter the details of Hotels %d", i+1);
		printf("\n\t\t\t\tName of hotel: ");
		fgets(hotelName, MAX_SIZE_NAME, stdin);      //Input for name of hotel from admin
	
		printf("\n\t\t\t\tFare of Room peer day (Rs): ");      //Input for cost of room from admin
		scanf("%d", &fare);

		printf("\n\t\t\t\tRatings of hotel: ");     //Input for ratings from admin
		scanf("%d", &rating);
		getchar();
		modifyDestinationDetails(hotelName, fare, rating);
	}
	return 1;
}

int displayHotelsFileData()
{
	FILE *fp;
	int i = 0; //Count no of lines in file
	fp = fopen("hotels.txt", "r");
	if(fp == NULL){
		printf("Empty file");
		exit(0);
	}
	char name[MAX_SIZE_NAME];
	int cost, stars, c;
        while(!feof(fp))   // Checking for end of file
       	{
		c = fgetc(fp);   // Taking input single character at a time
		if(c == '\n')
			++i;
	}
    	rewind(fp);  // Line I added
	// read each line 
	
        while(fscanf(fp, "%s, %d, %d ", name, cost, stars) > 0)
	{		
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


int deleteHotel(char data) 
{
	hotelsNode *prev = NULL, *temp = NULL;
	for (temp = hotelHead; temp != hotelTail->address; temp = temp->address)
	{
		if (strcmp(temp->hotelName, data) == 0)
			break;
		prev = temp;
	}
	if (temp == NULL) { 
		printf("%s not found!", data);
		return 0;
	}
	if (temp == hotelHead)
		hotelHead = hotelHead->address;
	else { 
		if (temp == hotelTail)
		{  
			prev->address = NULL;
			hotelTail = prev;   
		}
		else { 
			prev->address = temp->address;
		}
	}

	free(temp);
	return 1;
} 
				
