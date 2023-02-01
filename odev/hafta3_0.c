#include <stdio.h>
#include <stdlib.h>

struct dugum{
    int data1;
    double data2;
    struct dugum *previous;
    struct dugum *next;
};
typedef struct dugum cift_yonlu_bliste;
cift_yonlu_bliste *first = NULL;
cift_yonlu_bliste *last = NULL;
cift_yonlu_bliste *temp = NULL;
cift_yonlu_bliste *temp2 = NULL;
cift_yonlu_bliste *temp3 = NULL;
void list();
void basaEkle(int, double);
void sonaEkle(int, double);
void arayaEkle(int, double, int);
void aradansil(int);
void bastansil();
void sondansil();
int eleman1;
double eleman2;
int main(){
	basa_ekle(5, 7.5);
	list();
	sona_ekle(8, 9.3);
	list();
	araya_ekle(14, 1.1, 1);
	list();
	araya_ekle(3, 2.1, 2);
	list();
	aradan_sil(1);
	list();
	bastan_sil();
	list();
	sondan_sil();
	list();
}
void list(){
    temp = first;
    while(temp != NULL){
        printf("%d %lf\n", temp -> data1, temp -> data2);
        temp = temp -> next;
    }
	printf("\n");
}
void araya_ekle(int data1, double data2, int a){
	if(first == NULL){ 
		basa_ekle(data1, data2);
	}else{
		temp = first;
		for(int i = 0; i < a - 1; i++){
			temp = temp -> next;
		}
		if(temp -> next == NULL)
			sona_ekle(data1, data2);
		else{
			temp2 = temp -> next;
			temp3 = (cift_yonlu_bliste*)malloc(sizeof(cift_yonlu_bliste));
			temp3 -> data1 = data1;
			temp3 -> data2 = data2;
			temp -> next = temp3;
			temp2 -> previous = temp3;
			temp3 -> previous = temp;
			temp3 -> next = temp2;
		}
	}
}
void basa_ekle(int data1, double data2){
	if(first == NULL){ 
		first = (cift_yonlu_bliste*)malloc(sizeof(cift_yonlu_bliste));
		first -> data1 = data1;
		first -> data2 = data2;
		first -> previous = NULL;
    	first -> next = NULL;
	}else{
		temp = (cift_yonlu_bliste*)malloc(sizeof(cift_yonlu_bliste));
		temp -> data1 = data1;
		temp -> data2 = data2;
		first -> previous = temp;
		temp -> next = first;
		temp -> previous = NULL;
		first = temp;
	}
}
void sona_ekle(int data1, double data2){
	if(first == NULL)
		basa_ekle(data1, data2);
	else{
		temp = first;
		temp2 = (cift_yonlu_bliste*)malloc(sizeof(cift_yonlu_bliste));
		while(temp -> next != NULL)
			temp = temp -> next;
		temp2 -> data1 = data1;
		temp2 -> data2 = data2;
		temp -> next = temp2;
		temp2 -> previous = temp;
		temp2 -> next = NULL;
	}
}
void aradan_sil(int a){
	if(first == NULL)
		printf("Liste bos!");
	else if(a == 0)
		bastan_sil();
	else{
		temp = first;
		for(int i = 0; i < a - 1; i++){
			temp = temp -> next;
		}
		if(temp -> next -> next == NULL)
			sondan_sil();
		else{
			temp2 = temp -> next -> next;
			free(temp -> next);
			temp -> next = temp2;
			temp2 -> previous = temp;
		}
	}
}
void bastan_sil(){
	if(first == NULL){
		printf("Bos liste!");
	}else if(first -> next == NULL){
		first = NULL;
		printf("Listede eleman kalmadi.");
	}else{
		temp = first -> next;
		temp -> previous = NULL;
		free(first);
		first = temp;
	}
}
void sondan_sil(){
	if(first == NULL){
		printf("Bos liste!");
	}else if(first -> next == NULL){
		first = NULL;
		printf("Listede eleman kalmadi");
	}else{
		temp = first;
		while(temp -> next -> next != NULL)
			temp = temp -> next;
		temp -> next = NULL;
		free(temp -> next);
	}
}
