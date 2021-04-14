#include<stdio.h>
struct QuanLi{
	char DoUong[50];
	int SoLuong;
};
void NhapSoLieu( QuanLi a){
	fflush(stdin);
	printf("\nDo uong quy khach mong muon la: ");
	gets(a.DoUong);
	printf("\nSo luong cua loai do uong la: ");
	scanf("%d",&a.SoLuong);
}
void XuatSoLieu( QuanLi a){
	printf ("\nloai do uong moi chon la : %s",a.DoUong);
	printf("\nSo luong ban chon La: %d", a.SoLuong);
}
void NhapDS(QuanLi a[], int &n)
{
	printf("\nNhap Loai Do Uong Can la : ");
	scanf("%d",&n);
	for (int i=0; i<n; i++)
	{
		printf("\nMat Hang thu %d la:", i+1);
		NhapSoLieu(a[i]);
	}
}
void XuatDS(QuanLi a[],int n)
{
	for (int i=0; i<n ; i++)
	{
		XuatSoLieu(a[i]);
	}
}
void Menu(){
	int chon;
	int x,d,f;
	printf ("\n===============MENU===============");
	printf("1.Them Mot Do Uong ");
	printf("2.Loai Bo Mot Loai Do uong");
	printf("3.In lai Tat Ca");
	printf("4.Thanh Toan")
	printf("5.Xong ");
	printf("-------------------------------------");
	printf("\n HAy CHON THU BAN MUON");
	scanf("%d",&chon);
	switch(chon){
		case 1:{
			NhapDS(a,n);
			ThemDoUong(a,n,k);
			printf("\ndanh sach sau khi them");
			XuatDS(a,n);
			break;
		}
		case2:{
			printf()
			break;
		}
	}
}
void ThemDoUong(QuanLi a[],int n,int k)
{

	for(int i=0;i<n;i++)
	{
		a[n]=k;
	}
	n=n+1;
 	XuatDS(a,n);
}
void XoaMotDoUong(QuanLi a[],int n,int x){
	int x;
	for(int i=0;i<n;i++)
	{
		a[x]=a[x+1]; 
		n=n-1; 
		XuatDS(a,n);
	}
}
Void ThanhToan()
int main(){
	struct QuanLi;
	printf ("\n===============MENU===============");
	printf("1.CAfE DEN................15");
	printf("2.CAFE SUA................20");
	printf("3.TRA SUA.................20");
	printf("4.SINH TO.................25");
	printf("-------------------------------------");
	printf("\n HAy CHON THU BAN MUON");
	menu();
	getch();
}
