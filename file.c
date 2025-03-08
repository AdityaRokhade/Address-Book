#include<stdio.h>
#include"file.h"
//Function to load contacts from the file to structure
void loadContactsFromFile(AddressBook *addressBook)
{
    //Open file
    FILE *fptr= fopen("contacts.txt","r");
    //Returns NULL if file doesnt exist
    if(fptr==NULL)
    {
        printf("File doesn't exist\n");
    }
    else
    {
        //fetch count
        fscanf(fptr,"%d\n",&addressBook->contactCount);
        //Copy contacts to structure
        for(int i=0; i<addressBook->contactCount; i++)
        {
            fscanf(fptr,"%[^,],%[^,],%[^\n]\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        }
    }
    //Close file
    fclose(fptr);
}
//Function to save contacts to file from structure
void saveContactsToFile(AddressBook *addressBook)
{
    //Open file
    FILE *fptr=fopen("contacts.txt","w");
    //Write contacts count to 1st line of the file
    fprintf(fptr,"%d\n",addressBook->contactCount);
    //Write structure to the file
    for(int i=0; i<addressBook->contactCount; i++)
    {
        fprintf(fptr,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    //Close the file
   fclose(fptr);
}