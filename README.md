# generic_dynamic_array
The basic idea is to store the capacity and length of the array before the first element in the array. Even if the idea is simple the implementation requires use of some interesting C constructs. The ones that are kind of tricky to understand are explained below(also, I am not too experienced with C. So I might be understanding things wrong but I think this is right).

## void*, void**, \*(void**)&varName and do nothing statements
void** allows you to point to anything just like void* does, but void** can be directly derefrenced without casting it first like in the case of void*.
example:
```C
int main()
{
	int x = 10;
	int* xPtr = &x;
	float y = 10.5;
	float* yPtr = &y;
	void** array[2];
	void* otherArray[2];
	array[0] = (void**)xPtr;
	array[1] = (void**)yPtr;
	otherArray[0] = (void*)xPtr;
	otherArray[1] = (void*)yPtr;
	
	printf("%d %f \n" , *xPtr , *yPtr); //no need to cast before derefrencing for void**
	printf("%d %f \n" , *(int*)xPtr , *(float*)yPtr); //need to cast before derefrencing for void*
	return 0; 
}
```
if we have a function that accepts an arbitrary pointer and returns a void pointer then we have to cast the return value of the function when we use the function. We can make it so that the function will always return the correct pointer type without typecasting. This can be done using the \*(void**)&var trick.
example:
```C
#include<cstdlib>
#include<stdio.h>

void* foo(void* a)
{
	return a;
}

int main()
{
	int x =1 , y = 3;
	int* xPtr = &x;
	int* yPtr = &y;
	
	xPtr = (int*)foo(yPtr); //we want foo(void* ) to return the correct pointertype without us typecasting it
	*(void**)&xPtr = foo(yPtr); //foo will return the correct pointer type
	
	printf("%d \n" , *xPtr);
	return 0;
}
```
0; works as a do nothing statement and is useful in macros.
```C
int main()
{
	0; //this statement does nothing
	return 0;
}
```
