#include <stdio.h>
#include <stdlib.h>

struct dugum {
	int veri;
	struct dugum* adres;
};

typedef struct dugum bliste;
bliste *dugum1 = NULL;
bliste *yenidugum = NULL;
bliste *temp = NULL;
bliste *temp2 = NULL;
void dugumolustur(int);
void diziyazdir();
void bulsil(int);
int eleman;
int a = 0;
int main(){
	while(a == 0){
		printf("1. Diziye eleman ekle.\n2. Diziden eleman sil.\n3. Programi sonlandir.\n-> ");
		int giris;
		scanf("%d", &giris);

		switch(giris){
			case 1:			
				printf("Eklemek istediginiz elemani girin: ");
				scanf("%d", &eleman);
				dugumolustur(eleman);
				printf("%d elemani eklendi.\n", eleman);
				diziyazdir();
				break;
			
			case 2:	
				printf("Silmek istediginiz elamani girin: ");
				scanf("%d", &eleman);
				bulsil(eleman);
				diziyazdir();
				break;

			case 3:
				a = 1;
				printf("Program sona erdi.");
				break;
			
			default:
				printf("Hatali giris!\n");
				diziyazdir();
				break;
		}
	}
	return 0;
}
void dugumolustur(int veri){
	if(dugum1 == NULL){
		dugum1 = (bliste*)malloc(sizeof(bliste));
		dugum1->veri = veri;
		dugum1->adres = NULL;
	}else{
		temp = dugum1;
		while(temp->adres != NULL){
			temp = temp->adres;
		}
		temp->adres = (bliste*)malloc(sizeof(bliste));
		temp->adres->veri = veri;
		temp->adres->adres = NULL;
	}
}
void diziyazdir(){
	printf("Dizi: ");
	temp = dugum1;
	while(temp != NULL){
		printf("%d ", temp->veri);
		temp = temp->adres;
	}
	printf("\n");
}
void bulsil(int aranan) {
	temp = dugum1;
	if(temp == NULL){
		printf("Dizi bos!\n");
		return;
	}
	if(temp->veri == aranan){
		temp = dugum1->adres;
		free(dugum1);
		dugum1 = temp;
		printf("%d elemani silindi.\n", aranan);
		return;
	}
	while (temp->adres != NULL) {
		if (temp->adres->veri == aranan && temp->adres->adres == NULL) {
			free(temp->adres);
			temp->adres = NULL;
			printf("%d elemani silindi.\n", aranan);
			return;
		}else if(temp->adres->veri == aranan){
			temp2 = temp->adres->adres;
			free(temp->adres);
			temp->adres = temp2;
			printf("%d elemani silindi.\n", aranan);
			return;
		}
		temp = temp->adres;
	}
	printf("%d elemani dizide yok!\n", aranan);
}

	/*dugum1 = (bliste*)malloc(sizeof(bliste));
	dugum1->veri = 9;
	dugum1->adres = NULL;
	dugum1->adres = (bliste*)malloc(sizeof(bliste));
	dugum1->adres->veri = 20;
	dugum1->adres->adres = NULL;
	dugum1->adres->adres = (bliste*)malloc(sizeof(bliste));
	dugum1->adres->adres->veri = 55;
	dugum1->adres->adres->adres = NULL;
	dugum1->adres->adres->adres = (bliste*)malloc(sizeof(bliste));
	dugum1->adres->adres->adres->veri = 44;
	dugum1->adres->adres->adres->adres = NULL;*/
