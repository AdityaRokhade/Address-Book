Address Book Project Documentation
Project Overview
The Address Book Project is a console-based application written in the C programming language. It provides functionalities to store and manage contact information such as names, telephone or mobile numbers, and email addresses. The project focuses on fundamental C programming concepts, including command-line arguments, input parsing, and file operations, without relying on Abstract Data Types (ADTs).

Features
The application supports the following operations:

1. Add Contact
Add a new contact with username:
Enter the name of the contact.
Provide one or more phone numbers.
Provide one or more email addresses.
2. Search Contact
Search by name: Locate a contact using the name.
Search by phone number: Find a contact associated with a given phone number.
Search by email address: Find a contact associated with a specific email address.
3. Edit Contact
Edit by name: Modify the contact details based on the name.
Edit by phone number: Update the details associated with a phone number.
Edit by email address: Change the contact information linked to an email.
4. Delete Contact
Delete by name: Remove a contact using the name.
Delete by phone number: Delete the contact linked to a given phone number.
Delete by email address: Remove the contact associated with an email.
5. List All Contacts
Display all stored contacts with their associated details.
6. Save the Address Book
Save the address book to a file to persist the data.
7. Exit Application
Safely exit the application.
Key Concepts Utilized
This project leverages several essential features of the C programming language:

1. Command-Line Arguments
Used for initializing the application or specifying data files.
2. Input Parsing
Efficient handling of user input for names, phone numbers, and email addresses.
3. File Operations
Read and write operations to store and retrieve contact information.
4. Control Structures
Loops and conditionals to manage application logic.
Advanced Extensions
As an advanced exercise, this project can be extended by:

Implementing Abstract Data Types (ADTs) such as linked lists or hash tables.
Using more sophisticated search algorithms for optimized resource usage.
Enhancing the user interface.
Introducing data encryption for secure storage.
Building and Running the Project
Compilation
To compile the project, use the following command:

gcc -o address_book address_book.c
Running the Application
./address_book
Sample Usage
Add a new contact:

Enter the name: "John Doe"
Phone number: "1234567890"
Email: "johndoe@example.com"
Search for a contact by name:

Enter the name: "John Doe"
Edit contact details:

Choose to edit by name, phone number, or email.
Delete a contact by phone number:

Enter the phone number: "1234567890"
Save and exit:

Select the "Save" option and confirm exit. This project will help you strengthen your understanding of core C programming concepts and their application to real-world use cases. Happy coding!
