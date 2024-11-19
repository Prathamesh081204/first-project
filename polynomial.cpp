#include <stdio.h>
#include <stdlib.h>

struct node {
	## I am Prathamesh	
    int coefficient;
    int exponent;
    struct node* next;
};

struct node* createnode(int a, int x) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->coefficient = a;
    temp->exponent = x;
    temp->next = NULL;
    return temp;
}

struct node* create_poly(int degree, struct node* head) {
    struct node* temp = head;
    int degree2 = degree - 1;
    while (degree2 >= 0) {
        int j;
        printf("Enter coefficient of exponent %d: ", degree2);
        scanf("%d", &j);
        struct node* newnode = createnode(j, degree2);
        temp->next = newnode;
        temp = temp->next;
        degree2--;
    }
    return head;
}

void print_poly(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d x^%d", temp->coefficient, temp->exponent);
        temp = temp->next;
        if (temp != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

struct node* addition(struct node* head1 , struct node* head2){
    struct node* temp1 = head1 ;
    struct node* temp2 = head2 ;
    struct node* temp3 = head2 ;
    struct node* temp4 = head1 ;

    if(head1 -> exponent >= head2 -> exponent){
        while(temp1 != NULL){
            while(temp2 != NULL){
                if(temp1 -> exponent == temp2 -> exponent){
                    temp1 -> coefficient += temp2 -> coefficient ;
                    temp2 = temp2 -> next ;
                }
                else{
                    temp2 = temp2 -> next ;

                }

            }
            temp2 = temp3 ;
            temp1 = temp1 ->next ;
        }

        return head1 ;  
    }

    else if(head2 -> exponent >= head1 -> exponent){
        while(temp2 != NULL){
            while(temp1 != NULL){
                if(temp2 -> exponent == temp1 -> exponent){
                    temp2 -> coefficient += temp1 -> coefficient ;
                    temp1 = temp1 -> next ;
                }
                else{
                    temp1 = temp1 -> next ;

                }

            }
            temp1 = temp4 ;
            temp2 = temp2 ->next ;
        }

        return head2 ;  
    }
    
}


int main() {
    struct node* head;
    struct node* head3;
    int degree;
    int coeff;
    
    printf("Enter coefficient of the highest degree term: ");
    scanf("%d", &coeff);
    printf("Enter highest degree: ");
    scanf("%d", &degree);

    head = createnode(coeff, degree);
    head = create_poly(degree, head);
    print_poly(head);

    struct node* head2;
    int degree2;
    int coeff2;

    printf("Enter Polynomial 2  : ");
    printf("Enter coefficient of the highest degree term: ");
    scanf("%d", &coeff2);
    printf("Enter highest degree: ");
    scanf("%d", &degree2);

    head2 = createnode(coeff2, degree2);
    head2 = create_poly(degree2, head2);
    print_poly(head2);

    head3 = addition(head , head2) ;
    print_poly(head3);

    return 0;
}
