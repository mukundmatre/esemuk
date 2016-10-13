//header file for circular buffer
#ifndef __CBUFF_H__
#define __CBUFF_H__

enum status{Full, Empty, Available};

typedef struct cbuff {
  char *buffer;
  char *head;
  char *tail;
  int length;
  int num_items;
  enum status state;
}cb_t;

void add_item(char data);
char remove_item();
void numitem_check();
void mem_allocate(int len);
void mem_free();

#endif
