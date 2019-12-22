#include <stdio.h>
#define LEN 50
int numbers[LEN];
void shift_element(int* arr, int i);
void insertion_sort(int *arr,int len);

void shift_element(int* arr, int i) {
    while (i > 0) {
        *(arr+i) = *(arr+i-1);
        i--;
    }
}

void insertion_sort(int *arr,int len) {
	int *i, *last = arr + len;
	int ival;
	for(i = arr + 1; i < last; i++){
		if(*i < *(i-1)){
			for(ival = *i; i > arr && *(i-1) > ival; i--) {
				*i = *(i-1);
			}	
			*i = ival;
		}
	}
}
int main(){
    int length=0,c, bytesread;
    char input[LEN];
    printf("Enter numbers: \n");
    fgets(input, sizeof(input), stdin);
    char* input1 = input;
    while (sscanf(input1, "%d%n", &c, &bytesread) > 0) {
       *(numbers +length ++) = c;
        input1 += bytesread;
    }
    insertion_sort(numbers,length);
    for ( int i = 0; i < length-1; i++ ) {
        printf("%d,",*( numbers+i));
    }
    printf("%d\n",*( numbers + length-1));
    return 0;
}
