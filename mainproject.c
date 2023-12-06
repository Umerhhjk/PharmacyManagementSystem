//Project Members
//Member 1: Syed Umer Taiyab (23K-2016)
//Member 2: Muhammad Owais Muhammad Rafiq (23K-2042)
//Member 3: Abubakr Bin Hassan (23K-2025)
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

#define FILENAME_SIZE 1024
#define MAX_LINE 2048

//it is the structure of storing day,month,year seperately used in mfg and expiry date of medicines
struct date{
	int day;
	int month;
	int year;
};

struct user{
	char mobile[9];
	char password[10];
};

//it is the structure for storing the new medicines into the stock
struct drug{
		int id;
		char name[30];
		struct date mfg[10];
		struct date expiry[10];
		int price;
		int stock;
		int row;
};

void passwordchange(){
    FILE *admin, *pharmacist;
    int choice;
    char data[20];
    printf("Whose Password is to be changed\n");
    printf("1)Admin\n");
    printf("2)Pharmacist\n");
    scanf("%d", &choice);
    if(choice == 1){
        admin= fopen("adminpassword.txt", "w");
        printf("Enter New Password:");
        scanf("%s", data);
        fprintf(admin, "%s", data);
    }
    else if(choice == 2){
        pharmacist= fopen("pharmacistpassword.txt", "w");
        printf("Enter New Password:");
        scanf("%s", data);
        fprintf(pharmacist, "%s", data);
    }
    else{
        printf("Invalid choice");
    }
}

int loginadmin(char username[], char password[]){
    char validUsername[] = "umer";
    FILE *filepassword;
    filepassword = fopen("adminpassword.txt", "r");
    char validPassword[50];
    fgets(validPassword, sizeof(validPassword), filepassword);
    if(strcmp(username, validUsername) == 0 && strcmp(password, validPassword) == 0){
        return 1; 
    } 
	else{
        return 0; 
    }
}

int loginpharmacist(char username[], char password[]){
    char validUsername[] = "owais";
    FILE *filepassword;
    filepassword = fopen("pharmacistpassword.txt", "r");
    char validPassword[50];
    fgets(validPassword, sizeof(validPassword), filepassword);
    if(strcmp(username, validUsername) == 0 && strcmp(password, validPassword) == 0){
        return 1; 
    } 
	else{
        return 0; 
    }
}

void readpharmacistorder(const char *filename){
    FILE *file = fopen(filename, "r+");
    if(file == NULL){
        printf("Error opening the file.\n");
        return;
    }
    char ch;
    int isEmpty = 1;
    printf("File contents:\n");
    while((ch = fgetc(file)) != EOF){
        putchar(ch);
        isEmpty = 0;
    }
    if(isEmpty){
        printf("No recent purchases.\n");
    } 
    else{
        freopen(filename, "w", file);
    }
    fclose(file);
}

void readbug(const char *filename){
    FILE *file = fopen(filename, "r+");
    if(file == NULL){
        printf("Error opening the file.\n");
        return;
    }
    char ch;
    int isEmpty = 1;
    printf("File contents:\n");
    while((ch = fgetc(file)) != EOF){
        putchar(ch);
        isEmpty = 0;
    }
    if(isEmpty){
        printf("No bugs reported.\n");
    } 
    else{
        freopen(filename, "w", file);
    }
    fclose(file);
}
int readfile(const char *filename){
	char data[1000];
	FILE *file = fopen(filename, "r");
	if(file == NULL){
        printf("Could not open the file.\n");
        return 1;
    }
    // Read and print the file content line by line
    while(fgets(data, sizeof(data), file) != NULL){
        printf("%s", data);
    }
    // Close the file
    fclose(file);
}

//it is the function to print/display all the stock present in our pharmacy
void print_stock(){
	FILE *fp;
	char ch;
	fp = fopen("drug.txt", "r");
	struct drug new_drug;
	 if (fp == NULL) {
        perror("Error opening file");
    }
    // Read and display the contents of the file character by character
    printf("\n");
      while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);
}

//Function to print reciept
void reciept(int medicine[20], char name[50]){
    int sum=0;
    printf("\n\n\n\n\t\t\tP H A R M A C Y\n");
    printf("Name:- %s\n", name);
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    char timeString[80];
    strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", timeinfo);
    printf("Invoice Date:- %s\n", timeString);
    printf("\n-------------------------------------------------------------------\n");
    printf("MEDICINE\t\tQTY\t\tPRICE\n\n");
    for(int i=1; i<20; i++){
        if(medicine[i] != 0){
            switch (medicine[i-1]){
                case 0:
                    printf("Panadol    \t\t%d\t\t%d\n", medicine[i],medicine[i]*50);
                    sum = sum + (medicine[i]*50);
                    break;
                case 1:
                    printf("Augmentin  \t\t%d\t\t%d\n", medicine[i], medicine[i]*120);
                    sum = sum + (medicine[i]*120);
                    break;
                case 2:
                    printf("Disprin    \t\t%d\t\t%d\n", medicine[i], medicine[i]*30);
                    sum = sum + (medicine[i]*30);
                    break;
                case 3:
                    printf("Ativan     \t\t%d\t\t%d\n", medicine[i], medicine[i]*80);
                    sum = sum + (medicine[i]*80);
                    break;
                case 4:
                    printf("Amoxicillin\t\t%d\t\t%d\n", medicine[i], medicine[i]*60);
                    sum = sum + (medicine[i]*60);
                    break;
                case 5:
                    printf("Zyrtec     \t\t%d\t\t%d\n", medicine[i], medicine[i]*40);
                    sum = sum + (medicine[i]*40);
                    break;
                case 6:
                    printf("Brufen     \t\t%d\t\t%d\n", medicine[i], medicine[i]*45);
                    sum = sum + (medicine[i]*45);
                    break;
                case 7:
                    printf("Metformin  \t\t%d\t\t%d\n", medicine[i], medicine[i]*35);
                    sum = sum + (medicine[i]*35);
                    break;
                case 8:
                    printf("Insulin    \t\t%d\t\t%d\n", medicine[i], medicine[i]*150);
                    sum = sum + (medicine[i]*150);
                    break;
                case 9:
                    printf("Omeprazole \t\t%d\t\t%d\n", medicine[i], medicine[i]*55);
                    sum = sum + (medicine[i]*55);
                    break;
            }
        }
        i++;
    }
    printf("\n-------------------------------------------------------------------\n");
    printf("Total Price:\t\t%d", sum);
    printf("\n-------------------------------------------------------------------\n");
    printf("\n-------------------------------------------------------------------\n");
    printf("\n\t\t\tThank you for Shopping\n");
    printf("\n-------------------------------------------------------------------\n");
}

void customer_order(){
    char name[50];
    printf("Enter Name: ");
    scanf("%s", name);
	int unique_medicines, id, medicine[20]={0, 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 7, 0, 8, 0, 9, 0};
	FILE *filepointer, *fp, *filepointer2;
	char ch;
    filepointer = fopen("current_order.txt", "w+");
    fp = fopen("order_history.txt", "a");
    filepointer2 = fopen("pharmacist_orderhistory.txt", "a");
    if (filepointer == NULL) {
        printf("Error opening file.\n");
    }
    if (fp == NULL){
    	printf("Error opening file.\n");
	}
	print_stock();
	//Take number of unique medicines to order and then use array with the I.D in 0,2 and so on.
	//The amount is taken as input and then stored in the array right besides the I.D.
	printf("Enter the number of different medicine you want to order:");
	scanf("%d", &unique_medicines);
	for(int i=1; i <= unique_medicines; i++){
		printf("Enter the I.D of medicine %d:", i);
		scanf("%d", &id);
        for(int j=0; j<20; j++){
            if(id == medicine[j]){
                printf("Enter Amount:");
                scanf("%d", &medicine[j+1]);
            }
            j++;
        }
	}
    for(int j=1; j<20; j++){
        if(medicine[j] != 0){
            switch(medicine[j-1]){
                case 0:
                	fprintf(filepointer, "I.D: %d\t\tPanadol:%d\n", medicine[j-1], medicine[j]);
                	break;
                case 1:
                	fprintf(filepointer, "I.D: %d\t\tAugmentin:%d\n", medicine[j-1], medicine[j]);
                	break;
               	case 2:
                	fprintf(filepointer, "I.D: %d\t\tDisprin:%d\n", medicine[j-1], medicine[j]);
                	break;
                case 3:
                	fprintf(filepointer, "I.D: %d\t\tAtivan:%d\n", medicine[j-1], medicine[j]);
                	break;
               	case 4:
                	fprintf(filepointer, "I.D: %d\t\tAmoxicillin:%d\n", medicine[j-1], medicine[j]);
               		break;
                case 5:
              		fprintf(filepointer, "I.D: %d\t\tZyrtec:%d\n", medicine[j-1], medicine[j]);
               		break;
                case 6:
                	fprintf(filepointer, "I.D: %d\t\tBrufen:%d\n", medicine[j-1], medicine[j]);
                	break;
                case 7:
                	fprintf(filepointer, "I.D: %d\t\tMetformin:%d\n", medicine[j-1], medicine[j]);
                	break;
                case 8:
                	fprintf(filepointer, "I.D: %d\t\tInsulin:%d\n", medicine[j-1], medicine[j]);
                	break;
                case 9:
					fprintf(filepointer, "I.D: %d\t\tOmeprazole:%d\n", medicine[j-1], medicine[j]);
                	break;
			}
		}
		j++;
    }
    //append the current order to order history and pharmacist order history.
    fseek(fp, 0, SEEK_END);
    fseek(filepointer, 0, SEEK_SET);
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    char timeString[80];
    strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", timeinfo);
    fprintf(fp, "\n[%s]\n", timeString);
    fprintf(filepointer2, "\n[%s]\n", timeString);
	while ((ch = fgetc(filepointer)) != EOF) {
        fputc(ch, fp);
        fputc(ch, filepointer2);
    }
    reciept(medicine, name);
} 

//it is the function to input the new medicines into the stock (All the stock is mantained in drug.txt)
void order(int choice){
	int i=0,n=0;
	FILE *fptr;
	printf("Enter the No of medicine you want to input: ");
	scanf("%d",&n);
	struct drug new_drug[n];
	fptr = fopen("drug.txt", "a");
	for(i=0;i<n;i++){
		new_drug[i].id = i+10;
		printf("\nDrug no %d: ",i+1);
	 	scanf("%s", new_drug[i].name);
	 	printf("\nManufacturing date(DD MM YY): ");
	 	scanf("%d %d %d", & new_drug[i].mfg[i].day, & new_drug[i].mfg[i].month, & new_drug[i].mfg[i].year);
		printf("\nExpiry date(DD MM YY): ");
		scanf("%d %d %d", & new_drug[i].expiry[i].day, & new_drug[i].expiry[i].month, & new_drug[i].expiry[i].year);
		printf("\nPrice: ");
		scanf("%d", & new_drug[i].price);
		getchar();
		printf("\nNumber of units to be added to inventory: ");
		scanf("%d", & new_drug[i].stock);
		printf("\nEnter the no of row at you placed your medicine no %d: ",i+1);
		scanf("%d", & new_drug[i].row);
		printf("\nMedicine Information have been added successfully");
		fprintf(fptr, "Id: %d \nName: %s \nMFG Date: %d %d %d \nExpiry Date: %d %d %d \nPrice: $%d \nAmount: %d Units\nLocation: Shelf No. %d \n \n", new_drug[i].id, new_drug[i].name,new_drug[i].mfg[i].day, new_drug[i].mfg[i].month, new_drug[i].mfg[i].year, new_drug[i].expiry[i].day,new_drug[i].expiry[i].month, new_drug[i].expiry[i].year, new_drug[i].price, new_drug[i].stock, new_drug[i].row);
		fprintf(fptr,"-----------------------------------------\n\n");	
	}
	fclose(fptr);
}

//it is the bug reporting function which allow pharmacist to send bug report to admin 
//the bug report will be in bug.txt and the bug report will print along with the time on which pharmacist report a bug
void bug(const char *report) {
    FILE *file = fopen("bug.txt", "a");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    char timeString[80];
    strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", timeinfo);
    fprintf(file, "[%s] %s\n", timeString, report);
    fclose(file);
    printf("Your report have been send to the Admin. Thank you.\n");
}

//it is the function that is use to update the stock/amount of the specific medicine just by calling id of the medicine
void update(int choice) {
    FILE *file, *temp;
    char filename[FILENAME_SIZE] = "drug.txt";
    char temp_filename[FILENAME_SIZE];
    char buffer[MAX_LINE];
    char replace[MAX_LINE];
    int replace_line = 0;
	printf("\n");
    printf("Enter the ID of the medicine: ");
    scanf("%d", &choice);
    if (choice < 0 || choice > 9) {
        printf("Invalid ID. Exiting...\n");
        return;
    }

    replace_line = 6 + choice * 10;
	printf("Write the stock update in the form of (Amount : -- units) as it is type it but instead of -- write the no of current stock available\n");
    printf("New Stock Update: ");
    fflush(stdin);
    fgets(replace, MAX_LINE, stdin);

    strcpy(temp_filename, "temp____");
    strcat(temp_filename, filename);

    file = fopen(filename, "r");
    temp = fopen(temp_filename, "w");

    if (file == NULL || temp == NULL) {
        printf("Error opening files(s).\n");
        return;
    }

    bool keep_reading = true;
    int current_line = 1;

    do {
        fgets(buffer, MAX_LINE, file);

        if (feof(file)) keep_reading = false;
        else if (current_line == replace_line) {
            fputs(replace, temp);
        } else {
            fputs(buffer, temp);
        }

        current_line++;

    } while (keep_reading);

    fclose(file);
    fclose(temp);
	printf("Stock has been sucessfully updated\n");
    remove(filename);
    rename(temp_filename, filename);
}

//it is the function that is used to display all the location of medicine in the store along with the name of medicine
void location(int choice) {
    FILE *file;
    char filename[FILENAME_SIZE] = "drug.txt";
    char buffer[MAX_LINE];
    int read_line = 2;
    int count = 0;
    printf("\nHere are all the location of the medicines that are currently present in the stock\n");
    printf("You can find your desired medicine location from the below list\n");
    printf("\n");
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    int current_line = 1;
    while (fgets(buffer, MAX_LINE, file) != NULL) {
        if (current_line == read_line) {
            printf("%s", buffer);
            count++;
            read_line += 5; // Increment by 5
        }
        current_line++;
        if(count == 2){
        	printf("\n");
        	count=0;
		}
    }

    fclose(file);
}

int pharmacist(){
	char user[50];
    char pass[50];
    const char *filename = "pharmacist_orderhistory.txt";
    int i = 0;
    printf("Enter username: ");
    scanf("%s", user);
    printf("Enter password: ");
    while(i<50){
        pass[i] = getch();
        if(pass[i] == '\r'){ 
            pass[i] = '\0'; 
            break;
        } 
		else{
            printf("*");
        }
        i++;
    }
    printf("\n");
	if(loginpharmacist(user, pass)){
		//after logging in user will be redirect to the pharmacist portal
		int choice;
		printf("\n\n \t \t \t Welcome to the Phamacist Portal\n");
		while(choice != 7){
		printf("\n1)For Ordering Purpose press 1\n");
		printf("2)For Bug Reporting press 2\n");
		printf("3)For Checking Availability of Medicines/Stock press 3\n");
		printf("4)For knowing the location of the Medicine in store press 4\n");
		printf("5)For Updating the Amount of the Stock of the Medicine press 5\n");
        printf("6)For seeing recent orders by customer\n");
		printf("7)Exit");
		printf("\nEnter your Choice = ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				//case 1 will be giving option to the pharmacist to add new odering medicines into the stock
				order(choice);
				break;
			case 2:
				// Buffer to store user input
			    // Get bug report from the user
			    printf("Enter the bug report: ");
			    char bugReportBuffer[1000];
			    fgets(bugReportBuffer, sizeof(bugReportBuffer), stdin);
			    if (fgets(bugReportBuffer, sizeof(bugReportBuffer), stdin) == NULL) {
		        printf("Error reading bug report.\n");
		        return 1;
			    }
			    // Call the bug function with the bug report
			    bug(bugReportBuffer);
				break;
			case 3:
				//call the stock printing function to print the stock
				print_stock();
				break;	
			case 4:
				//call the location function to know the location of the specific medicine
				location(choice);
    			break;
			case 5:
				//call the update function in order to update/maintain the stock of the medicine
				update(choice);
				break;
            case 6:
                readpharmacistorder(filename);
                break;		
		}
		}
		
	}
	else{
		//if the input username or password is incorrect it will show Incorrect Username or password and make a sound of beep
		printf("\nIncorrect Username or password");
		Beep(800,700);
	}
	return 0;
}

int admin(){
	char username[50];
    char password[50];
    const char *filename1 = "bug.txt";
    const char *filename2= "order_history.txt";
    int i = 0, choice;
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    while(i<50){
        password[i] = getch();
        if(password[i] == '\r'){ 
            password[i] = '\0'; 
            break;
        	} 
		else{
            printf("*");
        }
        	i++;
    }
    printf("\n");
    if(loginadmin(username, password)){
        printf("Login successful!\n");
		printf("\n\n\n\t\tWelcome Admin\n");
		while(choice!=4){
			printf("\n1 bug report");
			printf("\n2 order history");
            printf("\n3 Change Password");
			printf("\n4 Exit");
			printf("\nEnter your choice:");
			scanf("%d", &choice);
			switch(choice){
				case 1:
    				readbug(filename1);
    				break;
    			case 2:
    				readfile(filename2);
					break;
                case 3:
                    passwordchange();
                    break;
			}
    	}
	}
	else{
       	printf("Login failed. Invalid username or password.\n");
   	}
    	return 0;
}

void customer(){
	int choice, remarks;
	FILE *filePointer1;
    filePointer1 = fopen("current_order.txt", "w+");
    if (filePointer1 == NULL) {
        printf("Error opening file.\n");
    }

	printf("\n\n \t \t \t Welcome to the Customer Portal\n");
	while(choice != 2){
	printf("\n1)For Ordering Purpose\n");
	printf("2)Exit");
	printf("\nEnter your Choice = ");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			customer_order();
			break;
		case 2:
            //remarks of the customer!!!
            printf("\nENTER:\n1)EXCELLENT\n2)GOOD\n3)SATISFACTORY");
            printf("\nHOW WAS OUR SERVICE: ");
            scanf("%d",&remarks);
            printf("EXITING PROGRAM. GOODBYE!\n");
            break;
        default:
            printf("INVALID CHOICE. PLEASE ENTER THE VALID OPTION.\n");
	}
    fclose(filePointer1);
	}
}

int main(){
	int choice;
	while(choice != 4){
		printf("\n\n");
		printf("\t\t\tPharmacy Management System");
		printf("\n\n\n\t\t\t\tWho are you");
		printf("\n1 Admin\n2 Pharmacist\n3 Customer\n4 Exit");
		printf("\nYour Choice:");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				admin();
				break;
			case 2:
				pharmacist();
				break;
			case 3:
				customer();
				break;
		}
	}
}
