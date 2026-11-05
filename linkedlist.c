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

void take_input( char *name , int *acc_num , double *bal){
    printf("Enter the name of the account holder : ");
    scanf("%s",name);
    printf("Enter the account number of the account holder : ");
    scanf("%d", acc_num);
    printf("Enter the amount that you want to deopsit: ");
    scanf("%d",&bal);
}


int main(){
    Account *head=NULL;
    
    char *name;
    int account_number;
    double acc_balance;
    char consent[100];
    take_input(name , &account_number , &acc_balance );
    printf("Do you want to create an account.\n");
    printf("If you want to create a account they type Yes: ");
    scanf("%s", consent);

    if(consent=="Yes "|| consent=="yes"){
        take_input(name , &account_number , &acc_balance );
    }


}

