#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct data {
    char regid[10];
    char name[20];
    char age[10];
    char g[10];
    char dob[20];
    char aid[20];
    char mob[20];
    char eid[100];
    char dose[2];
} dt;

struct accountid {
    char id[10];
    char pass[16];
} idt;

// Global Variables
int n, c = 0;
char state[20], dis[20], hos[40], date[12], hour[6];

// Declaring Function Used In This Program
void getUserdetails();
void venue();
void printdetails();
void generateid();
void addata();
void login();
void getdetails(char* id);
void details();

// Function to Clear Input Buffer
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Driver Code
int main() {
    int ch;
    printf("***Vaccine Registration System***\n");
    printf("Enter Your Choice:\n1.Register for Vaccine\n2.Check Your Status\n3.Exit\n");
    scanf("%d", &ch);
    clearBuffer();
    switch (ch) {
        case 1:
            getUserdetails();
            break;
        case 2:
            login();
            printdetails();
            break;
        case 3:
            break;
        default:
            printf("Choice doesn't exist");
    }
    return 0;
}

void login() {
    char id[10], pass[16], *token, row[100];
    FILE *fp;
    printf("Enter your registration id: ");
    fgets(id, sizeof(id), stdin);
    strtok(id, "\n");
    fflush(stdin);  // Remove newline character
    printf("Enter your Password:");
    fgets(pass, sizeof(pass), stdin);
    strtok(pass, "\n"); 
    fflush(stdin); // Remove newline character
    fp = fopen("id.csv", "r+");
    while (!feof(fp)) {
        fgets(row, sizeof(row), fp);
        token = strtok(row, ",");
        if (strcmp(token, id) == 0) {
            strcpy(idt.id, token);
            token = strtok(NULL, ",");
            strcpy(idt.pass, token);
            break;
        }
    }
    fseek(fp, 0, SEEK_SET);  // Reposition file pointer to the beginning
    while (1) {
        if (strcmp(idt.pass, pass) == 0) {
            printf("Successfully logged in...\nFetching your details...");
            getdetails(id);
            printdetails();  // Add this line
            break;
        } else {
            printf("Wrong Password! Try Again.");
            fgets(pass, sizeof(pass), stdin);
            strtok(pass, "\n");  // Remove newline character
        }
    }
    fclose(fp);
}


void generateid() {
    char row[100], *token, t[10];
    int i;
    FILE *fp;
    fp = fopen("id.csv", "r+");
    if (fp == NULL) {
        printf("Failed to open the file for writing.\n");
        return;
    }
    while (!feof(fp))
        fgets(row, sizeof(row), fp);
    token = strtok(row, ",");
    strcpy(t, token);
    while (token)
        token = strtok(NULL, ",");
    for (i = 0; t[i] != '\0'; i++)
        ;
    if ((int)(t[i - 1]) == 57)
        t[i - 1] = 48;
    else
        t[i - 1]++;
    strcpy(idt.id, t);
    printf("\t\tCreate your password: ");
    fgets(idt.pass, sizeof(idt.pass), stdin);
    strtok(idt.pass, "\n");  // Remove newline character
    fprintf(fp, "%s,%s\n", idt.id, idt.pass);
    fclose(fp);
    strcpy(dt.regid, idt.id);
}
void getdetails(char* id) {
    char row[100], *token;
    FILE *fp;
    fp = fopen("MYFILE.csv", "r");
    while (!feof(fp)) {
        fgets(row, 100, fp);
        token = strtok(row, ",");
        if (strcmp(token, id) == 0) {
            // Found the matching ID, now process the rest of the data
            strcpy(dt.regid, token);

            // Reset other fields to avoid garbage values
            strcpy(dt.name, "");
            strcpy(dt.g, "");
            strcpy(dt.dob, "");
            strcpy(dt.age, "");
            strcpy(dt.aid, "");
            strcpy(dt.mob, "");
            strcpy(dt.eid, "");
            strcpy(dt.dose, "");

            // Continue tokenizing and copying data
            while (token) {
                token = strtok(NULL, ",");
                if (token) {
                    // Depending on the position of the data in the row, copy it to the appropriate field
                    strcpy(dt.name, token);
                    token = strtok(NULL, ",");
                    strcpy(dt.g, token);
                    token = strtok(NULL, ",");
                    strcpy(dt.dob, token);
                    token = strtok(NULL, ",");
                    strcpy(dt.age, token);
                    token = strtok(NULL, ",");
                    strcpy(dt.aid, token);
                    token = strtok(NULL, ",");
                    strcpy(dt.mob, token);
                    token = strtok(NULL, ",");
                    strcpy(dt.eid, token);
                    token = strtok(NULL, ",");
                    strcpy(dt.dose, token);
                }
            }
            break;  // Found the data, exit the loop
        }
    }
    fclose(fp);
}


void addata() {
    FILE *fpt;
    fpt = fopen("MYFILE.csv", "a");
    if (fpt == NULL) {
        printf("Failed to open the file for writing.\n");
        return;
    }
    dt.name[strcspn(dt.name, "\n")] = '\0';
    dt.g[strcspn(dt.g, "\n")] = '\0';
    dt.dob[strcspn(dt.dob, "\n")] = '\0';
    dt.age[strcspn(dt.age, "\n")] = '\0';
    dt.aid[strcspn(dt.aid, "\n")] = '\0';
    dt.mob[strcspn(dt.mob, "\n")] = '\0';
    dt.eid[strcspn(dt.eid, "\n")] = '\0';
    dt.dose[strcspn(dt.dose, "\n")] = '\0';
    fprintf(fpt, "%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s\n", dt.regid, dt.name, dt.g, dt.dob, dt.age, dt.aid, dt.mob, dt.eid, dt.dose, hos, date, hour);
    fclose(fpt);
}

void getUserdetails() {
    printf("\t\tEnter The Candidate Name: ");
    clearBuffer();
    fgets(dt.name, 20, stdin);
    printf("\t\tEnter The Candidate Gender: ");
    fgets(dt.g, 10, stdin);
    printf("\t\tEnter the Candidate date of birth: ");
    fgets(dt.dob, 20, stdin);
    printf("\t\tEnter the Candidate Age: ");
    fgets(dt.age, 10, stdin);
    printf("\t\tEnter The Candidate Aadhaar Number: ");
    fgets(dt.aid, 20, stdin);
    printf("\t\tEnter The Candidate Email Id: ");
    fgets(dt.eid, 20, stdin);
    printf("\t\tEnter The Candidate Mobile Number: ");
    fgets(dt.mob, 100, stdin);
    printf("\t\tEnter the number of doses already taken: ");
    fgets(dt.dose, 2, stdin);
    generateid();
    venue();
}

void details(){
      addata();
      printdetails();
}


void venue() {
    int i;
    // For Clear Screen
    system("cls");
    printf("Please select Your Venue:\n");
    printf("\n\nChoose one of the following Hospitals for Vaccination:\n");
    // List Of Hospitals Available
    printf("\t\t1. Rio Hospital\n");
    printf("\t\t2. Apollo Hospital\n");
    printf("\t\t3. Lakeshore Hospital\n");
    // Taking Hospital Choice
    printf("\t\tEnter Choice: ");
    scanf("%d", &i);
    if (i == 1)
        strcpy(hos, "Rio Hospital");
    else if (i == 2)
        strcpy(hos, "Apollo Hospital");
    else if (i == 3)
        strcpy(hos, "Lakeshore Hospital");
    else
        printf("No such Choice exists...");
    clearBuffer();
    printf("\t\tEnter Date(DD-MM-YY):");
    fgets(date, sizeof(date), stdin);
    date[strcspn(date, "\n")] = '\0';
    printf("\t\tEnter Time(24 Hours):");
    fgets(hour, sizeof(hour), stdin);
    hour[strcspn(hour, "\n")] = '\0';
    printdetails();
}

void printdetails() {
    system("cls");
    printf("Your Details:\n");
    printf("Register No. : %s\n", dt.regid);
    printf("Name : %s\n", dt.name);
    printf("Gender : %s\n", dt.g);
    printf("Date of Birth : %s\n", dt.dob);
    printf("Aadhaar Id : %s\n", dt.aid);
    printf("Mobile No. : %s\n", dt.mob);
    printf("Email Id : %s\n", dt.eid);
    printf("Dose : %s\n", dt.dose);
    printf("Hospital : %s\n", hos);
    printf("Date: %s \t Time:%s", date, hour);
}

