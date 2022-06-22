/*DOUBLY LINKED LIST[APPEND,DISPLAY(forward,reverse),DELETE(head,element b/w head&tail,tail)]*/
#include<stdio.h>
#include<stdlib.h>
void main()
{
	struct node{
		struct node *prev;
		int data;
		struct node *next;};
	int ch,entry,c;
	struct node *head=NULL,*pos=NULL,*tail=NULL;
	while(1){
		printf("\nMENU\n1.APPEND\n2.DISPLAY(FORWARD)\n3.DISPLAY(REVERSE)\n4.DELETE HEAD\n5.DELETE TAIL\n6.DELETE ELEMENT B/W HEAD&TAIL\n7.EXIT\n\nEnter choice: ");
		scanf("%d",&ch);
		switch(ch){
		case 1:{
			printf("Enter data: ");
			scanf("%d",&entry);
			if (head==NULL){
				head=(struct node *)malloc(sizeof(struct node));
				head->prev=NULL;
				head->data=entry;
				head->next=NULL;
				pos=head;
				tail=head;
				printf("\nAPPENDED\n");
				break;}
			else{
				tail->next=(struct node *)malloc(sizeof(struct node));
				tail->next->prev=tail;
				tail->next->data=entry;
				tail->next->next=NULL;
				tail=tail->next;
				printf("\nAPPENDED\n");}
				break;
			}
		case 2:{
			pos=head;
			if(pos==NULL){
				printf("\nEMPTY\n");
				break;}
			else{
				printf("Elements are: ");
				while(pos!=NULL){
					printf("\t%d",pos->data);
					pos=pos->next;}
					break;}}
		case 3:{
			pos=tail;
			if(pos==NULL){
				printf("\nEMPTY\n");
				break;}
			else{
				printf("Elements are: ");
				while(pos!=NULL){
					printf("\t%d",pos->data);
					pos=pos->prev;}
					break;}}
		case 4:{
			struct node *del=head;
			if(head==NULL){
				printf("EMPTY\n");
				break;}
			if(head->next==NULL){
				struct node *del=head;
				del->next=NULL;
				del->prev=NULL;
				head=NULL;
				tail=NULL;
				free(del);
				printf("\ndeleted\n");}
			else{
				struct node *del=head;
				head=head->next;
				del->next=NULL;
				head->prev=NULL;
				free(del);
				printf("\ndeleted\n");}
				break;}
		case 5:{
			struct node *del=tail;
			if(tail==NULL){
				printf("\nEMPTY\n");
				break;}
			if(tail->prev==NULL){
				struct node *del=tail;
				del->next=NULL;
				del->prev=NULL;
				head=NULL;
				tail=NULL;
				free(del);
				printf("\nDELETED\n");
				break;}
			else{
				struct node *del=tail;
				tail=tail->prev;
				tail->next=NULL;
				free(del);
				pos=tail;
				printf("\nDELETED\n");
				break;}}
		case 6:{
			struct node *temp=head;
			if(head==NULL){
				printf("EMPTY");
				break;}
			c=0;pos=head;
			while(pos!=NULL){
				pos=pos->next;
				c++;}
			if(c>3){
				printf("\nEnter position of data: ");
				scanf("%d",&entry);
				for(int i=0;i<entry-1;i++)
					temp=temp->next;
					struct node *del=temp->next;
					temp->next=temp->next->next;
					temp->next->prev=temp;
					del->prev=NULL;
					del->next=NULL;
					free(del);
					printf("\nDELETED\n");
					break;}
			else if(c=3){
				for(int i=0;i<entry-1;i++)
					temp=temp->next;
					struct node *del=temp->next;
					temp->next=temp->next->next;
					temp->next->prev=temp;
					del->prev=NULL;
					del->next=NULL;
					free(del);
					printf("\nDELETED\n");
					break;}
				
			else{
				printf("No elements between head and tail\n");
				break;}}
		
		case 7:{
			printf("\nGOODBYE\n");
			exit(0);}
		default:
			printf("Error,wrong choice\n");
		}
	}
}
