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

Account *new_account(Account *traverse_pointer, char *name , int number , double balance){
    Account *ptr=(Account *)(malloc(sizeof(Account)));
    if(ptr==NULL){
        printf("Memory Allocation failed! Try again.");
    }
    strcpy(ptr->holder_name, name);
    ptr->account_number=number;
    ptr->balance=balance;
    ptr->status=ACCOUNT_ACTIVE;
    ptr->next=NULL;
    traverse_pointer->next=ptr;
    traverse_pointer=traverse_pointer->next;
    printf("I am function 1 \n");
    printf("My assigned value to pointer is %p\n",ptr);
    return ptr;
}
Account *make_account(Account *head , char *name , int number , double balance){
    Account *next_account = NULL;
    Account *ptr=(Account *)(malloc(sizeof(Account)));
    if(ptr==NULL){
        printf("Memory Allocation failed! Try again.");
    }
    if(head==NULL){
        head=ptr;
        strcpy(ptr->holder_name, name);
         ptr->account_number=number;
         ptr->balance=balance;
         ptr->status=ACCOUNT_ACTIVE;
         ptr->next=NULL;
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

void printf_information( Account *head){
    Account *head_copy=head;
    while(head_copy!=NULL){
        printf("%s\n",head->holder_name);
        printf("%d\n",head->account_number);
        printf("%d\n",head->balance);
        printf("%d\n",head->status);
        head_copy=head_copy->next;

    }
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
    char consent4[100]="No";
    char user_consent[100];
    int count=0;

    do{
    
        printf("Do you want to create an account? \n");
        printf("If yes then type Yes or else type NO: ");
        scanf("%s", user_consent);

        if(strcmp(consent3,user_consent)==0||strcmp(consent4,user_consent)==0){
        break;
       }

        if(strcmp(consent,user_consent)==0||strcmp(consent2,user_consent)==0)

        if(count==0){
        printf("Since you want to create account please enter the following details : - \n");
        take_input(name , &acc_num , &acc_balance );
        head=make_account(head , name , acc_num , acc_balance);
        traverse_pointer=head;
        printf("The memory allocated for head is %p",head);
        printf("The memory allocated for head is %p\n",traverse_pointer);
        printf("%s\n",traverse_pointer->holder_name);
        printf("%d\n",traverse_pointer->account_number);
        printf("%d\n",traverse_pointer->balance);
        printf("%d\n",traverse_pointer->status);
       }
        else{
        printf("The traverse_pointer got is %p\n",traverse_pointer);
        printf("Since you want to create account please enter the following details : - \n");
        take_input(name , &acc_num , &acc_balance );
        traverse_pointer=make_account(traverse_pointer , name , acc_num , acc_balance);
        printf("The traverse_pointer returning  is %p\n",traverse_pointer);
        printf("%s\n",traverse_pointer->holder_name);
        printf("%d\n",traverse_pointer->account_number);
        printf("%d\n",traverse_pointer->balance);
        printf("%d\n",traverse_pointer->status);
        }
        
       printf("The traverse_pointer returning  is %p\n",traverse_pointer);
       count++;

       printf("Memory allocated to head is %p\n ",head);
       printf("The memory allocated for traverse_pointer is %p\n",traverse_pointer);
       printf("%s\n", user_consent);

    }while(1);
    traverse_pointer=head;
    printf("The final memory allocated to head is %p\n ",head);
    printf("The final memory allocated for traverse_pointer is %p\n",traverse_pointer);
    printf_information(head);

}

