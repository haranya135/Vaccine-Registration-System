# Vaccine-Registration-System
This repository contains the source code for Vaccine Registration System in C.


1.Structures:

     -->struct data: Represents information about a candidate's registration, including registration ID, name, age, gender, date of birth, Aadhaar number, mobile number, email ID, and number of vaccine doses.
     
     -->struct accountid: Represents the user account ID and password.
     
2.Global Variables:

    -->int n, c: Unutilized global variables.
    
    -->char state[20], dis[20], hos[40], date[12], hour[6]: Global variables related to the vaccination venue, date, and time.
    
3.Functions:
    -->void getUserdetails(): Collects candidate details such as name, gender, date of birth, age, Aadhaar number, email ID, mobile number, and the number of vaccine doses. It also generates a registration ID and calls the venue() function.
    -->void venue(): Asks the user to choose a vaccination venue from a list of hospitals and provides options to enter the date and time. It then calls the printdetails() function.
    -->void printdetails(): Prints the candidate's details including the registration ID, name, gender, date of birth, Aadhaar number, mobile number, email ID, number of vaccine doses, chosen hospital, date, and time.
    -->void generateid(): Generates a unique registration ID based on existing IDs stored in a file (id.csv). It also prompts the user to create a password for their registration.
    -->void addata(): Appends the candidate's details along with venue information to a file (MYFILE.csv).
    -->void login(): Authenticates the user by checking their registration ID and password against the stored credentials in the id.csv file.
    -->void getdetails(char* id): Retrieves the details of a candidate based on their registration ID from the MYFILE.csv file.
    -->void details(): Calls the addata() and printdetails() functions to add details to the file and print them.

4.Main Function:
    -->Displays a menu with options to register for a vaccine, check the status, or exit.
    -->Calls the respective functions based on the user's choice.

For more information please refer to the above posted Vaccine Registration System.pdf file.
