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
    
}


int main(){
    Account *head=NULL;
    
}

