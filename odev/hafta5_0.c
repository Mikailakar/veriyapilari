#include <stdio.h>
#include <stdlib.h>

struct hanoiDynamicSeries{
	int top;
	int capacity;
	int *series;
};
typedef struct hanoiDynamicSeries stack;
stack *create();
int full(stack*);
int empty(stack*);
void increaseSize(stack*);
void add(stack*, int);
void top(stack*);
void eremove(stack*);
void sfree(stack*);
void list(stack*);
int main(){
	stack *stack1 = create();
	add(stack1, 3);
	list(stack1);
	add(stack1, 2);
	list(stack1);
	add(stack1, 5);
	list(stack1);
	add(stack1, 4);
	list(stack1);	
	return 0;
}
stack *create(){
	stack *new = (stack*)malloc(sizeof(stack));
	if(!new)
		return NULL;
	new -> capacity = 1;
	new -> top = -1;
	new -> series = malloc(new -> capacity * sizeof(stack));
	if(!new -> series)
		return NULL;
	return new;
}
int full(stack *S){
	return S -> top == S -> capacity - 1;
}
int empty(stack *S){
    return S -> top == -1;
}
void increaseSize(stack *S){
	S -> capacity = S -> capacity * 2;
	S -> series = realloc(S -> series, sizeof(S -> series) * S -> capacity);
}
void add(stack *S, int element){
	if(full(S))
		increaseSize(S);
	int elements[100];
	int i = 0;
	for(;!empty(S) && element > S -> series[S -> top]; i++){
		elements[i] = S -> series[S -> top];
		S -> top--;
	}
	elements[i] = element;
	while(i >= 0){
		S -> series[++S -> top] = elements[i];
		i--;
	}
	printf("%d elemani eklendi.\n", element);
}
void list(stack *S){
	if(empty(S))
        printf("Yigin bos! Listelenecek eleman yoktur.\n");
    else{
        int temp = S -> top;
        while(temp != -1){
        	printf("%d ", S -> series[temp]);
        	temp--;
		}
		printf("\n");
    }
}
void top(stack *S){
	if(empty(S))
        printf("Yigin bos!\n");
    else
        printf("Tepedeki eleman: %d\n", S -> series[S -> top]);	
}
void eremove(stack *S){
	if(empty(S))
        printf("Yigin bos! Yigindan silinecek eleman yoktur.\n");
    else{
    	printf("%d elemani yigindan cikartildi.\n", S -> series[S -> top]);
    	S -> top--;
	}
}
void sfree(stack *S){
	if(S){
		if(S -> series)
			free(S -> series);
		free(S);
	}
}
