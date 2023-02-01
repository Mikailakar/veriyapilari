#include <stdio.h>
#include <stdlib.h>

struct dugum{
    int data;
    struct dugum *previous;
    struct dugum *next;
};
typedef struct dugum daireselCYBListe;
daireselCYBListe *first = NULL;
daireselCYBListe *last = NULL;
daireselCYBListe *temp = NULL;
daireselCYBListe *temp2 = NULL;
daireselCYBListe *temp3 = NULL;
void topluDugumOlustur(int [], int);
void list();
void elemanAra(int);
void basaEkle(int);
void sonaEkle(int);
void arayaEkle(int, int);
void aradansil(int);
void bastansil();
void sondansil();
int elemanSay();
int eleman;
int main(){
	int dizi[] = {5, 15, 75, 40};
	int es = sizeof(dizi)/sizeof(int);
	topluDugumOlustur(dizi, es);
	list();
	printf("%d\n", elemanSay());
	elemanAra(15);
	arayaEkle(33, 3);
	list();
	aradansil(2);
	list();
	return 0;
}
void topluDugumOlustur(int dizi[], int N){
	int i;
	if(N == 0)
		first = NULL;
	else{
		for(i = 0; i < N; i++){
			temp = (daireselCYBListe*)malloc(sizeof(daireselCYBListe));
			if(i == 0){
				first = temp;
				temp -> data = dizi[0];
				temp -> next = first;
				temp -> previous = last;
				last = temp;
			}else{
				temp -> data = dizi[i];
				temp2 -> next = temp;
				temp -> next = first;
				temp -> previous = temp2;
				last = temp;
			}
			temp2 = temp;		
		}
	}
}
void list(){
    temp = first;
    do{
        printf("%d -- ", temp -> data);
        temp = temp -> next;
    }while(temp != first);
	printf("\n");
}
int elemanSay(){
	temp = first;
	int sayac = 0;
	if(first == NULL)
		return 0;
	do{
		temp = temp -> next;
		sayac++;
	}while(temp != first);
	return sayac;
}
void elemanAra(int aranan){
	temp = first;
	if(first == NULL){
		printf("Bos liste!\n");
		return;
	}
	do{
		if(temp -> data == aranan){
			printf("%d elemani listede bulundu\n", aranan);
			return;
		}
		temp = temp -> next;
	}while(temp != first);
	printf("%d elemani listede bulunamadi\n", aranan);
}
void arayaEkle(int data, int a){
	if(first == NULL || a == 0)
		basaEkle(data);
	else{
		temp = first;
		for(int i = 0; i < a - 1; i++){
			temp = temp -> next;
		}
		if(temp  == last)
			sonaEkle(data);
		else{
			temp2 = temp -> next;
			temp3 = (daireselCYBListe*)malloc(sizeof(daireselCYBListe));
			temp3 -> data = data;
			temp -> next = temp3;
			temp3 -> next = temp2;
			temp2 -> previous = temp3;
			temp3 -> previous = temp;
		}
	}
}
void basaEkle(int data){
	if(first == NULL){ 
		first = (daireselCYBListe*)malloc(sizeof(daireselCYBListe));
		first -> data = data;
		first -> previous = first;
    	first -> next = first;
	}else{
		temp = (daireselCYBListe*)malloc(sizeof(daireselCYBListe));
		temp -> data = data;
		first -> previous = temp;
		temp -> next = first;
		temp -> previous = last;
		first = temp;
		last -> next = first;
	}
}
void sonaEkle(int data){
	if(first == NULL)
		basaEkle(data);
	else{
		temp = (daireselCYBListe*)malloc(sizeof(daireselCYBListe));
		temp -> data = data;
		last -> next = temp;
		temp -> previous = last;
		temp -> next = first;
		last = temp;
		first -> previous = last;
	}
}
void aradansil(int a){
	if(first == NULL)
		printf("Liste bos!");
	else if(a == 0)
		bastansil();
	else{
		temp = first;
		for(int i = 0; i < a - 1; i++){
			temp = temp -> next;
		}
		if(temp -> next == last)
			sondansil();
		else{
			temp2 = temp -> next -> next;
			free(temp -> next);
			temp -> next = temp2;
			temp2 -> previous = temp;
		}
	}
}
void bastansil(){
	if(first == NULL)
		printf("Bos liste!");
	else if(first == last){
		first = NULL;
		last = NULL;
		printf("Listede eleman kalmadi.");
	}else{
		temp = first -> next;
		temp -> previous = last;
		last -> next = temp;
		free(first);
		first = temp;
	}
}
void sondansil(){
	if(first == NULL)
		printf("Bos liste!");
	else if(first  == last){
		first = NULL;
		last = NULL;
		printf("Listede eleman kalmadi.");
	}else{
		temp = last -> previous;
		temp -> next = first;
		first -> previous = temp;
		free(last);
		last = temp;
	}
}
