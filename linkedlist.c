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
    else if( number <=0 ){
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

void free_memory( Account *head){
    Account *head_copy=head;
    while(head_copy!=NULL){
        free(head_copy);
        head_copy=head->next;
        head=head->next;
    }
    printf("Deleted all accounts details !");
}

int main(){
    Account *head= NULL ;
    
    
}