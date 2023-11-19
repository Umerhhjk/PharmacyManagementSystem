#include <stdio.h>
#include <conio.h>
#include <string.h>
int login(char username[], char password[]){
    char validUsername[] = "user123";
    char validPassword[] = "password123";
    if(strcmp(username, validUsername) == 0 && strcmp(password, validPassword) == 0){
        return 1; 
    } 
	else{
        return 0; 
    }
}
int main(){
    char username[50];
    char password[50];
    int i = 0;
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
    if(login(username, password)){
        printf("Login successful!\n");
    } 
	else{
        printf("Login failed. Invalid username or password.\n");
    }
    return 0;
}