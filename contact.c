/*
NAme:Aditya Rokhade
Date:24/09/2024
Discription:WAP for AddressBook
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
//function to list contacts 
void listContacts(AddressBook *addressBook) //function for list contact
{

    if(addressBook->contactCount==0)//if contact count is zero
    {
        printf("NO data found\n");//print no data found
    }
    else
    {
    for(int i=0;i<addressBook->contactCount;i++)//if contact count not zero list all details
    {
        printf("Name: %-20sphone: %-20sEmail: %-20s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);//detais 
    }
    
}}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    //populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}
//function to save contact
void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    //exit(EXIT_SUCCESS); // Exit the program
}
//function to create contact
void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
    printf("Enter name:\n");
    int flag=0;
    while(flag==0)
    {
    scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].name);
    
        int i=0;
        while(addressBook->contacts[addressBook->contactCount].name[i])
        {//if it alpha we will  acccept input
        if(isalpha(addressBook->contacts[addressBook->contactCount].name[i])||addressBook->contacts[addressBook->contactCount].name[i]==' ')
        {
            flag=1;
        }
        else{
            printf("Name is not fopund   \n");
            printf("enter valid name\n");
            flag=0;
            break;
        }

        i++;
        }
    }
    printf("Enter mobile number\n");
    flag=0;
    while(flag==0){
    scanf("%s",addressBook->contacts[addressBook->contactCount].phone);//read phone number
    int i=0;
    int count=0;
        while(addressBook->contacts[addressBook->contactCount].phone[i])
        {//if mobile num id digits then 
        if(isdigit(addressBook->contacts[addressBook->contactCount].phone[i]))
        {
            count++;
            flag=1;
        }
        else{
            printf("phone  is not valid  \n");
            printf("enter valid phone \n");
            flag=0;
            break;
        }

        i++;
        }
        if(count==10)
        {
            for (int i=0;i<addressBook->contactCount;i++)
            {
                if(!strcmp(addressBook->contacts[i].phone,addressBook->contacts[addressBook->contactCount].phone))
                {
                    printf("phone number exist\n");
                    flag=0;
                    break;
                }
                else{
                    flag=1;
                }
            }

        }
        else{
            printf("Enter valid mobile number\n");
            flag=0;

        }
        }

    printf("Enter Email\n");
     flag=0;
     while(flag==0)
     {
    scanf("%s",addressBook->contacts[addressBook->contactCount].email);//read mail

    if(strchr(addressBook->contacts[addressBook->contactCount].email,'@')&&strstr(addressBook->contacts[addressBook->contactCount].email,".com"))
    {
        for (int i=0;i<addressBook->contactCount;i++)
        {
            if(!strcmp(addressBook->contacts[i].email,addressBook->contacts[addressBook->contactCount].email))
            {
                printf("Email already exist \n");
                flag=0;
                break;
            }
            else{
                flag=1;
            }

        }
    
        

    }
    else{
        printf("Enter valid email\n");
        flag=0;
    }
    }
    addressBook->contactCount++;

   saveAndExit(addressBook); //to update file so we save

    
}

//  function to search contact
void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    printf("\n 1.Based on name \n 2.Based on phone \n3.based on email ");
   int  option;
   printf("Enter the choice: ");
    scanf("%d",&option);//reading which op to perform based on opyion
    switch(option)
    {
        case 1:
            char str[100];
            scanf(" %[^\n]",str);//reading name
            int i;
            for ( i=0;i<addressBook->contactCount;i++)
            {
            if(!strcmp(addressBook->contacts[i].name,str))//checking user enterd name with available data
            {
                int c=0;
                for (int j=0;j<addressBook->contactCount;j++){
                    if(!strcmp(addressBook->contacts[j].name,str)){//checking name
                        c++;
                    }
                      
                }
                 if(c==1)
                    {
                    printf("Name:%s \nphone %s\nEmail %s",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                    break;
                    }
                       else{
            printf("same name exist try with mobile number\n");
            char str[11];
            int flag=0;
            while(flag==0){
            scanf(" %s",str);
        
            for(int i=0;i<addressBook->contactCount;i++)
            {
                if(!strcmp(addressBook->contacts[i].phone,str))//checking phone 
                {
                    printf("Name:%s \nphone %s\nEmail %s",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                    flag=1;
                    break;
                }
                
            }
            if(flag==0)
            {
                printf("Mobile number not valid enter again\n");

            }

           }
           break;

            }
           }
            }
        
        
           break;
        case 2:
                char phone[11];
                scanf("%s",phone);//read phone number
               for(int i=0;i<addressBook->contactCount;i++)
                {
                  
                  if(!strcmp(addressBook->contacts[i].phone,phone))//checking
                  {
                    printf("Name:%s \nphone %s\n Email %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);

                  }
                }
                break;
        case 3:char mail[100];
              scanf(" %[^\n]",mail);//read mail
              for(int i=0;i<addressBook->contactCount;i++)
              {
                if(!strcmp(addressBook->contacts[i].email,mail))
                {
                    printf("Name:%s \nphone %s\n Email %s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
                }
              }
              break;
        default:
        printf("\ninvalid option");//if option other than given
    }
}
//function to edit contact details
void editContact(AddressBook *addressBook)
{
    printf("\n1. Name\n2. Phone\n3. Email\n");//ask user on which to edit
    int choice;
    scanf("%d", &choice);//read choice

    switch (choice)
    {
        case 1:
        {
            int flag = 0;
            do
            {
                printf("\nEnter the name to be edited: ");
                char Name[50];
                getchar(); // Clear  buffer
                scanf("%[^\n]", Name);

                // Count same name
                int nameCount = 0;
                int nameIndexes[10]; 
                for (int i = 0; i < addressBook->contactCount; i++)
                {
                    if (!strcmp(addressBook->contacts[i].name, Name))
                    {
                        nameIndexes[nameCount++] = i; 
                    }
                }

                if (nameCount == 0)//if not found
                {
                    printf("\nName not found.\n");
                }
                else if (nameCount == 1)
                {
                    // Only one contact with the same name
                    flag = 1;
                    int idx = nameIndexes[0];
                    printf("\nEnter new name: ");
                    getchar(); // Clear buffer
                    scanf("%[^\n]", addressBook->contacts[idx].name);
                }
                else
                {
                    // Multiple contacts 
                    printf("Multiple contacts with the same name exist.\nPlease enter the phone number to identify the contact: ");
                    char phone[15];
                    scanf("%s", phone);

                    for (int i = 0; i < nameCount; i++)
                    {
                        int idx = nameIndexes[i];
                        if (!strcmp(addressBook->contacts[idx].phone, phone))//checking
                        {
                            flag = 1;
                            printf("\nEnter new name: ");
                            getchar(); // Clear buffer
                            scanf("%[^\n]", addressBook->contacts[idx].name);//edit new name
                            break;
                        }
                    }

                    if (!flag)//if not match
                    {
                        printf("\nPhone number did not match any contact with the given name.\n");
                        break;
                    }
                }
            } while (!flag);
            break;

        
    }


        case 2:
              int flag = 0;
                do
                {
                    printf(" phone number you want to edit: \n");
                        char phone[10];
                        getchar(); // Clear input buffer
                        scanf("%s", phone);
                        for (int i = 0; i < addressBook->contactCount; i++)
                        {
                        
                            if (strcmp(addressBook->contacts[i].phone, phone) == 0)
                            {
                                flag = 1;
                                printf("\nEnter new phone number: ");
                                scanf("%s", addressBook->contacts[i].phone);
                                getchar(); 
                                break;
                            }
                        }

                        if (!flag)
                        {
                            printf("\nPhone number did not match any contact with the given name.\n");
                        }
                } while (!flag);
                    break;

        case 3:
              int sett=0;
              do
              {
                printf("\n Enter email should be edited:");
                char maill[10];
                getchar();
                scanf("%[^\n]",maill);
                for(int i=0;i<addressBook->contactCount;i++)
                {
                    if(!strcmp(addressBook->contacts[i].email,maill))//checking
                    {
                        sett=1;
                        printf("\n enter new  mail to be edited");
                        scanf("%s",addressBook->contacts[i].email);
                        break;
                    }
                }if(!sett)
                {
                    printf("\n Email not found");//if not available
                }

              } while(!sett);
              break;
    
    
        default:
        {
            printf("\n INvalid choice");
        }     
    }
    saveAndExit(addressBook);//to save edited details
}
//function to delete contact
void deleteContact(AddressBook *addressBook)
{
    int flag = 0;
    while(flag == 0)
    {
        char delname[50]; 
        printf("Enter name to delete: ");
        getchar(); 
        scanf("%[^\n]", delname); // Read name

        int found = 0;
        int count = 0;

        // Search for the name in the contacts list
        for (int i = 0; i < addressBook->contactCount; i++) 
        {
            if (!strcmp(addressBook->contacts[i].name, delname)) // If found
            {
                count++;
            }
        }

        if (count == 0)
        {
            printf("Name not found\n");
            flag = 0; 
        }
        else if (count == 1) 
        {
            flag = 1; // Exit outer loop

            for (int i = 0; i < addressBook->contactCount; i++)
            {
                if (strcmp(addressBook->contacts[i].name, delname) == 0) // Match found
                {
                    
                    for (int j = i; j < addressBook->contactCount - 1; j++)
                    {
                        addressBook->contacts[j] = addressBook->contacts[j + 1];
                    }
                    addressBook->contactCount--; // Decrement the count
                    printf("Contact deleted successfully.\n");
                    break; // Break after deleting the contact
                }
            }
        }
        else // If multiple contacts with the same name
        {
            int flag1 = 0;
            flag = 1; // Exit outer loop
            while (flag1 == 0)
            {
                printf("Multiple names found. Try with phone number: ");
                char ph[11]; 
                scanf("%s", ph); // Read phone number

                // Search for the matching phone number
                for (int i = 0; i < addressBook->contactCount; i++)
                {
                    if (!strcmp(addressBook->contacts[i].phone, ph)) // Match found
                    {
                        flag1 = 1; // Phone number found

                        // Shift 
                        for (int j = i; j < addressBook->contactCount - 1; j++)
                        {
                            addressBook->contacts[j] = addressBook->contacts[j + 1];
                        }
                        addressBook->contactCount--; // Decrement the count
                        printf("Contact deleted successfully.\n");
                        break; 
                    }
                }

                if (!flag1)
                {
                    printf("Mobile number does not exist. Try again.\n");
                }
            }
        }
        saveAndExit(addressBook);//save the deleted mean update the file
    }
}