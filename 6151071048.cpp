#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

struct drink_st;
void hienThiMENU(struct drink_st*, int);
void hienthibang();

struct drink_st{
	char ten [30], theloai[30];
	int  giatien;
}bs;

void nhapN(drink_st ds[], int n){
	for(int i=0; i<n; i++){
	    printf("	Nhap thong tin do uong thu %d:", i+1);
	    printf("\n	Nhap ten do uong: "); 
		fflush(stdin); 
		gets(ds[i].ten);
        printf("	Nhap the loai do uong: "); 
		fflush(stdin); 
		gets(ds[i].theloai);
        printf("	Nhap gia tien cua do uong : "); 
		scanf("%d", &ds[i].giatien);

    }
}// nhap thong tin do uong
void xuatN(drink_st ds[], int n){
	for(int i=0; i<n; i++){
		printf("	Thong tin do uong thu %d: \n", i+1);
		printf("	Ten do uong: %s\n", ds[i].ten);
		printf("	The loai do uong : %s\n", ds[i].theloai);
		printf("	Gia cua do uong la: %d\n", ds[i].giatien);
	}
}// xuat thong tin do uong

void thongtindouong(struct drink_st bs){
	printf("	||%-20s ||%-20s ||%-20d \n", bs.ten,bs.theloai,bs.giatien);
}//hien thi thong tin do uong

void sapxep(struct drink_st *ds, int n) {
	int i, j;
	for(i = 0; i < n - 1; i++) {
		for(j = n - 1; j > i; j --) {
			if(strcmp(ds[j].theloai , ds[j - 1].theloai) > 0)  {
				struct drink_st a = ds[j];
				ds[j] = ds[j - 1];
				ds[j - 1] = a;
			}
		}
	}
}
//sap xep danh sach theo the loai
void timtheotheloai(struct drink_st *ds, int n) {
	char Ten[30];
	printf("	Nhap the loai : ");
	fflush(stdin);
	gets(Ten);
	hienthibang();
	int i, timS = 0;
	for(i = 0; i < n; i++) {
		if(strcmp(Ten, ds[i].theloai) == 0) {
			thongtindouong(ds[i]);
			timS = 1;
		}
	}
	if(timS == 0) {
		printf("\n	Khong co the loai %s trong danh sach do uong !", Ten);
	}
}
//tim do uong theo the loai

void hienthibang() {
	printf("-----------------------------------------------------"
	"-----------------------------\n");
	printf("	||%-20s ||%-20s ||%-30s \n", "Ten", "The loai", "Gia tien" );
}
//hien thi danh sach theo cot

void hienThiMENU(struct drink_st *ds, int n) {
	hienthibang();
	int i;
	for(i = 0; i < n; i++) {
		thongtindouong(ds[i]);
	}
	printf("-----------------------------------------------------"
	"-----------------------------\n");
}
void ghiFile(struct drink_st* ds, int n) {
	getchar();
	char fName[26];
	printf("	Nhap ten file: ");
	gets(fName);
	FILE* fOut = fopen(fName, "a");
	int i;
	fprintf(fOut,"	------------------------------------------------------------\n");
	fprintf(fOut,"	||TEN DO UONG   ||THE LOAI             ||GIA TIEN            ||\n");
	fprintf(fOut,"	------------------------------------------------------------\n");
	for(i = 0; i < n; i++) {
		struct drink_st bs = ds[i];
		fprintf(fOut, "	||%-10s ||%-20s ||%-20d||\n",bs.ten,bs.theloai,bs.giatien	);
	}
	fprintf(fOut,"	------------------------------------------------------------\n");
	fclose(fOut);
}

void docFile(struct drink_st* ds, int* n) {
	FILE* fOut = fopen("drink.txt", "r");
	int i = 0;
	if(fOut) {
		for(;;) {
			struct drink_st bs;
			fscanf(fOut,"%10s%20s%20d\n",bs.ten,bs.theloai,&bs.giatien);
			ds[i++] = bs;
			if(feof(fOut)) { 
				break;
			}
		}
	}
	fclose(fOut);
	*n = i;
}

int main(){
	system("Color 1E");
	int key,n;
	struct drink_st ds[10];
	bool daNhap = false;
	do{
		printf("\n	Nhap so luong do uong: ");
		scanf("%d",&n);
	}while(n<=0);
	while(true){
		printf("                                                                     \n");
		printf("          --------------------------------------------------          \n");
		printf("        *                                                  *         \n");
		printf("       *                                                    *         \n");
		printf("      *                     QUAN LY QUAN COFFE               *        \n");
		printf("      *         1. Nhap thong tin do uong.                    *         \n");
		printf("      *        2. Sap xep do uong theo the loai(Z->A).        *         \n");
		printf("      *        3. Tim do uong theo the loai.                 *        \n");
		printf("       *        4. Ghi vao file text.                       *         \n");
		printf("         *        5. Thoat chuong trinh.                   *         \n");
		printf("           *                                              *         \n");
		printf("             *                                          *         \n");
		printf("               *--------------------------------------*         \n");
		printf(" ----------------------------------------------------------------------------\n");
		printf("	Ban chon: ");
		scanf("%d",&key);
		switch(key){
			case 1:
				nhapN(ds,n);
				printf("	Ban da nhap thanh cong !\n");
				daNhap = true;
				printf("	Bam bat ki phim nao de tiep tuc !");
				getch();
				break;
			case 2:
				if(daNhap){
					printf("	Thong tin do uong sau khi sap xep :\n");
					sapxep(ds,n);
					hienThiMENU(ds,n);
				}
				else{
					printf("	LUU Y: Nhap thong tin cho do uong truoc!\n");
				}
				printf("	Bam bat ki phim nao de tiep tuc!");
				getch();
				break;
			
			case 3:
				if(daNhap){
					timtheotheloai(ds,n);
				}
				else{
					printf("	LUU Y: Nhap thong tin cho do uong truoc!\n");
				}
				printf("	Nhan phim bat ki de tiep tuc\n");
				getch();
				break;
			case 4:
				if(daNhap){
				ghiFile(ds,n);
				}
				else{
					printf("	LUU Y: Nhap thong tin cho do uong truoc!\n");
				}
				printf("	Nhan phim bat ki de tiep tuc\n");
				getch();
				break;
			case 5:
				return 0;
				break;
			default :
				printf("	Khong co chuc nang nay\n");
				printf("	Bam phim bat ki de tiep tuc!");
				getch();
				break;	
			}	
		}
	}
