/*DOUBLY LINKED LIST[APPEND,DISPLAY(forward,reverse),DELETE(head,element b/w head&tail)]*/
#include<stdio.h>
#include<stdlib.h>
void main()
{
	struct node{
		struct node *prev;
		int data;
		struct node *next;};
	int ch,entry;
	struct node *head=NULL,*pos=NULL,*tail=NULL;
	while(1){
		printf("\nMENU\n1.APPEND\n2.DISPLAY(FORWARD)\n3.DISPLAY(REVERSE)\n4.DELETE(HEAD)\n5.DELETE(ELEMENT B/W HEAD&TAIL)\n6.EXIT\n\nEnter choice: ");
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
				break;}
			else{
				tail->next=(struct node *)malloc(sizeof(struct node));
				tail->next->prev=tail;
				tail->next->data=entry;
				tail->next->next=NULL;
				tail=tail->next;}
				break;
			}
		case 2:{
			pos=head;
			printf("Elements are: ");
			while(pos!=NULL){
				printf("\t%d",pos->data);
				pos=pos->next;}
				break;}
		case 3:{
			pos=tail;
			printf("Elements are: ");
			while(pos!=NULL){
				printf("\t%d",pos->data);
				pos=pos->prev;}
				break;
			}
		case 4:{
			struct node*del=head;
			head=head->next;
			del->next=NULL;
			head->prev=NULL;
			free(del);
			printf("\nDELETED\n");
			break;}
		case 5:{
			struct node *temp=head;
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
		
		case 6:{
			printf("\nGOODBYE\n");
			exit(0);}
		}
	}
}
 
