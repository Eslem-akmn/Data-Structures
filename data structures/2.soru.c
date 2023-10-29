#include <stdio.h>
#include <stdlib.h>

/*2.SORU: LÝsteye rastegele üretilmiþ 100 sayý eklensin,girilen tüm sayýlarý büyükten küçüðe 
sýralayan ve ekrana yazan c kodu 
OUTPUT=>  54->58->63->.........->105;
*/

struct node{
    int data;
    struct node *next;
};

void sirala(struct node *head) {
    struct node *i, *j;
    int key;
    for (i=head;i!=NULL;i =i->next) {  //bubble sort 
        for (j =i->next;j!=NULL;j =j->next) {
            if (i->data > j->data) {
                key=i->data;
                i->data = j->data;
                j->data=key;
            }
        }
    }
}

void yazdir(struct node *head) {
    while (head != NULL) {
        printf("%d\n", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;
    int sayi, i;
    for (i = 0; i < 100; i++) {
        sayi = rand();
        struct node *temp= (struct node *)malloc(sizeof(struct node));
        temp->data = sayi;
        temp->next = head;
        head=temp;
    }
    sirala(head);
    yazdir(head);

    return 0;
}
