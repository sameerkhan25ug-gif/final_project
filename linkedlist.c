#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum {
    ACCOUNT_ACTIVE,
    ACCOUNT_CLOSED
} AccountStatus;

typedef struct Account {
    int account_number;         // Unique identifier (e.g., 1001)
    char holder_name[50];       // Customer name
    double balance;             // Current balance
    AccountStatus status;     // ACTIVE or CLOSED
    struct Account *next;
} Account;

typedef struct {
    Account *head;
    int total_accounts;
} AccountList;

void *new_account(Account *head , char *name , int number , double balance){
    Account *current=head;
    Account *ptr=(Account *)(malloc(sizeof(Account)));
    if(ptr==NULL){
        printf("Memory Allocation failed! Try again.");
    }
    strcpy(ptr->holder_name, name);
    ptr->account_number=number;
    ptr->balance=balance;
    ptr->status=ACCOUNT_ACTIVE;
    current->next=ptr;
    current=current->next;
}
Account *make_account(Account *head , char *name , int number , double balance){
    Account *next_account = NULL;
    Account *ptr=(Account *)(malloc(sizeof(Account)));
    if(ptr==NULL){
        printf("Memory Allocation failed! Try again.");
    }
    strcpy(ptr->holder_name, name);
    ptr->account_number=number;
    ptr->balance=balance;
    ptr->status=ACCOUNT_ACTIVE;
    if(head==NULL){
        head=ptr;
        next_account=ptr;
    }
    return ptr;
}

void take_input( char *name , int *acc_num , double *bal){
    printf("Enter the name of the account holder : ");
    scanf("%s",name);
    printf("Enter the account number of the account holder : ");
    scanf("%d",acc_num);
    printf("Enter the amount that you want to deopsit: ");
    scanf("%d",bal);
}


int main(){
    Account *head=NULL;
    
    char name[100];
    int account_number;
    double acc_balance;
    char consent[100]="Yes";
    char consent2[100]="yes";
    char user_consent[100];

    printf("Do you want to create an account? \n");
    printf("If yes then type Yes: ");
    scanf("%s", user_consent);
    
    if(strcmp(consent,user_consent)==0||strcmp(consent2,user_consent)==0){
        printf("Since you want to create account please enter the following details : - \n");
        take_input(name , &account_number , &acc_balance );
    }
    Account *Person_1= make_account(head , name , account_number , acc_balance);
    printf("The memory that is there in head is %p",head);
    printf("The memory that is there in Account one  is %p",Person_1);

}

