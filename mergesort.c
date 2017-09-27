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

node * mergelists(node *head1,node *head2) /*
											Accepts 2 pointers,each pointing to one pre-sorted list,	
											and combines these into one list 
										   */
{		
		node * ptr=NULL;					
		list=temp;
		while(head1!=NULL && head2!=NULL)	//Iterates through both lists until one reaches end
		{
			
			if (head1->duration<head2->data)	//Check if list1 head is greater than list2
			{
				if(ptr==NULL)					//if ptr is empty, make it the root of list
				{
					ptr=head1;
				}
				else							/* otherwise, make ptr point to the next node 
													and then set it equal to that next node */
				{
					ptr->next=head1;
					ptr=ptr->next;
				}
				head1=head1->next;				//move head1 over one node
			}
			else							//If head1>=head2 then...
			{
				if(ptr==NULL)				//if ptr is empty, make it the root of list
				{
					ptr=head2;
				}
				else						/* otherwise, make ptr point to the next node 
													and then set it equal to that next node */
				{
					ptr->next=head2;
					ptr=list->next;
				}
				head2=head2->next;
			}
				
		}
		if (head1==NULL)					//If head1 list is at end of list, add rest of head2
		{
			while(head2!=NULL)
			{	
				if (ptr==NULL)
				{
					ptr=head2;
				}
				else
				{
					ptr->next=head2;
					ptr=ptr->next;
				}
			}
		}
		if (head2==NULL)					//If head2 list is at end of list, add rest of head1
		{
			while (head1!=NULL)
			{
				if (ptr==NULL)
				{
					ptr=head1;
					
				}
				else
				{
					ptr->next=head1;
					ptr=ptr->next;
				}
			}
		}
		return ptr;							//returns node pointer to combined, sorted list of head1 and head2
}
node * mergesort (node *head)				/*
												Heart of mergesort algorithm. I plan to call the merge function
												within this function. (Recursive)
												Method also calls length function to know length of linked list
											*/	
{
	node *final=NULL;
	node *half1=NULL;
	node *half2=NULL;
	int dist=length(head);
	int mid=(dist/2);
	if (dist==1)
	{
		return head;
	}
	else									
	{		
								//split list
		int i;
		for (i=0;i<dist;i++)	/* assigns half of the current linked list to one node pointer and 
									the rest to the other node pointer. I count from one to the total
									amount of nodes, and I assign the first half to the first variable
									and second half to second variable.
								*/	
		{
			if (i<=mid)			/*mid(half of total number of node) is used as upper bound to amount that 
								  is assigned to the first of two lists.
								  
								  unfortunately, this may be the weakest portion of the sorting. I am still trying to 
								  find a way to split the list into two pieces to be arguments
								  for the recursive part later
								*/
			{
				if (half1==NULL)
				{
					half1=head;
				}
				else
				{
					half1->next=head;
				}
			}
			else
			{
				if (half2==NULL)
				{
					half2=head;
				}
				else
				{
					half2->next=head;
				}
			}
			head=head->next;
			
		}			
		
		
		half1=mergesort(half1);
		half2=mergesort(half2);
	}
	final=mergelists(half1,half2);
	return final;
}
