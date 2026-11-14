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

Account *next_new_account(Account *traverse_pointer, char *name , int number , double balance){
    Account *new_ptr=(Account *)(malloc(sizeof(Account)));
    if(new_ptr==NULL){
        printf("Memory Allocation failed! Try again.");
    }
    else if(name==NULL){
        printf("The entered name is not correct! \n");
        printf("Please try again ! \n");
    }
    else if( number <0 ){
        printf("The entered account number is not correct! \n");
        printf("Please try again ! \n");
    }
    else if( balance <0 ){
        printf("The entered balance connot be saved in account! \n");
        printf("Please try again ! \n");
    }
    else{
    strcpy(new_ptr->holder_name, name);
    new_ptr->account_number=number;
    new_ptr->balance=balance;
    new_ptr->status=ACCOUNT_ACTIVE;
    new_ptr->next=NULL;
    traverse_pointer->next=new_ptr;
    traverse_pointer=traverse_pointer->next;
    }
    
    return new_ptr;
}

Account *delete_at_random_position( Account *head ,int number ){
    Account *traverse_random=head;
    Account *traverse_random_prev;
    if(traverse_random->next==NULL ){
        traverse_random=NULL
        traverse_random_prev=NULL
    }
    else {
        while(traverse_random!=NULL){
        if(traverse_random->account_number==number){
            traverse_random_prev->next=traverse_random->next;
            free(traverse_random);
            return 0;
        }
        traverse_random_prev=traverse_random;
        traverse_random=traverse_random->next;
    }  
    }
    
    return traverse_random_prev;  
}

Account  *search_at_random_position( Account *head ,int number ){
    Account *search_random=head;
    while(search_random!=NULL){
        if(search_random->account_number==number){
            return search_random;
        }
        search_random=search_random->next;
    }  
    return NULL;
}

Account *make_account(Account *head , char *name , int number , double balance){
    Account *return_value;
    Account *ptr=(Account *)(malloc(sizeof(Account)));
    if(ptr==NULL){
        printf("Memory Allocation failed! Try again.");
    }
    else if(name==NULL){
        printf("The entered name is not correct! \n");
        printf("Please try again ! \n");
    }
    else if( number <0 ){
        printf("The entered account number is not correct! \n");
        printf("Please try again ! \n");
    }
    else if( balance <0 ){
        printf("The entered balance connot be saved in account! \n");
        printf("Please try again ! \n");
    }
    else if(head==NULL){
        head=ptr;
        strcpy(ptr->holder_name, name);
         ptr->account_number=number;
         ptr->balance=balance;
         ptr->status=ACCOUNT_ACTIVE;
         ptr->next=NULL;
         return_value=ptr;
    }
    else{
        return_value=next_new_account(head,name ,number ,balance);
    }
    return return_value;
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
    head=make_account(head , NULL, 100 , 1000000.00);
    printf("%s\n",head->holder_name);
        printf("%d\n",head->account_number);
        printf("%lf\n",head->balance);
        printf("%d\n",head->status);
}