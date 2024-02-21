#include <stdio.h>
#include <malloc.h>

struct pack
{
  int a;
  int b;
};

struct pack * cmap[10];


void modify(int key, int aval)
{
   struct pack * cval = cmap[key];
   
   printf("\n modify before cval=%u :: key=%d ,pack->a=%d , pack->b=%d ",cval,key,cval->a,cval->b);
   cval->a = aval;
   printf("\n modify after :: key=%d ,pack->a=%d , pack->b=%d ",key,cval->a,cval->b);
   //cmap[key] = cval;  
}


void read(int key)
{
   struct pack * cval = cmap[key];
   printf("\n read cval=%u:: key=%d ,pack->a=%d , pack->b=%d ",cval,key,cval->a,cval->b);
  
}

void put(int key,int a,int b)
{
   struct pack * cval = (struct pack *)malloc(sizeof(struct pack));
   cval->a = a;
   cval->b = b;
   cmap[key] = cval;
  
}

void printstruct(struct pack* cval)
{
   printf("\n generic struct :: address=%u, pack->a=%d , pack->b=%d ",cval,cval->a,cval->b);
  
}

int  main()
{
  put(1,30,31);
  read(1);
  modify(1,97);
  read(1); 
  
  
  struct pack* context = cmap[1];
  printstruct(context);
  
  modify(1,540);
  read(1); 
  printstruct(context);
  /*
  free(cmap[1]);
  cmap[1] = NULL;
  //read(1);
  printf("\n printing now :::: \n");
  printstruct(context);
  // read(1);
   */
  return 0;
}
