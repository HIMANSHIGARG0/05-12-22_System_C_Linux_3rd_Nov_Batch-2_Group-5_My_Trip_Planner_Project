#include<stdio.h>
#include<stdlib.h>
#include<destinations.h>
#include<hotels.h>
#include<register.h>
#include<commonMacros.h>

void welcomeMessage();
void loginScreen();
void adminMenu();
void registerNewUser();
int loginPage();
void manageDestinations();
void manageHotels();

int main()
{
	welcomeMessage();
	loginScreen();
return 0;
}

void welcomeMessage()
{
	system("clear");
	printf("\n\n\n\n\n");
	printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
	printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
	printf("\n\t\t\t        =                  WELCOME                  =");
	printf("\n\t\t\t        =                    TO                     =");
	printf("\n\t\t\t        =                  MY TRIP                  =");
	printf("\n\t\t\t        =               A TRIP PLANNER              =");
	printf("\n\t\t\t        =                                           =");
	printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
	printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
	printf("\n\n\n\t\t\t Enter any key to continue.....");
	getchar();
}

void loginScreen()
{
	int chr;
	printf("1. Register New User\n");
	printf("2. Login\n");
	printf("0. Quit\n");
	printf("Enter Choice: ");
	scanf("%d", &chr);
	getchar();
	switch(chr)
	{
		case 1:
			registerNewUser();
			break;
		case 2:
			loginPage();
                        break;
		case 0:
		      exit(EXIT_FAIL);
	              break;
	}

}
void registerNewUser()
{
	char name[MAX_SIZE_NAME], id[MAX_SIZE_NAME], password[MAX_SIZE_NAME];
	
	printf("\n\t\t\tEnter the details for the Registeration as a New User");
	
	printf("\n\t\t\t\tUser Name: ");
	fgets(name, MAX_SIZE_NAME, stdin);      //Input for name of new user
	
	printf("\n\t\t\t\tUser Id ");
	fgets(id, MAX_SIZE_NAME, stdin);      //Input for id
	
	printf("\n\t\t\t\tPassword: ");
	fgets(password, MAX_SIZE_NAME, stdin);      //Input for password
	addNewUser(name, id, password);            //func call to insert user details in linked list

	displayRegisteredUsers();
	writeToUsersFile();       //func call to write inserted data to users.txt file
	printf("\n\t\t\tRegistered Successfully!\n");
}

int loginPage()
{
	char id[MAX_SIZE_NAME], password[MAX_SIZE_NAME];
	
	printf("\n\t\t\tEnter the details for Login");
	
	printf("\n\t\t\t\tUser Id ");
	fgets(id, MAX_SIZE_NAME, stdin);      //Input for id
	
	printf("\n\t\t\t\tPassword: ");
	fgets(password, MAX_SIZE_NAME, stdin);      //Input for password


	FILE *fp;
        int i = 0, c; //Count no of lines in file
	fp = fopen("users.txt", "r");
	if(fp == NULL){
		printf("Empty file");
		exit(0);
	}
	char name[MAX_SIZE_NAME];
	char pw[MAX_SIZE_NAME];
	while(!feof(fp))   // Checking for end of file
	{

		c = fgetc(fp);   // Taking input single character at a time
		if(c == '\n')
			++i;
	}
	rewind(fp);  // Line I added
	// read each line
	

	while(fscanf(fp, "%s, %s", name, pw) > 0){

		if((!strcmp(name,"admin") == 0) && (!strcmp(pw,"admin123")== 0)) 
		{ 
		//	printf("\n\nLogged In Successful");
	       		adminMenu();	
			break;
		}
		else
		{
			printf("\n\nIncorrect username or password\n"); 
			break;
		}		}
	fclose(fp);
}

void adminMenu()
{
	system("clear");
	printf("\n\n");
	printf("\t\t\t\t****************  ADMIN SCREEN  ****************\n\n\n");
	int ch;
	printf("\t\t\t1. MANAGE DESTINATIONS\n");
	printf("\t\t\t2. MANAGE HOTELS\n");
	printf("\t\t\t3. MANAGE TRANSPORT MODE\n");
	printf("\t\t\t4. CHECK HOTEL BOOKING\n");
	printf("\t\t\t5. CHECK TICKETS\n");
	printf("\t\t\t0. QUIT\n");
	
	printf("\n\t\t\tEnter Choice: ");
	scanf("%d", &ch);
	
	switch(ch)
	{
		case 1:
			manageDestinations();
			printf("\n\n\n\t\t\t Enter any key to continue.....");
			getchar();
			break;
		case 2:
			manageHotels();
			printf("\n\n\n\t\t\t Enter any key to continue.....");
			getchar();
			break;
		case 0: 
			exit(EXIT_FAIL);
	}
}

void manageDestinations()
{

	//int destIdNo; //primary key for destination data
	int destinationCount;  //No. of Destinations Admin wants to manage
        char destinationName[MAX_SIZE_NAME];    //Name of Destination
        int tripCost;    //Cost for whole Trip
        int tripDuration;   //Duration of the Trip

	while(1)
	{
	//system("clear");
	//printf("\n\n");
	printf("\n\n");
	printf("\t******************  DESTINATION SCREEN  ******************\n\n\n");
	
	int ch1; // variable for menu choice
	char data[MAX_SIZE_NAME]; // used in delete data
	printf("\t\t\t1. ADD NEW DESTINATION(S) DETAILS\n");
	printf("\t\t\t2. MODIFY/UPDATE DETAILS\n");
	printf("\t\t\t3. DELETE DESTINATION\n");
	printf("\t\t\t0. QUIT\n");
	
	printf("\n\t\t\tEnter Choice: ");
	scanf("%d", &ch1);
	getchar();
	switch(ch1)
	{
		case 1:
			printf("\n\t\t\tEnter the no of destinations you want to insert: ");
			scanf("%d", &destinationCount);
			getchar();
		
			for(int i = 0; i < destinationCount; i++)
			{
				printf("\n\t\t\tEnter the details of Destination %d", i+1);
				getchar();

				printf("\n\t\t\t\tName of Destination: ");
				fgets(destinationName, MAX_SIZE_NAME, stdin);      //Input for name of destination from admin
		
				printf("\n\t\t\t\tCost of Trip (Rs): ");      //Input for cost of trip from admin
	           		scanf("%d", &tripCost);
				
				printf("\n\t\t\t\tTrip Duration(in days): ");     //Input for duration of trip from admin
				scanf("%d", &tripDuration);
				
				addNewDestination(destinationName, tripCost, tripDuration);            //func call to insert destination details in linked list
			} 
			displayDestinationDetails();
			appendToDestinationsFile();       //func call to write inserted data to destinations.txt file
			printf("\n\t\t\tDestination Details successfully added to the file!\n");
			break;
		case 2:
			displayDestinationsFileData();
			break;
		case 3:
			printf("Enter name of destination whose data to be deleted: ");
			scanf("%s", &data);
			getchar();
		     	if (delete(data) == EXIT_SUCC)
			{
				printf("%d successfully deleted", data);
				writeToDestinationsFile();       //func call to write inserted data to destinations.txt file
				printf("Successfully written the file again");
			}
			else{
				printf("\ndoesnot exist!\n");
			}
			break;
		case 0: 
			exit(EXIT_FAIL);
	}

	}
}	

void manageHotels()
{
	int hotelsCount;  //No. of hotels Admin wants to manage
	char hotelName[MAX_SIZE_NAME];    //Name of hotel
	int fare;    //fare of room per day
	int rating;   //ratings of hotels 
	while(1)
	{
		//system("clear");
		//printf("\n\n");

		printf("\n\n");
		printf("\t******************  HOTEL SCREEN  ******************\n\n\n");

		int ch2; // variable for menu choice
		char data[MAX_SIZE_NAME]; // used in delete data
		printf("\t\t\t1. ADD NEW HOTEL\n");
		printf("\t\t\t2. MODIFY HOTEL\n");
		printf("\t\t\t3. DELETE HOTEL\n");
		printf("\t\t\t0. QUIT\n");

		printf("\n\t\t\tEnter Choice: ");
		scanf("%d", &ch2);
		getchar();

		switch(ch2)
		{
			case 1:
				printf("\n\t\t\tEnter the no of hotels you want to insert: ");
				scanf("%d", &hotelsCount);
				getchar();

				for(int i = 0; i < hotelsCount; i++)
				{
					printf("\n\t\t\tEnter the details of Hotels %d", i+1);
					getchar();
				
					printf("\n\t\t\t\tName of Hotel: ");
					fgets(hotelName, MAX_SIZE_NAME, stdin);      //Input for name of hotel from admin

					printf("\n\t\t\t\tFare of a Room per Day (Rs): ");      //Input for fare per day for a room from admin
					scanf("%d", &fare);
			
					printf("\n\t\t\t\tRatings of the Hotel (out of 5): ");     //Input for ratings from admin
					scanf("%d", &rating);
			
					addNewHotels(hotelName, fare, rating);            //func call to insert hotel details in linked list
				}

				displayHotelDetails();
				writeToHotelsFile();       //func call to write inserted data to hotels.txt file
				printf("\n\t\t\tDetails of Hotels Successfully added to the file!\n");
				break;
			case 2:
				printf("\n\t\t\tDisplaying Data from file to LL!\n");
				displayHotelsFileData();
				break;
			case 3:
				printf("Enter name of hotel whose data you want to remove: ");
				scanf("%s", &data);
				getchar();
				if (deleteHotel(data) == EXIT_SUCC)
					printf("\n%s deleted!\n");
				else
					printf("\ndoesnot exist!\n");
				//displayDestinationDetails();     //func call to display details of trip inserted in linked list by admin									                   //displayDestinationsFileData();
	               		break;		
			case 0:
		      	 	exit(EXIT_FAIL);
	}

	}
}
