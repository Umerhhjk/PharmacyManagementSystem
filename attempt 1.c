#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

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
		struct date mfg;
		struct date expiry;
		int price;
		int stock;
		int row;
};

//it is the function to generate random id to the medicines
int rand_id(void) {
 int num = 0;
 srand(time(0));
 num = (rand() % (2000 - 1000 + 1)) + 1000;
 return num;
}

//it is the function to input the new medicines into the stock (All the stock is mantained in order.txt)
void order(int choice){
	struct drug new_drug;
	FILE *fptr;
	fptr = fopen("order.txt", "a");
 	new_drug.id = rand_id();
	printf("\nDrug: ");
 	scanf("%s", new_drug.name);
 	printf("\nManufacturing date(DD MM YY): ");
 	scanf("%d %d %d", & new_drug.mfg.day, & new_drug.mfg.month, & new_drug.mfg.year);
	printf("\nExpiry date: ");
	scanf("%d %d %d", & new_drug.expiry.day, & new_drug.expiry.month, & new_drug.expiry.year);
	printf("\nPrice: ");
	scanf("%d", & new_drug.price);
	getchar();
	printf("\nNumber of units to be added to inventory: ");
	scanf("%d", & new_drug.stock);
	printf("\nEnter the no of row at you placed your medicine: ");
	scanf("%d", & new_drug.row);
	fprintf(fptr, "%d \n %s \n %d %d %d \n %d %d %d \n %d \n %d \n %d \n \n", new_drug.id, new_drug.name,new_drug.mfg.day, new_drug.mfg.month, new_drug.mfg.year, new_drug.expiry.day,new_drug.expiry.month, new_drug.expiry.year, new_drug.price, new_drug.stock, new_drug.row);
	fclose(fptr);
}

//this is the bug report option in which user can report the bug. all the bug report along with the current time will move to the bug.txt
void bug(const char *report) {
    // Open the file in write mode
    FILE *file = fopen("bug.txt", "a");

    // Check if the file is opened successfully
    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    // Get the current time
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    // Format the time as a string
    char timeString[80];
    strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", timeinfo);

    // Write the bug report and time to the file
    fprintf(file, "[%s] %s\n", timeString, report);

    // Close the file
    fclose(file);

    printf("Your report have been send to the Admin. Thank you.\n");
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
		printf("\n1)For Ordering Purpose press 1\n");
		printf("2)For Bug Reporting press 2\n");
		printf("3)For Checking Availability of Medicines/Stock press 3\n");
		printf("4)For knowing the location of the Medicine in store press 4\n");
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
			
					
		}
	}
	else{
		//if the input username or password is incorrect it will show Incorrect Username or password and make a sound of beep
		printf("\nIncorrect Username or password");
		Beep(800,700);
	}
	return 0;
}

