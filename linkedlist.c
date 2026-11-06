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
    if(head==NULL){
        head=ptr;
        next_account=ptr;
        strcpy(ptr->holder_name, name);
         ptr->account_number=number;
         ptr->balance=balance;
         ptr->status=ACCOUNT_ACTIVE;
    }
    else{
        new_account(head,name ,number ,balance);
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

void free_memory( Account *head){
    Account *to_del_next;
    while(head!=NULL){
        to_del_next=head->next;
        free(head);
        head=to_del_next;

    }
}
int main(){
    Account *head=NULL;
    Account *traverse_pointer=NULL;
    
    char name[100];
    int acc_num;
    double acc_balance;
    char consent[100]="Yes";
    char consent2[100]="yes";
    char consent3[100]="No";
    char user_consent[100];
    int count=0;

    printf("Do you want to create an account? \n");
    printf("If yes then type Yes or else type NO: ");
    scanf("%s", user_consent);
    
    
    while(strcmp(consent3,user_consent)!=0){
        if(strcmp(consent,user_consent)==0||strcmp(consent2,user_consent)==0){
        printf("Since you want to create account please enter the following details : - \n");
        take_input(name , &acc_num , &acc_balance );
       }
       if(count==0){
        head=make_account(head , name , acc_num , acc_balance);
       }
       else{
        traverse_pointer=make_account(head , name , acc_num , acc_balance);
       }
       count++;
    }
    printf("Memory allocated to head is %p ",head);
    
    // Account *Person_1= make_account(head , name , acc_num , acc_balance);
    // head=Person_1;

    // printf("%d\n",Person_1->account_number);
    // printf("%s\n",Person_1->holder_name);
    // printf("%d\n",Person_1->balance);
    // printf("%d\n",Person_1->status);

}

