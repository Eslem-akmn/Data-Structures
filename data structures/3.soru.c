#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentsNode{
	char name[30];
	int sNum;
	int age;
	struct studentsNode *next;
};
struct studentsNode *record(struct studentsNode *head)
{
	struct studentsNode *students=(struct studentsNode*)malloc(sizeof(struct studentsNode));
	printf("\nEnter the student name: ");
	scanf("%s",students->name);
	printf("Enter the student number: ");
	scanf("%d",&students->sNum);
	printf("Enter the student age: ");
	scanf("%d",&students->age);
	
	students->next=NULL;
	printf("Student is added on the list\n");
	if(head==NULL) //liste boþsa student düðümü listenin baþý olsun
		head=students;
	else
	{
		students->next=head;
		head=students;
    }
    return head;
}

void listing(struct studentsNode *head){
	struct studentsNode *temp=head;
	int counter=0,i=1; 
	if(head==NULL){     //liste boþsa 
		printf("List is empty..");  
	}
	else{
		while(temp!=NULL){
			printf("\n%d-%s	 	%d		%d\n" ,i,temp->name,temp->sNum,temp->age);
			temp=temp->next;
			counter++;
			i++;
		}
	}
	printf("\nNumber of students: %d",counter);
}

void search(struct studentsNode *head,char searchname[30]){
	int found=0;
	struct studentsNode *temp=head;
	while(temp!=NULL){
		if(strcasecmp(temp->name,searchname)==0){     //girilen isimle düðümdeki isim eþit mi?
			printf("\nRecord found\n");
			printf("\n%s	%d	%d\n",temp->name,temp->sNum,temp->age);
			found=1;
			break;
		}
		else{
			temp=temp->next;
		}	
	}
	if(!found){    //girilen isim listede yoksa
		printf("Searched name not found.\n"); 
	}
	
}
struct studentsNode *del(struct studentsNode *head, char *deleted){
	struct studentsNode *temp=head;
	if(strcmp(head->name,deleted)>=0){     //girilen isim listenin baþýysa
		temp=temp->next;
		head->next=temp->next;
		free(temp);       
	}
	else{
		while(temp->next!=NULL && strcmp(temp->name,deleted)<0){
			temp=temp->next;
		}
		if(temp->next==NULL){       //girilen isim son düðümse
			return head;
		}
		struct studentsNode *delNode=temp->next;   //silinecek isim
		temp->next=delNode->next;
		free(delNode);
	}
	return head;
}

void longest(struct studentsNode *head){
	struct studentsNode *temp=head;
	struct studentsNode *longest=head;
	temp=temp->next;	
	while(temp!=NULL){
		if(strlen(temp->name)>strlen(longest->name)){  //listedeki en uzun elemaný bulana kadar
		struct studentsNode *p;
		p=temp;
		temp=temp->next;
		longest=p;
		}
		else{
		temp=temp->next;
		}
	}
	printf("Longest name: %s and length: %d",longest->name,strlen(longest->name));
}

int main(){
	struct studentsNode *head=NULL;
	int choice;
	char searchname[30];
	char deleted[30];
	int i;
	while(choice!=6){
		printf("\nTransactions\n");
		printf("1-Add record\n");
		printf("2-Student information\n");
		printf("3-Searching for records by student name\n");
		printf("4-Deregistration\n");
		printf("5-Longest name\n");
		printf("6-Exit\n");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				head=record(head);
				break;
			case 2:
				listing(head);
				break;
			case 3:
				printf("Enter the name to search for: ");
				scanf("%s",searchname);
				search(head,searchname);	
				break;
			case 4:
				printf("Enter the name: ");
				scanf("%s",deleted);
				del(head,deleted);
				break;
			case 5:
				longest(head);
				break;
			case 6:
				break;				
		}
	}
}

