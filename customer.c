#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayMedicines(char medicine[][100], float price[], int quantity[]);
void purchaseMedicine(char medicine[][100], float price[], int quantity[]);

int main() {
    char medicine[2][100];
    float price[2];
    int quantity[2];
    int i, numb = 0;
    char name[10];
    int choice;
    int remarks=0;

    FILE *file = fopen("medicines.txt", "w");

    if (file == NULL) {
        printf("ERROR OPENING FILE!\n");
        exit(1);
    }

    for (i = 0; i < 2; i++) {
        printf("ENTER THE NAME OF THE MEDICINE %d: ", i + 1);
        scanf("%s", medicine[i]);

        printf("ENTER THE PRICE OF THE MEDICINE %d: ", i + 1);
        scanf("%f", &price[i]);

        printf("ENTER THE QUANTITY OF THE MEDICINE %d: ", i + 1);
        scanf("%d", &quantity[i]);

        fprintf(file, "%s,%f,%d\n", medicine[i], price[i], quantity[i]);
    }

    fclose(file);
      
    printf("\n\t\t!!!WELCOME TO THE PHARMACEUTICAL MANAGEMENT SYSTEM!!!\n");

    do {
    	printf("\n");
        printf("1.DISPLAY MEDICINES\n");
        printf("2.PURCHASE MEDICINES\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayMedicines(medicine, price, quantity);
                break;

            case 2:
                purchaseMedicine(medicine, price, quantity);
                break;

            case 3:
            	//remarks of the customer!!!
                printf("\nENTER:\n1)EXCELLENT\n2)GOOD\n3)SATISFACTORY");
                printf("\nHOW WAS OUR SERVICE: ");
                scanf("%d",&remarks);
                printf("EXITING PROGRAM. GOODBYE!\n");
                break;

            default:
                printf("INVALID CHOICE. PLEASE ENTER THE VALID OPTION.\n");
        }
    } while (choice != 3);

    return 0;
}
//TO DISPLAY WHOLE MENU OF THE MEDICINES
void displayMedicines(char medicine[][100], float price[], int quantity[]) {
    int i;
    printf("MEDICINE   PRICE   QUANTITY\n");
    for (i = 0; i < 2; i++) {
        printf("%s   %.2f     %d\n", medicine[i], price[i], quantity[i]);
        printf("\n");
    }
}
//TO PURCHASE MEDICINES
void purchaseMedicine(char medicine[][100], float price[], int quantity[]) {
    char name[100];
    char a[10][100];
    float b[10];
    int   c[10];
    int i=0;
    int numb=0;
    int found=0;
    int row=0;
    char opt;
    float subtotal=0.0,m=0.0,discount=0.0,total=0.0,GST=0.0; 
   //TAKING INPUT FOR THE NAME OF MEDICINES FROM THE USER
    do {
    	getchar();
        puts("PLEASE ENTER THE NAME OF THE MEDICINE");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    //CHECKING IF ITS AVAILABLE
        for (i = 0; i < 2; i++) {
            if (strcasecmp(medicine[i], name) == 0){
			 strcpy(a[i], medicine[i]);
                b[i] = price[i];

                found = 1;
                row = i;

                break;
            }
            
        }

        if (found) {
            printf("THE MEDICINE IS AVAILABLE.\n");
            printf("PLEASE ENTER THE CORRECT QUANTITY: ");
            scanf("%d", &numb);

            // Check if the requested quantity is available
            while (numb > quantity[row]) {
                printf("\nPLEASE ENTER THE CORRECT QUANTITY: ");
                scanf("%d", &numb);
            }
            quantity[row] -= numb;
            c[row]=numb;
            
        }
		     else {
            printf("SORRY, THE MEDICINE IS NOT AVAILABLE. PLEASE TRY AGAIN.\n");
        }
        //ASKING FOR ANOTHER INPUT
        
        printf("\nDO YOU WANT TO PURCHASE ANOTHER MEDICINE? (y/n): ");
       scanf(" %c", &opt);
    } while (opt == 'y');
    //CALCULATING THE DISCOUNT,SUB-TOTAL,GST,DISCOUNT AND TOTAL
    for(i=0;i<row+1;i++){
    		m=b[i]*c[i];
    		subtotal=subtotal+m;
    	}
    		
    //OFFERING DISCOUNT of 15% if the subtotal is greater than RS 3000/-
	//GST OF 5% of the sub-total;
			 GST= 0.05*subtotal;
			if(subtotal>3000.000){
				discount=0.15*subtotal;
				total=subtotal+GST-discount;
			}
			else{
				discount=0.00;
				total=subtotal+GST;
			}
    // printing the receipt of the purchased item
    char receipt;
    printf("\nDO YOU WANT THE RECEIPT OF THE PURCHASED MEDICINES?(y/n) ");
    i=0;
    receipt=getche();
    switch (receipt){
    	case  'y' :
    		printf("\n\t\t\t !!!!!!!!PHARMACUETICAL MANAGEMENT SYSTEM!!!!!!!!!");
    		printf("\n");
    		printf("\n-------------------------------------------------------------------");
    		printf("\n");
    		printf("\nYOU HAVE ORDERED:");
    		printf("\n-------------------------------------------------------------------");
    		printf("\n MEDICINES    QUANTITY     PRICE(RS)");
    		printf("\n-------------------------------------------------------------------");
    		for(i=0;i<row+1;i++){
    			printf("\n%s        %d         %.2f ",a[i],c[i],b[i]*c[i]);
    			printf("\n");
    			m=b[i]*c[i];
    			subtotal=subtotal+m;
			}
			
			
			printf("\n-------------------------------------------------------------------");
			printf("\n-------------------------------------------------------------------");
			printf("\n\t\t\t\t\t\tSUB-TOTAL: %.2f",subtotal);
			printf("\n\t\t\t\t\t\tDISCOUNT: %.2f",discount);
			printf("\n\t\t\t\t\t\tG.S.T: %.2f",GST);
			printf("\n\t\t\t\t\t\tTOTAL: %.2f",total);
			printf("\n-------------------------------------------------------------------");
    		printf("\n\t\t!!!!!!!THANK YOU FOR SHOPPING.HOPE YOU WILL SHOP AGAIN!!!!!!");
    		
    		break;
    		case'n':
    		printf("\nSUB-TOTAL: %.2f",subtotal);
			printf("\nDISCOUNT: %.2f",discount);
			printf("\nG.S.T: %.2f",GST);
			printf("\nTOTAL: %.2f",total);
			break;
			default:
				printf("\nINVALID INPUT");
    			
	}
	printf("\nPRESS 3 TO EXIT ");
}
