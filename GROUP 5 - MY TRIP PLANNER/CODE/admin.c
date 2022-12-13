#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct planner
{
    int hotel_id;
    char hotel_name[20];
    char trans_name[20];
}hotel;


typedef enum test_values {
    pass = 1,
    fail = 0
}test_values;

test_values search(int id);

test_values addition(int id,char name[]);

test_values deletehotel(int id);


test_values viewhotel(void);

test_values addition(int id,char name[])
{
   
   
   
    FILE *fp=NULL;
    fp=fopen("trip.dat","ab+");
   
    if(fp == NULL)
    {
        printf("\nError: while opening file\n");
        return fail;
    }
    else{
       
        hotel *newHotel = NULL;
        newHotel = malloc(sizeof(hotel));

        newHotel->hotel_id = id;
        strcpy(newHotel->hotel_name,name);
       
    fwrite(newHotel,sizeof(hotel),1,fp);
    fclose(fp);
    free(newHotel);
   
   
    return pass;
    }

}
test_values deletehotel(int id)
{
   
   
   
    FILE *fp=NULL;
    FILE *ft=NULL;
    fp = fopen("trip.dat","rb");
    ft = fopen("temp.dat","wb");
   
    if(fp==NULL || ft==NULL)
        {
            printf("\nError: While opening file:\n");
            return fail;
        }
    else{
        rewind(fp);
       
        hotel *discarded_hotel = (hotel*)malloc(sizeof(hotel));
    while(fread(discarded_hotel,sizeof(hotel),1,fp)==1)
    {
        if(id != discarded_hotel->hotel_id)
        {
            fwrite(discarded_hotel,sizeof(hotel),1,ft);
        }
    }
    fclose(fp);
    fclose(ft);
    free(discarded_hotel);
 
   remove("trip.dat");
    rename("temp.dat","trip.dat");
   
    return pass;
        }
}
test_values search(int id)
{
   
    FILE *fp=NULL;
    fp = fopen("trip.dat","rb");
    if(fp==NULL)
    {
        printf("\nError while opening file in search area\n");
        return fail;
    }
    else{
   
    hotel *hotel_to_find=(hotel*)malloc(sizeof(hotel));
    while(fread(hotel_to_find,sizeof(hotel),1,fp))
    {
        if(hotel_to_find->hotel_id==id)
        {
           
            printf("\nHotel_Id: %d\t\Hotel_name: %s\t\tTrans_Name: %s",hotel_to_find->hotel_id,hotel_to_find->hotel_name,hotel_to_find->trans_name);
            fclose(fp);
            free(hotel_to_find);
            return pass;
        }
    }
   
    fclose(fp);
    free(hotel_to_find);
    printf("\nSpecified hotel is not present\n");
   
    return fail;
    }
}

test_values viewhotel()
{
   
    FILE *fp=NULL;
    fp=fopen("trip.dat","rb");
   
    if(fp==NULL)
    {
        printf("\nERROR:\n");
        return fail;
    }
    else{
        hotel *hotel_to_find=(hotel*)malloc(sizeof(hotel));
    while(fread(hotel_to_find,sizeof(hotel),1,fp)==1)
    {
        printf("\n%d\t\t\t%s\t\t\t%s",hotel_to_find->hotel_id,hotel_to_find->hotel_name,hotel_to_find->trans_name);
    }
    fclose(fp);
    free(hotel_to_find);
   
    return pass;
    }
}
int main()
{
   
    int id_des,id_hot,id_trans,choice,success,choice2,choice3,choice4;
   
    char dest[20],hotel[20],trans[20];
   
       

    printf("\n\t\t\t\t\t\t*************** MAIN MENU ***************\n");
    printf("\n\t\t\t\t\t\t1. Manage Destination");
    printf("\n\t\t\t\t\t\t2. Manage Hotels");
    printf("\n\t\t\t\t\t\t3. Manage Transport Modes");
    printf("\n\t\t\t\t\t\t4. Check Hotel Bookings");
    printf("\n\t\t\t\t\t\t5. Check Tickets");
    printf("\n\t\t\t\t\t\t6. Quit");
    printf("\n\t\t\t\t\t\t******************************************\n");
    printf("\n\t\t\t\t\t\tEnter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        printf("Choose the option below\n1. Add new Destination\n2. Modify Destination\n3. Delete Destination\n4. Search Destination\n0. Quit\n");
        printf("Enter your choice:");
        scanf("%d",&choice2);
        if(choice2 == 1)
        {
        printf("\nEnter Destination id: ");
        scanf("%d",&id_des);
        printf("\nEnter Destination");
        scanf("%19s",dest);
        success=addition(id_des,dest);
        break;
        }
        else if(choice2 == 2)
        {
        printf("\nEnter Destination id you want to Modify: ");
        scanf("%d",&id_des);
        success=deletehotel(id_des);
        printf("\nEnter New Destination id");
        scanf("%d",&id_des);
        printf("\nEnter Destination");
        scanf("%19s",dest);
        success=addition(id_des,dest);
        break;
        }
        else if(choice2 == 3)
        {
        printf("\nEnter Destination id you want to delete: ");
        scanf("%d",&id_des);
        success=deletehotel(id_des);
        break;
        }
        else if(choice2 == 4)
        {
        printf("\nEnter Destination id you want to search: ");
        scanf("%d",&id_hot);
        success=search(id_hot);
        break;
        }
        else
        {
            break;
        }
       
        case 2:
        printf("Choose the option below\n1. Add new Hotel\n2. Modify Hotel\n3. Delete Hotel\n4. Search Hotel\n0. Quit\n");
        printf("Enter your choice:");
        scanf("%d",&choice3);
        if(choice3 == 1)
        {
        printf("\nEnter Hotel id: ");
        scanf("%d",&id_hot);
        printf("\nEnter Hotel");
        scanf("%19s",hotel);
        success=addition(id_hot,hotel);
        break;
        }
        else if(choice3 == 2)
        {
        printf("\nEnter Hotel id you want to Modify: ");
        scanf("%d",&id_hot);
        success=deletehotel(id_hot);
        printf("\nEnter New Hotel id");
        scanf("%d",&id_hot);
        printf("\nEnter Hotel");
        scanf("%19s",hotel);
        success=addition(id_hot,hotel);
        break;
        }
        else if(choice3 == 3)
        {
        printf("\nEnter Hotel id you want to delete: ");
        scanf("%d",&id_hot);
        success=deletehotel(id_hot);
        break;
        }
        else if(choice3 == 4)
        {
        printf("\nEnter Hotel id you want to search: ");
        scanf("%d",&id_hot);
        success=search(id_hot);
        break;
        }
        else
        {
            break;
        }
       
       
        case 3:
         printf("Choose the option below\n1. Add new Transport mode\n2. Modify Transport Mode\n3. Delete Transport Mode\n4. Search Transport\n0. Quit\n");
        printf("Enter your choice:");
        scanf("%d",&choice4);
        if(choice4 == 1)
        {
        printf("\nEnter Transport id: ");
        scanf("%d",&id_trans);
        printf("\nEnter Two mode of Transport with \ in between");
        scanf("%19s",trans);
        success=addition(id_trans,trans);
        break;
        }
        else if(choice4 == 2)
        {
        printf("\nEnter Transport id you want to Modify: ");
        scanf("%d",&id_trans);
        success=deletehotel(id_trans);
        printf("\nEnter New Transport id");
        scanf("%d",&id_trans);
        printf("\nEnter Two mode of Transport with \ in between");
        scanf("%19s",trans);
        success=addition(id_trans,trans);
        break;
        }
        else if(choice4 == 3)
        {
        printf("\nEnter Transport id you want to delete: ");
        scanf("%d",&id_trans);
        success=deletehotel(id_trans);
        break;
        }
        else if(choice4 == 4)
        {
        printf("\nEnter Transport id you want to search: ");
        scanf("%d",&id_hot);
        success=search(id_hot);
        break;
        }
        else
        {
            break;
        }
       
        default:
        printf("\n\t\t\t\t\t\tInvalid input");
        break;
     }
    if(success == pass)
    {
        printf("Successful\n");
    }
    else if(success==fail)
    {
        printf("Unsuccessful\n");
    }
    else{
        printf("Error\n");
    }
return 0;
}
