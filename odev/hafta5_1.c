#include <stdio.h>
#include <stdlib.h>
struct dugum{
	int veri;
	struct dugum *sonraki;
};
typedef struct dugum yigin;
yigin *direk1 = NULL;
yigin *direk2 = NULL;
yigin *direk3 = NULL;
void ekle1(int);
void ekle2(int);
void ekle3(int);
int cikar1();
int cikar2();
int cikar3();
void listele();
int degistir(int, int);
int main(){
    ekle1(4);
    ekle1(3);
    ekle1(2);
    ekle1(1);
    listele();
	degistir(1, 2);
	degistir(1, 3);
	degistir(2, 3);
	degistir(1, 2);
	degistir(3, 1);
	degistir(3, 2);
	degistir(1, 2);
	degistir(1, 3);
	degistir(2, 3);
	degistir(2, 1);
	degistir(3, 1);
	degistir(2, 3);
	degistir(1, 2);
	degistir(1, 3);
	degistir(2, 3);
	return 0;
}
void ekle1(int eleman){
	if(direk1 == NULL || eleman < direk1 -> veri){
		yigin *yeni;
		yeni = (yigin*)malloc(sizeof(yigin));
		yeni -> veri = eleman;
		if(direk1 == NULL)
			yeni -> sonraki = NULL;
		else
			yeni -> sonraki = direk1;
		direk1 = yeni;
	}else
		printf("HATA!!!\n");
}
void ekle2(int eleman){
	if(direk2 == NULL || eleman < direk2 -> veri){
		yigin *yeni;
		yeni = (yigin*)malloc(sizeof(yigin));
		yeni -> veri = eleman;
		if(direk2 == NULL)
			yeni -> sonraki = NULL;
		else
			yeni -> sonraki = direk2;
		direk2 = yeni;
	}else
		printf("HATA!!!\n");
}
void ekle3(int eleman){
	if(direk3 == NULL || eleman < direk3 -> veri){
		yigin *yeni;
		yeni = (yigin*)malloc(sizeof(yigin));
		yeni -> veri = eleman;
		if(direk3 == NULL)
			yeni -> sonraki = NULL;
		else
			yeni -> sonraki = direk3;
		direk3 = yeni;
	}else
		printf("HATA!!!\n");
}
void listele(){
	yigin *temp = direk1;
    printf("Direk 1: --> ");
	while(temp != NULL){
		printf("%d ", temp -> veri);
		temp = temp -> sonraki;
	}
	printf("\n");
	temp = direk2;
    printf("Direk 2: --> ");
	while(temp != NULL){
		printf("%d ", temp -> veri);
		temp = temp -> sonraki;
	}
	printf("\n");
	temp = direk3;
    printf("Direk 3: --> ");
	while(temp != NULL){
		printf("%d ", temp -> veri);
		temp = temp -> sonraki;
	}
	printf("\n\n");
}
int cikar1(){
    yigin *temp = direk1;
	int d = temp -> veri;
    direk1 = temp -> sonraki;
    free(temp);
	return d;
}
int cikar2(){
    yigin *temp = direk2;
	int d = temp -> veri;
    direk2 = temp -> sonraki;
    free(temp);
	return d;
}
int cikar3(){
    yigin *temp = direk3;
	int d = temp -> veri;
    direk3 = temp -> sonraki;
    free(temp);
	return d;
}
int degistir(int a, int b){
	int c;
	switch (a){
	case 1:
		c = cikar1();
		break;		
	case 2:
		c = cikar2();
		break;
	case 3:
		c = cikar3();
		break;
	}
	switch (b){
	case 1:
		ekle1(c);
		break;		
	case 2:
		ekle2(c);
		break;
	case 3:
		ekle3(c);
		break;
	}
	listele();
}
