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



Account *make_account(Account *head , char *name , int number , double balance){
    Account *traverse_pointer=head;
    Account *ptr=(Account *)(malloc(sizeof(Account)));
    if(ptr==NULL){
        printf("Memory Allocation failed! Try again.");
    }
    else if(name==NULL){
        printf("The entered name is not correct! \n");
        printf("Please try again ! \n");
        free(ptr);
    }
    else if( number <0 ){
        printf("The entered account number  i.e %d is not correct! \n",number);
        printf("Please try again ! \n");
        free(ptr);
    }
    else if( balance <0 ){
        printf("The entered balance cannot  i.e %lf be saved in account! \n",balance);
        printf("Please try again ! \n");
        free(ptr);
    }
    else if(head==NULL){
        head=ptr;
        strcpy(ptr->holder_name, name);
         ptr->account_number=number;
         ptr->balance=balance;
         ptr->status=ACCOUNT_ACTIVE;
         ptr->next=NULL;
         return ptr;
    }
    else{
        strcpy(ptr->holder_name, name);
        ptr->account_number=number;
        ptr->balance=balance;
        ptr->status=ACCOUNT_ACTIVE;
        ptr->next=NULL;
        while( traverse_pointer!=NULL){
        if(traverse_pointer->next==NULL){
            traverse_pointer->next=ptr;
            break;
        }
        traverse_pointer=traverse_pointer->next;
    }
        
    }
    return ptr;
}

void free_memory( Account *head){
    while(head!=NULL){
        free(head);
        head=head->next;
    }
    printf("Deleted all accounts details !");
}

int main(){
    Account *head= NULL ;
    
    
}