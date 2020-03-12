#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

extern void foo(void *dest, void *src, int size);
void move()
{
	char *p1 = (char*)0xDEADBEEF;
	char *p2 = malloc(100*1024*1024*sizeof(char));
	p1 = malloc(100*1024*1024*sizeof(char));
	for(int i = 0; i < 10; i++)
	{
		memcpy(p2, p1, 1024*1024*100);
	}
}
int main()
{
	clock_t t;
	t = clock();
	char *p1 = (char*)0xDEADBEEF;
	char *p2 = malloc(100*1024*1024*sizeof(char));
	p1 = malloc(100*1024*1024*sizeof(char));
	for(int i = 0; i < 10 ; i++)
	{
		foo(p2, p1, 1024*1024*100);
	}
	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("it took assembly code: %f secs \n", time_taken);
	
	clock_t t1;
	t1 = clock();
	move();
	t1 = clock() -t1;
	double time_taken1 = ((double)t1)/CLOCKS_PER_SEC;
	printf("it took c code: %f secs \n", time_taken1);
	return 0;
}
