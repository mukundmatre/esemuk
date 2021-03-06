#ifndef __CBUFF_H__
#define __CBUFF_H__

enum status{Full, Empty, Available};

typedef struct cbuff {
  uint8_t *buffer;
  uint8_t *head;
  uint8_t *tail;
  size_t length;
  size_t num_items;
  enum status state;
}cb_t;

cb_t *struc_ptr;
uint8_t *buff_ptr;

int buff_full();
int buff_empty();
void add_item(uint8_t data);
uint8_t remove_item();
void numitem_check();
void mem_allocate(uint8_t len);
void mem_free();

#endif
