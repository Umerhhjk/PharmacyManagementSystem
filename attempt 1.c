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
		struct date *mfg[10];
		struct date *expiry[10];
		int price;
		int stock;
		int row;
};

struct user{
	char mobile[9];
	char password[10];
};

//it is the function to generate random id to the medicines
//int rand_id(void) {
// int num = 0;
// srand(time(0));
// num = (rand() % (2000 - 1000 + 1)) + 1000;
// return num;
//}

//it is the function to input the new medicines into the stock (All the stock is mantained in order.txt)
void order(struct drug *new_drug[]){
	int i=0;
	FILE *fptr;
	fptr = fopen("order.txt", "a");
	for(i=0;i<10;i++){
		new_drug[i]->id = i+1;
		printf("\nDrug no %d: ",i+1);
	 	scanf("%s", new_drug[i]->name);
	 	printf("\nManufacturing date(DD MM YY): ");
	 	scanf("%d %d %d", & new_drug[i]->mfg[i]->day, & new_drug[i]->mfg[i]->month, & new_drug[i]->mfg[i]->year);
		printf("\nExpiry date(DD MM YY): ");
		scanf("%d %d %d", & new_drug[i]->expiry[i]->day, & new_drug[i]->expiry[i]->month, & new_drug[i]->expiry[i]->year);
		printf("\nPrice: ");
		scanf("%d", & new_drug[i]->price);
		getchar();
		printf("\nNumber of units to be added to inventory: ");
		scanf("%d", & new_drug[i]->stock);
		printf("\nEnter the no of row at you placed your medicine no %d: ",i+1);
		scanf("%d", & new_drug[i]->row);
		fprintf(fptr, "Id: %d \nName: %s \nMFG Date: %d %d %d \nExpiry Date: %d %d %d \nPrice: $%d \nAmount: %d Units\nLocation: Shelf No. %d \n \n", new_drug[i]->id, new_drug[i]->name,new_drug[i]->mfg[i]->day, new_drug[i]->mfg[i]->month, new_drug[i]->mfg[i]->year, new_drug[i]->expiry[i]->day,new_drug[i]->expiry[i]->month, new_drug[i]->expiry[i]->year, new_drug[i]->price, new_drug[i]->stock, new_drug[i]->row);
		fprintf(fptr,"-----------------------------------------\n\n");	
	}
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


void location(struct drug *new_drug[]) {
	int j=0;
	printf("Enter the id no of medicine = ");
	scanf("%d",&j);
	printf("Name of the medicine = %s",new_drug[j]->name);
	printf("Location: Shelf No %d",new_drug[j]->row);
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
		struct drug new_drug[10];
		printf("\n\n \t \t \t Welcome to the Phamacist Portal\n");
		while(choice != 5){
		printf("\n1)For Ordering Purpose press 1\n");
		printf("2)For Bug Reporting press 2\n");
		printf("3)For Checking Availability of Medicines/Stock press 3\n");
		printf("4)For knowing the location of the Medicine in store press 4\n");
		printf("5)Exit");
		printf("\nEnter your Choice = ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				//case 1 will be giving option to the pharmacist to add new odering medicines into the stock
				order(&new_drug[10]);
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
				print_stock(choice);
				break;	
			case 4:
				location(&new_drug[10]);
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
