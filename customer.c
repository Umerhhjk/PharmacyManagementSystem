#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

#define FILENAME_SIZE 1024
#define MAX_LINE 2048

void print_stock(){
	FILE *fp;
	char ch;
	fp = fopen("drug.txt", "r");
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

void customer_order(){
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
                	fprintf(filepointer, "I.D: %d\t\tPanadol:%d\n", medicine[j], medicine[j-1]);
                	break;
                case 1:
                	fprintf(filepointer, "I.D: %d\t\tAugmentin:%d\n", medicine[j], medicine[j-1]);
                	break;
               	case 2:
                	fprintf(filepointer, "I.D: %d\t\tDisprin:%d\n", medicine[j], medicine[j-1]);
                	break;
                case 3:
                	fprintf(filepointer, "I.D: %d\t\tAtivan:%d\n", medicine[j], medicine[j-1]);
                	break;
               	case 4:
                	fprintf(filepointer, "I.D: %d\t\tAmoxicillin:%d\n", medicine[j], medicine[j-1]);
               		break;
                case 5:
              		fprintf(filepointer, "I.D: %d\t\tZyrtec:%d\n", medicine[j], medicine[j-1]);
               		break;
                case 6:
                	fprintf(filepointer, "I.D: %d\t\tBrufen:%d\n", medicine[j], medicine[j-1]);
                	break;
                case 7:
                	fprintf(filepointer, "I.D: %d\t\tMetformin:%d\n", medicine[j], medicine[j-1]);
                	break;
                case 8:
                	fprintf(filepointer, "I.D: %d\t\tInsulin:%d\n", medicine[j], medicine[j-1]);
                	break;
                case 9:
					fprintf(filepointer, "I.D: %d\t\tOmeprazole:%d\n", medicine[j], medicine[j-1]);
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
}