
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
struct ogrenci{
    char no[8];
    char ad[20];
    char soyad[20];
    int sira;
    char ogr_turu[2];
}temp,temp1,kayit;



void ekle(){
char devam;
struct ogrenci ogr[2000];
int sayac=0;
    char karar;
    int i;
    FILE *dosya;
    dosya=fopen("ornek_ogrenci_kayit_bilgileri.txt","r+");
    while(!feof(dosya)){
        fscanf(dosya,"%s %s %s %d %s\n", (ogr[sayac].no), ogr[sayac].ad, ogr[sayac].soyad, &(ogr[sayac].sira), (ogr[sayac].ogr_turu));
        sayac++;
    }
    fclose(dosya);
    FILE *ekleme;
    ekleme=fopen("ornek_ogrenci_kayit_bilgileri.txt","a+");
    printf("\nOgrenci ekleme yapacak misiniz(E/H)");
    scanf ("%c",&karar);
    karar=getchar();

    if(karar=='e'|| karar=='E'){
    do{

      strcpy(kayit.no,"-");
      printf("\nOgrencinin adini giriniz:");
      fflush(stdin);
      gets(kayit.ad);
      printf ("Ogrencinin soyadini giriniz:");
      fflush(stdin);
      gets(kayit.soyad);
      printf("Ogrencinin ogretim turunu giriniz:");
      fflush(stdin);
      gets(kayit.ogr_turu);
      kayit.sira=sayac+1;

      for(i=0;i<sayac;i++){
        if(strcmp(ogr[i].ad,kayit.ad)==0 && strcmp(ogr[i].soyad,kayit.soyad)==0)
        {
            printf("Ogrenci listede var.\n");
            break;
        }
        else{
            fprintf(ekleme,"%s %s %s %d %s\n",(kayit.no), kayit.ad, kayit.soyad, (kayit.sira), (kayit.ogr_turu));
            break;
        }
      }
      fclose(ekleme);
      printf ("\nkayıt icin devam etmek istiyor musunuz?");
      scanf ("%c",&devam);
      devam=getchar();
    }

    while(devam=='e'|| devam=='E');
    }
}



 void listele()
{
    int sayac=0,i,j;
    struct ogrenci ogr[2000];
    struct ogrenci ogry[2000];
    FILE *dosya;
    FILE *dosya2;
    dosya=fopen("ornek_ogrenci_kayit_bilgileri.txt", "r+");
    dosya2=fopen("yeni3.txt", "w");
    if(dosya==NULL)
        return ;
    while(!feof(dosya)){
        fscanf(dosya,"%s %s %s %d %s\n", (ogr[sayac].no), ogr[sayac].ad, ogr[sayac].soyad, &(ogr[sayac].sira), (ogr[sayac].ogr_turu));
        sayac++;
    }
    for(i=0;i<sayac;i++){
        printf("%s %s %s %d %s\n", (ogr[i].no), ogr[i].ad, ogr[i].soyad, (ogr[i].sira), (ogr[i].ogr_turu));
    }
    printf("toplam:%d\n",sayac);
    printf("--------------\n");
    printf("Tekrar Edenler:\n");
    printf("--------------\n");
    int b=0;
    for(i=0;i<sayac;i++){
        for(j=i+1;j<sayac+1;j++){
          if(strcmp(ogr[i].ad,ogr[j].ad)==0 && strcmp(ogr[i].soyad,ogr[j].soyad)==0){
             b++;
             printf("%s %s\n",ogr[i].ad,ogr[i].soyad);
             break;
          }
          else{
             fprintf(dosya2,"%s %s %s %d %s\n",(ogr[i].no), ogr[i].ad, ogr[i].soyad, (ogr[i].sira), (ogr[i].ogr_turu));
             i++;
          }

        }
    }
    fclose(dosya);
    fclose(dosya2);
    printf("--------------\n");
    printf("tekrar edenlerin sayisi:%d\n",b);
    printf("--------------\n");
    int sayac2=0;
    FILE *dosya21;
    dosya21=fopen("yeni3.txt","r+");
    if(dosya21==NULL)
        return ;
    while(!feof(dosya21)){
        fscanf(dosya21,"%s %s %s %d %s\n", (ogry[sayac2].no), ogry[sayac2].ad, ogry[sayac2].soyad, &(ogry[sayac2].sira), (ogry[sayac2].ogr_turu));
        sayac2++;
    }
    printf("\ntekrarlilar cikinca %d ogrenci kaldi\n",sayac2);
    struct ogrenci birog[2000];
    struct ogrenci ikiog[2000];
    int birn=0;
    for(i=0;i<sayac2;i++){
       int sonuc=strcmp(ogry[i].ogr_turu,"I");
       if(sonuc==0){
           strcpy(birog[i].no,ogry[i].no);
           strcpy(birog[i].ad,ogry[i].ad);
           strcpy(birog[i].soyad,ogry[i].soyad);
           birog[i].sira=ogry[i].sira;
           strcpy(birog[i].ogr_turu,ogry[i].ogr_turu);
           birn++;
        }
    }
    printf("\nbirinci ogretim:%d\n",birn);
    int ikin=0;
    for(i=0;i<sayac2;i++){
        int sonuc1=strcmp(ogry[i].ogr_turu,"II");
        if(sonuc1==0){
            strcpy(ikiog[i].no,ogry[i].no);
            strcpy(ikiog[i].ad,ogry[i].ad);
            strcpy(ikiog[i].soyad,ogry[i].soyad);
            ikiog[i].sira=ogry[i].sira;
            strcpy(ikiog[i].ogr_turu,ogry[i].ogr_turu);
             ikin++;
        }
    }
   printf("\nikinci ogretim sayisi:%d\n",ikin);
   FILE *dosya3;
     dosya3=fopen("yeni4.txt","w");
     for(i=0;i<sayac2;i++){
            int sonuc2=strcmp(ogry[i].ogr_turu,"I");
        if(sonuc2==0){
        fprintf(dosya3,"%s %s %s %d %s\n",(birog[i].no), birog[i].ad, birog[i].soyad, (birog[i].sira), (birog[i].ogr_turu));
     }
     }
     int s2=0;
     FILE *dosya4;
     dosya4=fopen("yeni5.txt","w");
     for(i=0;i<sayac2;i++){
            int sonuc2=strcmp(ogry[i].ogr_turu,"II");
        if(sonuc2==0){
        fprintf(dosya4,"%s %s %s %d %s\n",(ikiog[i].no), ikiog[i].ad, ikiog[i].soyad, (ikiog[i].sira), (ikiog[i].ogr_turu));

     }
     }

     fclose(dosya3);
     fclose(dosya4);
     FILE *biro;
     biro=fopen("yeni4.txt","r+");
     struct ogrenci bogr[200];
     if(biro==NULL)
        return ;
    for(i=0;i<birn;i++)
    {
        fscanf(biro,"%s %s %s %d %s\n", (bogr[i].no), bogr[i].ad, bogr[i].soyad, &(bogr[i].sira), (bogr[i].ogr_turu));
        if(feof(biro))
            break;
    }

    for(j=0;j<birn;j++){
             char numarasi[8];
            if(bogr[j].sira>0 && bogr[j].sira<10){
               bogr[j].sira=1701000+bogr[j].sira;
        sprintf(numarasi,"%d",bogr[j].sira);
        sprintf(bogr[j].no,"%s",numarasi);
        bogr[j].sira=bogr[j].sira-1701000;
        }
           if(bogr[j].sira>=10 && bogr[j].sira<100){
            bogr[j].sira=1701000+bogr[j].sira;
            sprintf(numarasi,"%d",bogr[j].sira);
            sprintf(bogr[j].no,"%s",numarasi);
            bogr[j].sira=bogr[j].sira-1701000;
           }
           if(bogr[j].sira>=100){
            bogr[j].sira=1701000+bogr[j].sira;
            sprintf(numarasi,"%d",bogr[j].sira);
            sprintf(bogr[j].no,"%s",numarasi);
            bogr[j].sira=bogr[j].sira-1701000;
           }
    }
     for (i = 1; i <birn; i++)
      for (j = 0; j <birn - i; j++) {
         if (strcmp(bogr[j].no, bogr[j + 1].no) > 0) {
            temp1 = bogr[j];
            bogr[j] = bogr[j + 1];
            bogr[j + 1] = temp1;
         }
      }

     FILE *abir;
     abir=fopen("numbir.txt","w+");
     for(i=0;i<birn;i++){
        fprintf(abir,"%s %s %s %d %s\n",(bogr[i].no), bogr[i].ad, bogr[i].soyad, (bogr[i].sira), (bogr[i].ogr_turu));
     }

     FILE *ikio;
     ikio=fopen("yeni5.txt","r+");
     struct ogrenci iogr[2000];
     if(ikio==NULL)
        return  ;
    for(i=0;i<ikin;i++)
    {
        fscanf(ikio,"%s %s %s %d %s\n", (iogr[i].no), iogr[i].ad, iogr[i].soyad, &(iogr[i].sira), (iogr[i].ogr_turu));
        if(feof(ikio))
            break;
    }
    int k=ikin-s2;
    for(j=0;j<ikin;j++){
             char numarasi[8];
            if(iogr[j].sira>0 && iogr[j].sira<10){
               iogr[j].sira=1702000+iogr[j].sira-k;
        sprintf(numarasi,"%d",iogr[j].sira);
        sprintf(iogr[j].no,"%s",numarasi);
        iogr[j].sira=iogr[j].sira-1702000+ikin+k;
        }
           if(iogr[j].sira>=10 && iogr[j].sira<100){
            iogr[j].sira=1702000+iogr[j].sira-k;
            sprintf(numarasi,"%d",iogr[j].sira);
            sprintf(iogr[j].no,"%s",numarasi);
            iogr[j].sira=iogr[j].sira-1702000+k;
           }
           if(iogr[j].sira>=100)
            {
            iogr[j].sira=1702000+iogr[j].sira-k;
            sprintf(numarasi,"%d",iogr[j].sira);
            sprintf(iogr[j].no,"%s",numarasi);
            iogr[j].sira=iogr[j].sira-1702000+k;
           }
    }
     for (i = 1; i < ikin; i++)
      for (j = 0; j < ikin - i; j++) {
         if (strcmp(iogr[j].no, iogr[j + 1].no) > 0) {
            temp = iogr[j];
            iogr[j] = iogr[j + 1];
            iogr[j + 1] = temp;
         }
      }
     FILE *aiki;
     aiki=fopen("numiki.txt","w+");
     for(i=0;i<ikin;i++){
        fprintf(aiki,"%s %s %s %d %s\n",(iogr[i].no), iogr[i].ad, iogr[i].soyad, (iogr[i].sira), (iogr[i].ogr_turu));
     }



     // siniflandirma
     int sinif;
     int toplam=0;
     printf("\nsinif sayisini giriniz:");
     scanf("%d",&sinif);
     int dizi[sinif];
     printf("\nsinif kapasitelerini giriniz:");
     for(i=0;i<sinif;i++){
        scanf("%d",&dizi[i]);
     }
     for(i=0;i<sinif;i++){
           toplam+=dizi[i];
     }
     if(toplam<birn){
            do{
        printf("\nsinif sayisini giriniz:");
     scanf("%d",&sinif);
     printf("\nsinif kapasitelerini giriniz:");

     for(i=0;i<sinif;i++){
        scanf("%d",&dizi[i]);
     }
     for(i=0;i<sinif;i++){
           toplam+=dizi[i];
     }
            }
            while(toplam<birn);
     }

        /// SINIF ATAMA KISMI BURDAN BASLIYOR TOPLAM=KAPASİTELERIN TOPLAMI YANİ AZ SA TEKRAR SORCAK GİR DİYE YUKARIDA DA NO ATAMA VAR

        FILE *file;
        FILE *file1;
        FILE *file2;
        FILE *file3;
     	int birinci_ogretim_durum[birn];
        int ikinci_ogretim_durum[ikin];
        int birinci_ogretim_durum_1[birn];
        int ikinci_ogretim_durum_1[ikin];
        for (i=0;i<birn;i++){
             birinci_ogretim_durum[i]=0;
        }
        for (i=0;i<ikin;i++){
            ikinci_ogretim_durum[i]=0;
        }
        for (i=0;i<birn;i++){
             birinci_ogretim_durum_1[i]=0;
        }
        for (i=0;i<ikin;i++){
            ikinci_ogretim_durum_1[i]=0;
        }
        int sinif_no = 0;
        int ind=0;


    /// ---> Birinci Öğretim

             while (1)
            {




    char isim[100] = "Esit Dagitimli - Birinci Ogretim Sinif ";
    char char_sinif[5];
    sprintf(char_sinif,"%d",sinif_no+1);
    strcat(isim,char_sinif);
    strcat(isim,".txt");

    file = fopen(isim, "a");



        int kontrol_et=0;
    for (j=0;j<sinif;j++){
        if (birinci_ogretim_durum[j]!=dizi[j]){
            kontrol_et=1;
        }
    }


    if(kontrol_et==0){
        break;
    }

a:
    if(sinif_no>=sinif){
        sinif_no=0;
    }

    if (birinci_ogretim_durum[sinif_no]>=dizi[sinif_no]){
        sinif_no++;
        goto a;
    }


    ///Eşit Dağıtıyoruz

    fprintf(file,"%-10s \t  %-10s  \t  %-10s  \t  %-10d  \t  %-10s \n",bogr[ind].no,bogr[ind].ad,bogr[ind].soyad,bogr[ind].sira,bogr[ind].ogr_turu);
    birinci_ogretim_durum[sinif_no]+=1;
    ind++;
    sinif_no++;

    if (ind>=birn){
     break;
    }


    if(sinif_no>=sinif){
        sinif_no=0;
    }




        }

        /// -> İkinci Öğretim

    sinif_no=0;
    ind=0;

           while (1)
            {

    char isim[100] = "Esit Dagitimli - Ikinci Ogretim Sinif ";
    char char_sinif[5];
    sprintf(char_sinif,"%d",sinif_no+1);
    strcat(isim,char_sinif);
    strcat(isim,".txt");

    file1 = fopen(isim, "a");


    int kontrol_et=0;

    for (j=0;j<sinif;j++){
        if (ikinci_ogretim_durum[j]!=dizi[j]){
            kontrol_et=1;
        }
    }

    if(kontrol_et==0){
        break;
    }

b:
    if(sinif_no>=sinif){
        sinif_no=0;
    }
    if (ikinci_ogretim_durum[sinif_no]>=dizi[sinif_no]){
        sinif_no++;
        goto b;
    }



    ///Eşit Dağıtıyoruz

    fprintf(file1,"%-10s \t  %-10s  \t  %-10s  \t  %-10d  \t  %-10s \n",iogr[ind].no,iogr[ind].ad,iogr[ind].soyad,iogr[ind].sira,iogr[ind].ogr_turu);
    ikinci_ogretim_durum[sinif_no]+=1;
    ind++;
    sinif_no++;
    if (ind>=ikin){
     break;
    }


    if(sinif_no>=sinif){
        sinif_no=0;
    }

        }

        /// -> En Az Sinif Odakli Dagilim



        /// Sirali Sinif Kapasite Listesi Olusturuyoruz
        int sirali_dizi[sinif];

           for (i=0;i<sinif;i++){
                sirali_dizi[i] = dizi[i];
           }


          for (i=0;i<sinif;i++){

        for (j=0;j<sinif;j++){

           if (sirali_dizi[i]>sirali_dizi[j]){
                int gecici=sirali_dizi[j];
                sirali_dizi[j]=sirali_dizi[i];
                sirali_dizi[i]=gecici;
                }

            }


      }

      /// Birinci Öğretim

    ind = 0;
    sinif_no=0;

            while (1)
            {




    char isim[100] = "Az Sinif Odakli - Birinci Ogretim Sinif ";
    char char_sinif[5];
    sprintf(char_sinif,"%d",sinif_no+1);
    strcat(isim,char_sinif);
    strcat(isim,".txt");

    file2 = fopen(isim, "a");

        if (ind>=birn){
         break;
        }


     if(sinif_no>=sinif){
            break;
        }


    fprintf(file2,"%-10s \t  %-10s  \t  %-10s  \t  %-10d  \t  %-10s \n",bogr[ind].no,bogr[ind].ad,bogr[ind].soyad,bogr[ind].sira,bogr[ind].ogr_turu);
    birinci_ogretim_durum_1[sinif_no]+=1;
    ind++;


    if (birinci_ogretim_durum_1[sinif_no]>=sirali_dizi[sinif_no]){
        sinif_no++;
    }



    fclose(file2);

}


        /// İkinci Öğretim


ind = 0;
sinif_no=0;

            while (1)
            {

    char isim[100] = "Az Sinif Odakli - Ikinci Ogretim Sinif ";
    char char_sinif[5];
    sprintf(char_sinif,"%d",sinif_no+1);
    strcat(isim,char_sinif);
    strcat(isim,".txt");

    file3 = fopen(isim, "a");

        if (ind>=ikin){
         break;
        }


     if(sinif_no>=sinif){
            break;
        }


    fprintf(file3,"%-10s \t  %-10s  \t  %-10s  \t  %-10d  \t  %-10s \n",iogr[ind].no,iogr[ind].ad,iogr[ind].soyad,iogr[ind].sira,iogr[ind].ogr_turu);

    ikinci_ogretim_durum_1[sinif_no]+=1;

    ind++;


    if (ikinci_ogretim_durum_1[sinif_no]>=sirali_dizi[sinif_no]){
        sinif_no++;
    }

    fclose(file3);

}
     fclose(file);
     fclose(file1);
     fclose(file2);
     fclose(file3);
     fclose(abir);
     fclose(aiki);
     fclose(dosya21);
     fclose(dosya3);
     fclose(dosya4);
}

int main(){
clock_t begin = clock();
int secim,flag=0;
printf("\n---secimler----\n");
printf("1-Listele\n");
printf("2-Ekle\n");
printf("3-Cikis\n");
while(flag==0){
        printf("seciminiz:");
scanf("%d",&secim);
    switch(secim){
case 1:
    listele();
    break;
case 2:
    ekle();
    break;
case 3:
    flag=1;
    break;
default:
    printf("yanlis secim");
    }
}
clock_t end = clock();
double sure = (double)(end - begin) / CLOCKS_PER_SEC;
printf("\n \nGecen Sure: %.2f saniye\n",sure);
return 0;
}
