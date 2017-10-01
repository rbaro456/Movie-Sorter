/// ***PUT CODE FOR MEGE SORT IN HERE ***///
/// ***PUT CODE FOR MEGE SORT IN HERE ***///
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int length (node *ptr)				     //Length of linked list
{
	int count=0;
	while (ptr!=NULL) 					 //Iterate thru list and increment count until end is reached
	{
		count++;
		ptr=ptr->next;
	}
	return count;						//returns int value for length of linked list
}

node * mergelists(node *head1,node *head2, int index) /*
											Accepts 2 pointers,each pointing to one pre-sorted list,	
											and combines these into one list 
										   */
{		
		node *front=NULL;
		node * ptr=NULL;					
		while(head1!=NULL && head2!=NULL)	//Iterates through both lists until one reaches end
		{
			
			if (strcmp(head1->category[index],head2->category[index])>=0)	//Check if list1 head is greater than list2
			{
				if(front==NULL)					//if ptr is empty, make it the root of list
				{
					
					front=head2;
					ptr=front;
				}
				else							/* otherwise, make ptr point to the next node 
													and then set it equal to that next node */
				{
					ptr->next=head2;
					ptr=ptr->next;
					
				}
				head2=head2->next;				//move head1 over one node
			}
			else							//If head1>=head2 then...
			{
				if(front==NULL)				//if ptr is empty, make it the root of list
				{
					front=head1;
					ptr=front;
				}
				else						/* otherwise, make ptr point to the next node 
													and then set it equal to that next node */
				{
					ptr->next=head1;
					ptr=ptr->next;
				}
				
				head1=head1->next;
			}
				
		}
		if (head1==NULL)					//If head1 list is at end of list, add rest of head2
		{
			
			while(head2!=NULL)
			{	
				if (front==NULL)
				{
					front=head2;
					ptr=front;
				}
				else
				{
					ptr->next=head2;
					ptr=ptr->next;
				}
				head2=head2->next;
			}
			
		}
		else if (head2==NULL)					//If head2 list is at end of list, add rest of head1
		{
			while (head1!=NULL)
			{
				if (front==NULL)
				{
					front=head1;
					ptr=front;
					
				}
				else
				{
					ptr->next=head1;
					ptr=ptr->next;
				}
				head1=head1->next;
			}
		}
		return front;							//returns node pointer to combined, sorted list of head1 and head2
}
node * mergesort(node *head,int ind)				/*
												Heart of mergesort algorithm. I plan to call the merge function
												within this function. (Recursive)
												Method also calls length function to know length of linked list
											*/	
{

	int index=ind;
	int dist=length(head);
	int mid=(dist/2);
	int i;
	node *ptr=head;
	node *half1=head;
	node *half2=NULL;
	if (dist==1)
	{
		return head;
	}
	else									
	{		
								//split list
		for (i=1;i<=dist;i++)	/* assigns half of the current linked list to one node pointer and 
									the rest to the other node pointer. I count from one to the total
									amount of nodes, and I assign the first half to the first variable
									and second half to second variable.
								*/	
		{
			if(i==mid)
			{
				half2=ptr->next;	
				ptr->next=NULL;
				break;				
			}									
			ptr=ptr->next;							
		}			
			
	}				
		half1=mergesort(half1,index);
		half2=mergesort(half2,index);
	return mergelists(half1,half2,index);
}








node * nummergelists(node *head1,node *head2, int index) /*
											Accepts 2 pointers,each pointing to one pre-sorted list,	
											and combines these into one list 
										   */
{		
		node *front=NULL;
		node * ptr=NULL;					
		while(head1!=NULL && head2!=NULL)	//Iterates through both lists until one reaches end
		{
			
			if (atoi(head1->category[index])>atoi(head2->category[index]))	//Check if list1 head is greater than list2
			{
				if(front==NULL)					//if ptr is empty, make it the root of list
				{
					
					front=head2;
					ptr=front;
				}
				else							/* otherwise, make ptr point to the next node 
													and then set it equal to that next node */
				{
					ptr->next=head2;
					ptr=ptr->next;
					
				}
				head2=head2->next;				//move head1 over one node
			}
			else							//If head1>=head2 then...
			{
				if(front==NULL)				//if ptr is empty, make it the root of list
				{
					front=head1;
					ptr=front;
				}
				else						/* otherwise, make ptr point to the next node 
													and then set it equal to that next node */
				{
					ptr->next=head1;
					ptr=ptr->next;
				}
				
				head1=head1->next;
			}
				
		}
		if (head1==NULL)					//If head1 list is at end of list, add rest of head2
		{
			
			while(head2!=NULL)
			{	
				if (front==NULL)
				{
					front=head2;
					ptr=front;
				}
				else
				{
					ptr->next=head2;
					ptr=ptr->next;
				}
				head2=head2->next;
			}
			
		}
		else if (head2==NULL)					//If head2 list is at end of list, add rest of head1
		{
			while (head1!=NULL)
			{
				if (front==NULL)
				{
					front=head1;
					ptr=front;
					
				}
				else
				{
					ptr->next=head1;
					ptr=ptr->next;
				}
				head1=head1->next;
			}
		}
		return front;							//returns node pointer to combined, sorted list of head1 and head2
}








node * nummergesort(node *head,int ind)				/*
												NUMBER VERSION Heart of mergesort algorithm. I plan to call the merge function
												within this function. (Recursive)
												Method also calls length function to know length of linked list
											*/	
{

	int index=ind;
	int dist=length(head);
	int mid=(dist/2);
	int i;
	node *ptr=head;
	node *half1=head;
	node *half2=NULL;
	if (dist==1)
	{
		return head;
	}
	else									
	{		
								//split list
		for (i=1;i<=dist;i++)	/* assigns half of the current linked list to one node pointer and 
									the rest to the other node pointer. I count from one to the total
									amount of nodes, and I assign the first half to the first variable
									and second half to second variable.
								*/	
		{
			if(i==mid)
			{
				half2=ptr->next;	
				ptr->next=NULL;
				break;				
			}									
			ptr=ptr->next;							
		}			
			
	}				
		half1=nummergesort(half1,index);
		half2=nummergesort(half2,index);
	return nummergelists(half1,half2,index);
}












