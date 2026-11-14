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
        printf("The entered account number  i.e %d is not correct! \n",number);
        printf("Please try again ! \n");
    }
    else if( balance <0 ){
        printf("The entered balance connot  i.e %lf be saved in account! \n",balance);
        printf("Please try again ! \n");
    }
    else{
    strcpy(new_ptr->holder_name, name);
    new_ptr->account_number=number;
    new_ptr->balance=balance;
    new_ptr->status=ACCOUNT_ACTIVE;
    new_ptr->next=NULL;
    while( traverse_pointer!=NULL){
        if(traverse_pointer->next==NULL){
            traverse_pointer->next=new_ptr;
            break;
        }
        traverse_pointer=traverse_pointer->next;
    }
  }
    
    return new_ptr;
}

Account *delete_at_random_position( Account *head ,int number ){
    Account *traverse_random=head;
    Account *traverse_random_prev=NULL;
    if(traverse_random->next==NULL ){
        free(traverse_random);
        traverse_random=NULL;
        traverse_random_prev=NULL;
        return NULL;
    }
    else if ( traverse_random->account_number==number){
         traverse_random_prev=traverse_random->next;
         free(traverse_random);
         head=traverse_random_prev;
    }
    else {
        while(traverse_random!=NULL){
        if(traverse_random->account_number==number){
            traverse_random_prev->next=traverse_random->next;
            free(traverse_random);
            head=traverse_random_prev;
            return head;
        }
        traverse_random_prev=traverse_random;
        traverse_random=traverse_random->next;
      }  
    }
    
    return head; 
}

Account  *search_at_random_position( Account *head ,int number ){
    Account *search_random=head;
    while(search_random!=NULL){
        if(search_random->account_number==number){
            return search_random;
        }
        search_random=search_random->next;
    }
    printf("Unable to find the detail of mentioned account number! Try again");
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
        printf("The entered account number  i.e %d is not correct! \n",number);
        printf("Please try again ! \n");
    }
    else if( balance <0 ){
        printf("The entered balance connot  i.e %lf be saved in account! \n",balance);
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
        return_value=next_new_account(head, name ,number ,balance);
    }
    return return_value;
}

void free_memory( Account *head){
    while(head!=NULL){
        free(head);
        head=head->next;
    }
    printf("Deleted all accounts details !");
}

int main(){
    
}