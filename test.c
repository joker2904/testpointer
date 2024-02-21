#include <stdio.h>
#include <malloc.h>

int* getarray1()
{

  int* p = (int*)malloc(sizeof(int) * 2);
  p[0] = 12;
  p[1] = 13;
  printf("\narray1 inside = %d %d ,  %d %d",p,*(p+0),p+1,*(p+1) );
  return p;   
}


void getarray2(int* p)
{

  //p = (int*)malloc(sizeof(int) * 2);
  printf("\narray2 inside before =  %d %d ,  %d %d",p,*(p+0),p+1,*(p+1));
  p[0] = 15;
  p[1] = 16;
  printf("\narray2 inside after =  %d %d ,  %d %d",p,*(p+0),p+1,*(p+1));
}


int  main()
{
  int* q = getarray1();
  printf("\narray1 outside =  %d %d ,  %d %d",q,*(q+0),q+1,*(q+1));

  getarray2(q);
  printf("\narray1 outside =  %d %d ,  %d %d",q,*(q+0),q+1,*(q+1));
  return 0;
}
