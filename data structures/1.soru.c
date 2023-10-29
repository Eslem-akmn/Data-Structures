#include <stdio.h>
#include <stdlib.h>

//1.SORU:Klavyedem -1 girilinceye kadar girilen tüm tek sayýlarý listenin baþýna çift sayýlarý da listenin sonuna ekleme

struct node{
	int data;
	struct node *next;
};

struct node *addFront(struct node *head,int key){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=key;
	temp->next=head;
	head=temp;
	return head;
}

struct node *addLast(struct node *head,int key){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=key;
	temp->next=NULL;
	if(head==NULL)
		head=temp;
	else{
		struct node *last=head; //last liste içinde gezinme saðlar
		while(last->next!=NULL)
			last=last->next;
		last->next=temp;	//temp son düðüm olur
	}	
	return head;
}
void printList(struct node *head) {
    if (head == NULL) {
        printf("Liste bos\n");
        return;
    }
    while (head != NULL) {
        printf("%d\n", head->data);
        head = head->next;
    }
}

int main() {
    int sayi; 
    struct node *head = NULL; 
    while (1) {
        printf("Sayi giriniz: ");
        scanf("%d", &sayi);
        if (sayi == -1) 
        	break;
        else if (sayi % 2 !=0 ) {
            head = addFront(head, sayi);
        }
        else {
            head = addLast(head, sayi);
        }
    }
    printList(head);
}


