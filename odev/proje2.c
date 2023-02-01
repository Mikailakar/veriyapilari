#include <stdio.h>
#include <stdlib.h>

struct dbliste{
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
typedef struct bliste blist;

stok *urun1 = NULL;
stok *temp = NULL;
stok *temp2 = NULL;
kuyruk *front = NULL;
kuyruk *rear = NULL;
yigin *kamyon = NULL;
blist *user = NULL;
blist *kategoriler[4];
blist *btemp = NULL;

void kategoriolustur();
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
    kategoriolustur();
    stokyukle();
    //stokyaz();
    kategoriyazdir();

    return 0;
}

void kategoriolustur(){
    btemp = NULL;
    blist *btemp2 = NULL;
    for(int i = 0; i < 4; i++){
        kategoriler[i] = (blist*)malloc(sizeof(blist));
        btemp = kategoriler[i];
        btemp->urunKodu = i * 10 + 11;
        for(int j = 2; j < 5; j++){
            btemp2 = (blist*)malloc(sizeof(blist));
            btemp2->urunKodu = i * 10 + j + 10;
            btemp->next = btemp2;
            btemp = btemp2;
            if(i == 3 && j == 3)
                break;
        }
        btemp->next = NULL;
    }
    /*for(int h = 0; h < 4; h++){
        btemp = kategoriler[h];
        while(btemp != NULL){
            printf("%d ", btemp->urunKodu);
            btemp = btemp->next;
        }
    }*/
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
            printf("\nBILGISAYARLAR:\n");
            btemp = kategoriler[0];
            for(int i = 0; i < 4; i++){
                printf("%d- ", (i+1));
                urunk(btemp->urunKodu);
                printf("\n");
                btemp = btemp->next;
            }
            printf("5- GERI\n-> ");
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
            printf("\nTVLER:\n");
            btemp = kategoriler[1];
            for(int i = 0; i < 4; i++){
                printf("%d- ", (i+1));
                urunk(btemp->urunKodu);
                printf("\n");
                btemp = btemp->next;
            }
            printf("5- GERI\n-> ");
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
            printf("\nTELEFONLAR:\n");
            btemp = kategoriler[2];
            for(int i = 0; i < 4; i++){
                printf("%d- ", (i+1));
                urunk(btemp->urunKodu);
                printf("\n");
                btemp = btemp->next;
            }
            printf("5- GERI\n-> ");
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
            printf("\nKAMERALAR:\n");
            btemp = kategoriler[3];
            for(int i = 0; i < 3; i++){
                printf("%d- ", (i+1));
                urunk(btemp->urunKodu);
                printf("\n");
                btemp = btemp->next;
            }
            printf("4- GERI\n-> ");
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
        if(urun1 == temp)
            break;
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
    if(temp3 != NULL){
        temp2->next = temp3;
        temp3->prev = temp2;
        if(b == 1)
            urun1 = temp3;
    }else
        urun1 = NULL;

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
    printf("\nKuyruktan kamyona yukleniyor");
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
    printf("\n\nKamyondan teslim ediliyor");
    yigin *ytemp = kamyon;
    blist *btemp = user;
    blist *btemp2 = btemp;
    if(user == NULL){
        user = (blist*)malloc(sizeof(blist));
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
            btemp = (blist*)malloc(sizeof(blist));
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
    blist *btemp = user;
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
