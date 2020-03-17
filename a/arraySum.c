#include <stdio.h>
#include <stdint.h>

int32_t add_array_c(int32_t *myarray, int size) {
int32_t sum = 0;
for(int i=0; i<size; i++) {
    sum += myarray[i];
}
return sum;
}

//rdi //rsi
int32_t add_array_asm(int32_t *myarray, int size);
int32_t *rev_array_asm(int32_t *myarray, uint32_t *rev_myarray, int size);


int main(int argc, char** avgs) {

int32_t myarray[5] = {3, 5, 6, 7, 8};
int32_t rev_myarray[5] = {0};
int32_t *rev;

//int32_t sum = add_array_c(myarray, 5);
//int32_t sum = add_array_asm(NULL, 0);
rev = rev_array_asm(myarray, rev_myarray, 5);

printf("original: ");
for (int i = 0; i < 5; ++i)
	printf("%d ", myarray[i]);
printf("\n");
printf("reverse: ");
for (int i = 0; i < 5; ++i)
	printf("%d ", rev_myarray[i]);
printf("\n");

printf("addresses\n");
for (int i = 0; i < 5; ++i)
	printf("%p\n", rev + i);

//printf("Sum is : %d\n", sum);
return 0;
}
