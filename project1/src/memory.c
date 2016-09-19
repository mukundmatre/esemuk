#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include"memory.h"


int8_t my_memmove(uint8_t *src, uint8_t *dst, uint32_t length){
 uint32_t i=0;
 uint8_t temp[100];
    
 if(src != NULL){
    for(i=0;i<length;i++){
       *(temp+i)=*(src+i);
     }

    for(i=0;i<length;i++){
       *(dst+i)=*(temp+i);
     }
    
    return 0;
 }
 
 else
    return 1;

}


int8_t my_memzero (uint8_t *src,uint32_t length){
  
 if(src != NULL){
     unsigned char *p;
     
      for(p = src; 0 < length ; ++p, --length)
         *p = 0;
		
       return 0;
    }
  
  else
  return 1;
 }



int8_t my_reverse(uint8_t *src, int length)
{
 uint16_t j;

 if(src != NULL){
   int8_t temp;
   
   for(j=0;j<(length/2);j++){
      temp=*(src+j);
      *(src+j)=*(src+length-j-1);
      *(src+length-j-1)=temp;
    }
	
    return 0;
 }

 else
    return 1;

}
