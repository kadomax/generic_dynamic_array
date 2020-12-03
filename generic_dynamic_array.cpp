#include<cstdlib>
#include<stdio.h>

#define len(a) *((int*)a - 2)
#define cap(a) *((int*)a - 1)
#define _header(a) ((int*)a - 2)
#define init(a) ((*(void**)&(a)) = _init(a , sizeof(*a)))
void* _init(void* arr , size_t itemsize)
{
	int* p = (int*)malloc(itemsize + 2*sizeof(int));
	p[0] = 0;
	p[1] = 1;
	return (p+2);
}

#define grow(a) (*((void**)&(a)) = _grow(a , sizeof(*a)))
void* _grow(void* a , size_t itemsize)
{
	int newCap = 2*cap(a);
	int* p = (int*)realloc(_header(a) , itemsize*newCap + 2*sizeof(int));
	p[1] = newCap;
	return p + 2;
}

#define growcondition(a , n) (len(a) + n >= cap(a) ? 1 : 0)
#define maybeGrow(a , n) (growcondition(a , n) ? grow(a) , 0 : 0)
#define push(a , ele) ( maybeGrow(a , 1) , (a)[_header(a)[0]++] = ele )

int main()
{
	float* a = NULL;
	init(a);
	grow(a);
	push(a , 2.3);
	push(a , 3.4);
	push(a , 3.5);
	push(a , 4.3);
	push(a , 5.6);
	
	for(int i = 0 ; i < len(a) ; i++)
	{
		printf("%f\n" , a[i]);
	}
	
	printf("%d %d\n" , len(a) , cap(a));
	return 0;
}