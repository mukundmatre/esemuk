//circular buffer optimized for use with UART
#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include<stdlib.h>
#include "cbuff.h"

cb_t *struc_ptr;
char *buff_ptr;

/*int main()
{
  uint8_t i,data,full,empty,l;
  int addrem;
  l=5;
  mem_allocate(l);
  struc_ptr->length = l;
  struc_ptr->buffer = buff_ptr;
  struc_ptr->head = buff_ptr;
  struc_ptr->tail = buff_ptr;
  while(1)
  {
  printf("\nData in buffer: ");
  for(i=0;i<struc_ptr->length;++i)
  {
    printf("\n%c\n",*(struc_ptr->buffer+i));
  }
  printf("\nEnter 0 to add and 1 to remove item :" );
  scanf(" %d",&addrem);
  full = buff_full();
  empty = buff_empty();
  if ((addrem == 0) && full!=1)
  {
  	printf("Enter data: ");
    scanf(" %c",&data);
    add_item(data);
  }
  else if((addrem == 0) && full==1)
  {
  	printf("Buffer is full ");
  }

  else if((addrem == 1) && empty!=1 )
  {
  	remove_item();
  }

  else if((addrem == 1) && empty==1 )
  {
  	printf("Buffer is empty ");
  }


  else
  {
  	printf("Invalid input");
  }
}
void mem_free();
}*/


int buff_full()
{
  int i;
  numitem_check();
  if (struc_ptr->num_items == struc_ptr->length)
  {
  	(struc_ptr->state)=Full;
    return 1;
  }
  else
  {
  	(struc_ptr->state)=Available;
    return 0;
  }

}


int buff_empty()
{
  int i;
  numitem_check();
  if (struc_ptr->num_items==0)
  {
  	(struc_ptr->state)=Empty;
  	return 1;
  }
  else
  {
  	(struc_ptr->state)=Available;
  	return 0;
  }
}


void add_item(char item)
{

  if (struc_ptr->head<((struc_ptr->buffer)+((struc_ptr->length)-1)))
  {
  	*(struc_ptr->head)= item;
  	(struc_ptr->head)++;
	}
  else if (struc_ptr->head == ((struc_ptr->buffer) + ((struc_ptr->length)-1)))
  {
  	*(struc_ptr->head) = item;
  	struc_ptr->head = struc_ptr->buffer;
  }
  //printf("\nWritten data %c", item);
  numitem_check();
  //printf("\nNumber of items in buffer %d", struc_ptr->num_items);
}


char remove_item()
{
  char dataout;

  if(struc_ptr->tail<((struc_ptr->buffer)+((struc_ptr->length)-1)))
  {
  	dataout = *(struc_ptr->tail);
	*(struc_ptr->tail) = NULL;
	(struc_ptr->tail)++;
	//printf("Read Data: %c",dataout);
  }
  else if(struc_ptr->tail==((struc_ptr->buffer)+((struc_ptr->length)-1)))
  {
  	dataout = *(struc_ptr->tail);
  	*(struc_ptr->tail) = NULL;
  	struc_ptr->tail = struc_ptr->buffer;
  	//printf("Read Data: %c",dataout);
  }
  numitem_check();
  return dataout;
  //printf("\nNumber of items in buffer %d", struc_ptr->num_items);
}


void numitem_check()
{
  int i;
  struc_ptr->num_items = 0;
  for (i=0;i<struc_ptr->length;++i)
  {
    if(*(struc_ptr->buffer + i)!=NULL)
	{
      (struc_ptr->num_items)++;
	  }
  }
}

void mem_allocate(int len)
{
  struc_ptr = (cb_t *) malloc(sizeof(cb_t));
  buff_ptr = (char*) calloc(len , sizeof(char));

}

void mem_free()
{
  free(struc_ptr);
  free(buff_ptr);
}
