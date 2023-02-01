#include <stdio.h>
#include <stdlib.h>

struct dbliste{
    char urun[20];
    int urunKodu;
    struct dbliste *next;
    struct dbliste *prev;
};
typedef struct dbliste stok;

struct queue{
    int urunKodu;
    struct queue *next;
};
typedef struct queue kuyruk;

struct stack{
    int urunKodu;
    struct stack *next;
};
typedef struct stack yigin;

struct bliste{
    int urunKodu;
    struct bliste *next;
};
typedef struct bliste tesedilen;

stok *urun1 = NULL;
stok *temp = NULL;
stok *temp2 = NULL;
kuyruk *front = NULL;
kuyruk *rear = NULL;
yigin *kamyon = NULL;
tesedilen *user = NULL;

void kategoriyazdir();
void urunyazdir(int);
void stokara(int, int); //stokta ürün olup olmadığına, varsa adet sayısı döndür
void stokyukle(); //stoğu oluştur
void stokyaz(); //stoktaki elemanları yazdır
void stokcik(int, int); //stoktan çıkarıp kuyruğa ekle
void sepet();
void urunk(int); //urun kodu stringe donustur
void kuyrukcik(); //kuyruktan çıkarıp kamyona ekle
void yaz(); //kuyruk ve kamyon içindeki elemanları yazdır (siparişler hangi aşamada)
void yaz2();
void teslimet(); //kamyondan çıkarıp teslim et

int main(){
    stokyukle();
    stokyaz();
    int secim;
    kategoriyazdir();

    return 0;
}

void stokyukle(){
    urun1 = (stok*)malloc(sizeof(stok));
    temp = urun1;
    temp2 = NULL;
    int uk = 0;
    int i = 1;
    for(int j = 1; j < 5; j++){
        uk = i * 10 + j;
        if(uk == 44)
            break;
        for(int h = 0; h < 5; h++){
            if(temp == NULL)
                temp = (stok*)malloc(sizeof(stok));
            temp->urunKodu = uk;
            temp->prev = temp2;
            temp->next = NULL;
            if(temp2 != NULL)
                temp2->next = temp;
            temp2 = temp;
            if(uk != 43 || h != 4)
                temp = temp->next;
        }
        if(j == 4){
            i++;
            j = 0;
        }
    }
    temp->next = urun1;
    urun1->prev = temp;
}

void kategoriyazdir(){
    printf("\nKATEGORILER:\n1- Bilgisayar\n2- TV\n3- Telefon\n4- Kamera\n5- SEPET\n-> ");
    int secim;
    scanf("%d", &secim);
    urunyazdir(secim);
}

void urunyazdir(int secim){
    int secim2;
    switch(secim)
    {
   	    case 1:
            printf("\nBILGISAYARLAR:\n1- HP\n2- Lenovo\n3- Asus\n4- MSI\n5- GERI\n-> ");
            scanf("%d", &secim2);
            if(secim2 == 5){
                kategoriyazdir();
                break;
            }else if(secim2 > 5 || secim2 < 1){
                printf("HATALI GIRIS!!!\n");
                urunyazdir(secim);
            }
            stokara(1, secim2);
   	        break;
   	    case 2:
            printf("\nTVLER:\n1- LG\n2- Philips\n3- Samsung\n4- Vestel\n5- GERI\n-> ");
            scanf("%d", &secim2);
            if(secim2 == 5){
                kategoriyazdir();
                break;
            }else if(secim2 > 5 || secim2 < 1){
                printf("HATALI GIRIS!!!\n");
                urunyazdir(secim);
            }
            stokara(2, secim2);
   	        break;
   	    case 3:
            printf("\nTELEFONLAR:\n1- Xiaomi\n2- Oppo\n3- Apple\n4- Huawei\n5- GERI\n-> ");
            scanf("%d", &secim2);
            if(secim2 == 5){
                kategoriyazdir();
                break;
            }else if(secim2 > 5 || secim2 < 1){
                printf("HATALI GIRIS!!!\n");
                urunyazdir(secim);
            }
            stokara(3, secim2);
   	        break;
   	    case 4:
            printf("\nKAMERALAR:\n1- Sony\n2- Canon\n3- Nikon\n4- GERI\n-> ");
            scanf("%d", &secim2);
            if(secim2 == 4){
                kategoriyazdir();
                break;
            }else if(secim2 > 4 || secim2 < 1){
                printf("HATALI GIRIS!!!\n");
                urunyazdir(secim);
            }
            stokara(4, secim2);
            break;
        case 5:
            sepet();
            break;
        default:
            printf("HATALI GIRIS!!!\n");
            kategoriyazdir();
            break;
   }
}

void stokara(int katego, int sec){
    int urunKodu = katego * 10 + sec;
    int ff = 0;
    int stoktaAdet = 0;
    int adet = 0;
    temp = urun1;
    while(ff == 0 || temp->urunKodu != urun1->urunKodu){
        if(temp->urunKodu == urunKodu)
            stoktaAdet++;
        temp = temp->next;
        if(urun1->urunKodu != temp-> urunKodu)
            ff = 1;
    }
    printf("\nStokta adet sayisi: %d\nSepete eklemek istediginiz adet:\n-> ", stoktaAdet);
    scanf("%d", &adet);
    if(adet == 0)
        kategoriyazdir();
    else if(adet < 0 || adet > stoktaAdet){
        printf("HATALI GIRIS!!!\n");
        stokara(katego, sec);
    }else{
        stokcik(urunKodu, adet);
    }
}

void stokcik(int urunKodu, int adet){
    temp = urun1;
    int b = 0;
    while(temp->urunKodu != urunKodu){
        temp = temp->next;
    }
    if(temp == urun1)
        b = 1;
    temp2 = temp->prev;
    stok *temp3 = temp;
    for(int i = 0; i < adet; i++){
        temp3 = temp3->next;
        free(temp);
        temp = temp3;
    }
    temp2->next = temp3;
    temp3->prev = temp2;
    if(b == 1)
        urun1 = temp3;

    kuyruk *ktemp = NULL;
    kuyruk *ktemp2 = NULL;
    if(front == NULL){
        front = (kuyruk*)malloc(sizeof(kuyruk));
        rear = (kuyruk*)malloc(sizeof(kuyruk));
        ktemp = front;
    }else{
        ktemp = rear->next;
        ktemp2 = rear;
    }
    for(int j = 0; j < adet; j++){
        if(ktemp == NULL)
            ktemp = (kuyruk*)malloc(sizeof(kuyruk));
        ktemp->urunKodu = urunKodu;
        ktemp->next = NULL;
        if(ktemp2 != NULL)
            ktemp2->next = ktemp;
        ktemp2 = ktemp;
        ktemp = ktemp->next;
    }
    rear = ktemp2;
    kategoriyazdir();
}

void sepet(){
    if(front != NULL){
        kuyruk *ktemp = NULL;
        ktemp = front;
        printf("\nSepet: ");
        while(ktemp != NULL){
            urunk(ktemp->urunKodu);
            ktemp = ktemp->next;
        }
        printf("\n1- Onayla\n2- GERI\n-> ");
        int secim3;
        scanf("%d", &secim3);
        switch(secim3){
            case 1:
                kuyrukcik();
                break;
            case 2:
                kategoriyazdir();
                break;
            default:
                printf("HATALI GIRIS!!!\n");
                sepet();
                break;
        }
    }else{
        printf("SEPET BOS!!!\n");
        kategoriyazdir();
    }
}

void urunk(int urunKodu){
    switch(urunKodu){
    case 11:
        printf("HP ");
        break;
    case 12:
        printf("Lenovo ");
        break;
    case 13:
        printf("Asus ");
        break;
    case 14:
        printf("MSI ");
        break;
    case 21:
        printf("LG ");
        break;
    case 22:
        printf("Philips ");
        break;
    case 23:
        printf("Samsung ");
        break;
    case 24:
        printf("Vestel ");
        break;
    case 31:
        printf("Xiaomi ");
        break;
    case 32:
        printf("Oppo ");
        break;
    case 33:
        printf("Apple ");
        break;
    case 34:
        printf("Huawei ");
        break;
    case 41:
        printf("Sony ");
        break;
    case 42:
        printf("Canon ");
        break;
    case 43:
        printf("Nikon ");
        break;    
    default:
        break;
    }
}

void kuyrukcik(){
    yaz();
    kamyon = (yigin*)malloc(sizeof(yigin));
    kamyon->next = NULL;
    yigin *ytemp = kamyon;
    yigin *ytemp2 = ytemp;
    kuyruk *ktemp = NULL;
    while(front != NULL){
        ytemp = ytemp2;
        if(front->next != NULL)
            ytemp2 = (yigin*)malloc(sizeof(yigin));
        ytemp->urunKodu = front->urunKodu;
        ktemp = front;
        front = front->next;
        free(ktemp);
        if(front != NULL)
            ytemp2->next = ytemp;
        kamyon = ytemp2;
        yaz();
    }
    rear = NULL;
    teslimet();
}

void yaz(){
    kuyruk *ktemp = NULL;
    ktemp = front;
    printf("\n\nKuyruk: ");
    while(ktemp != NULL){
        urunk(ktemp->urunKodu);
        ktemp = ktemp->next;
    }
    yigin *ytemp = kamyon;
    printf("\nKamyon: ");
    while(ytemp != NULL){
        urunk(ytemp->urunKodu);
        ytemp = ytemp->next;
    }
}

void teslimet(){
    yigin *ytemp = kamyon;
    tesedilen *btemp = user;
    tesedilen *btemp2 = btemp;
    if(user == NULL){
        user = (tesedilen*)malloc(sizeof(tesedilen));
        btemp = user;
        btemp2 = btemp;
    }else{
        while(btemp2->next != NULL){
            btemp2 = btemp2->next;
        }
        btemp = btemp2->next;
    }
    while(kamyon != NULL){
        if(btemp == NULL){
            btemp = (tesedilen*)malloc(sizeof(tesedilen));
            btemp2->next = btemp;
        }
        btemp->next = NULL;
        ytemp = kamyon->next;
        btemp->urunKodu = kamyon->urunKodu;
        free(kamyon);
        kamyon = ytemp;
        btemp2 = btemp;
        btemp = btemp->next;
        yaz2();
    }
    printf("\n");
    kategoriyazdir();
}

void yaz2(){
    yigin *ytemp = kamyon;
    printf("\n\nKamyon: ");
    while(ytemp != NULL){
        urunk(ytemp->urunKodu);
        ytemp = ytemp->next;
    }
    tesedilen *btemp = user;
    printf("\nTeslim edilen: ");
    while(btemp != NULL){
        urunk(btemp->urunKodu);
        btemp = btemp->next;
    }
}

void stokyaz(){
    temp = urun1;
    int ff = temp->urunKodu;
    int fd = 0;
    while(fd == 0 || temp->urunKodu != ff){
        printf("%d ", temp->urunKodu);
        temp = temp->next;
        if(ff != temp-> urunKodu)
            fd = 1;
    }
}