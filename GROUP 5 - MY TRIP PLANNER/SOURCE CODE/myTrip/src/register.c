#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<commonMacros.h>

struct registerNode{

	char userId[MAX_SIZE_NAME];
	char password[MAX_SIZE_NAME];
	char username[MAX_SIZE_NAME];
	
	struct registerNode *address;
};
typedef struct registerNode regNode;

regNode *regHead = NULL;
regNode *regTail = NULL;

int addNewUser(char userId[MAX_SIZE_NAME], char password[MAX_SIZE_NAME], char username[MAX_SIZE_NAME])
{
	regNode *temp = malloc(sizeof(regNode));
	
        strcpy(temp->userId, userId);
        strcpy(temp->password, password);
        strcpy(temp->username, username);

	if(regHead == NULL)
	{
		regHead = regTail = temp; //add first node , head and tail point to first node
 		temp->address = NULL;
	}
	else
	{
		regTail->address = temp;  // add at the end of linked list
		temp->address = NULL;
		regTail = temp;
	}
	return 1;
}

void displayRegisteredUsers()
{
	for(regNode *traverse=regHead; traverse!=NULL;traverse=traverse->address)
	{
		int len = strlen(traverse->userId);
		if(traverse->userId[len-1] == '\n' )
			traverse->userId[len-1] = 0;

		printf("\n\t\t\tUsername: ");
		puts(traverse->username);
		printf("\n\t\t\tUser ID: ");
		puts(traverse->userId);
		printf("\n\t\t\tPassword: ");
		puts(traverse->password);
	}
	getchar();
}

int writeToUsersFile()
{
	regNode *temp = regHead;
       	FILE* file; 
	file = fopen ("users.txt", "a");
	if (file == NULL)
	{
		fprintf(stderr, "\nCouldn't Open File'\n");
		exit (1);
	}

	for(regNode *traverse = regHead; traverse != NULL; traverse=traverse->address)
	{
		int len1, len2;
		len1 = strlen(traverse->userId);
                if(traverse->userId[len1-1] == '\n' )
			traverse->userId[len1-1] = 0;
		
		len2 = strlen(traverse->username);
                if(traverse->username[len2-1] == '\n' )
			traverse->username[len2-1] = 0;
		
		fprintf(file,"\n%s," "%s," "%s\n", traverse->userId, traverse->username, traverse->password);
	}
	    fclose(file);	
	return 1;    
}

/*int displayHotelsFileData()
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
}*/


				
