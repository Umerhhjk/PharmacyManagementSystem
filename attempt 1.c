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

struct user{
	char mobile[9];
	char password[10];
};

//it is the function to input the new medicines into the stock (All the stock is mantained in order.txt)
void order(int choice){
	int i=0,n=0;
	FILE *fptr;
	printf("Enter the No of medicine you want to input: ");
	scanf("%d",&n);
	struct drug new_drug[n];
	fptr = fopen("order.txt", "a");
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

//it is the function to print/display all the stock present in our pharmacy
void print_stock(int choice){
	FILE *fp;
	char ch;
	fp = fopen("order.txt", "r");
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

//it is the function that is used to display all the location of medicine in the store along with the name of medicine
void location(int choice) {
    FILE *file;
    char filename[FILENAME_SIZE] = "order.txt";
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


//it is the function that is use to update the stock/amount of the specific medicine just by calling id of the medicine
void update(int choice) {
    FILE *file, *temp;
    char filename[FILENAME_SIZE] = "order.txt";
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


//this is the main file
int main(){
	//username is pharmacist
	//password is owais
	//the above code is about making login form
	char ch,password[5] = "owais",username[10] = "pharmacist",user[20],pass[20];
	printf("Enter Username = ");
	gets(user);
	printf("Enter Password = ");
	int i;
		while((ch = _getch()) != 20){
			if(ch == '\r'){
				break;
			}
			else{
				pass[i] = ch;
				i++;
				printf("*");
				
			} 
		}	
	pass[i] = '\0';
	if(strcmp(username,user) == 0 && strcmp(password,pass) == 0){
		//after logging in user will be redirect to the pharmacist portal
		int choice;
		printf("\n\n \t \t \t Welcome to the Phamacist Portal\n");
		while(choice != 6){
		printf("\n1)For Ordering Purpose press 1\n");
		printf("2)For Bug Reporting press 2\n");
		printf("3)For Checking Availability of Medicines/Stock press 3\n");
		printf("4)For knowing the location of the Medicine in store press 4\n");
		printf("5)For Updating the Amount of the Stock of the Medicine press 5\n");
		printf("6)Exit");
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
				print_stock(choice);
				break;	
			case 4:
				//call the location function to know the location of the specific medicine
				location(choice);
    			break;
			case 5:
				//call the update function in order to update/maintain the stock of the medicine
				update(choice);
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
