#include<stdio.h>
#include<string.h>
#define max 100
struct QUANLI
{
	char DoUong[50];
	int GiaSanPham;
	char size[5];
	int SoLuong;
};
typedef QUANLI QuanLi;
struct DANHSACH
{
	QuanLi a[max];
	int n;
};
typedef DANHSACH DanhSach;
void NhapSoLieu(QuanLi &QL)
{
	fflush(stdin);
	printf ("\nMoi Khach Hang Muon Chon Do Uong : ");
	gets(QL.DoUong);
	printf("\nGia Cua Moi Do Uong La:");
	scanf("%d",&QL.GiaSanPham);
	printf("\n Cua hang co size m: la nho , l: la lon");
	printf("\nChon kich co do uong ban muon: ");
    scanf("%s",&QL.size);
	printf ("\nSo Luong Do Uong Quy Khach Mong Muon la : ");
	scanf("%d",&QL.SoLuong);
}
void XuatSoLieu(QuanLi QL)
{
	printf ("\nLoai Do Uong Quy Khach Da Chon : %s", QL.DoUong);	
	printf("\nGia Do Uong Quy khach Vua Chon La : %d",QL.GiaSanPham);
	printf("\nKich co ban chon: %s",QL.size);
    printf("\nSo Luong Quy Khach Da Chon : %d ",QL.SoLuong);
}
void NhapDS(DanhSach &ds)
{
	printf("\nNhap Loai Do Uong Can la : ");
	scanf("%d",&ds.n);
	printf ("\nNhap Thong Tin Do Uong");
	for (int i=0; i<ds.n; i++)
	{
		printf("\nMat Hang thu %d la:", i+1);
		NhapSoLieu(ds.a[i]);
	}
}
void XuatDS(DanhSach &ds)
{
	for (int i=0; i<ds.n ; i++)
	{
		XuatSoLieu(ds.a[i]);
	}
}
void ThemDoUong(DanhSach &ds,QuanLi x,int k)
{
	for(int i=ds.n;i>=k;i--)
		{
			ds.a[i]=ds.a[i-1];
		}
		ds.a[k]=x;
		ds.n++;
}
int TimDoUong(DanhSach ds, char *c)
{
	int dem=0;
	for(int i=0 ; i<ds.n ; i++)
	{
		if(strcmp(ds.a[i].DoUong,c)==0)
		{
			return i;
			break;
		}
		dem++;
	}
	return -1;
}
void XoaMotDoUong(DanhSach ds, char *c)
{
	int vt=TimDoUong(ds,c);
	if(vt==-1)
	printf("\nkhong tim thay Do Uong %s muon xoa",c );
	else
		for (int i=vt ; i>ds.n ; i++)
		{
			ds.a[i]=ds.a[i+1];
			ds.n++;
		}
}
void ThongKe(DanhSach ds){
	int dem=0;
	printf("\nThong Tin Do Uong %s: \n", ds.a[0].DoUong);
	for(int i=0;i<ds.n;i++){
		XuatDS(ds);
		dem++;
		if(ds.a[i+1].DoUong!=ds.a[i].DoUong){
			printf("\t** so luong Do uong %s co %d quyen sach\n",ds.a[i].DoUong,dem);
			dem=0;
			if(i<ds.n-1)
				printf("\nThong tin Do uong %s: \n", ds.a[i+1].DoUong);
		}
	}
}
void SapXep(DanhSach ds)

{
	for(int i=0;i<ds.n-1;i++)
	{
		for(int j=i+1;j<ds.n;j++)
		{
			if(ds.a[i].SoLuong<ds.a[j].SoLuong)
			{
				float t=ds.a[i].SoLuong;
				ds.a[i].SoLuong=ds.a[j].SoLuong;
				ds.a[j].SoLuong=t;
			}
		}
	}
}
void ThanhToan(DanhSach ds, int Tong=0)
{
	SapXep(ds);
	int vt = 0;//vi tri bat dau dem;
	for(int i = vt; i<ds.n; i = vt)
	{
		int dem = 1;
		int Tong = ds.a[i].SoLuong*ds.a[i].GiaSanPham;
		for(int j = vt + 1; j < ds.n; j++)
		{
			if(ds.a[i].DoUong == ds.a[j].DoUong)
			{
				dem++;
				Tong = Tong + ds.a[j].SoLuong*ds.a[j].GiaSanPham;
			}
			else
			{
				break;
			}
		}
		if(dem>0)
		{
			printf("\nTien cua do uong %s la %d",ds.a[vt].DoUong,Tong);
			vt = vt + dem; //vi tri bat dau moi;
		}
	}
}
void menu()
{
	DanhSach ds;
	QuanLi x;
	int i,k;
	char *c;
	int Tong=0;
	int chon, flat=1;
	NhapDS(ds);
	
	while(flat)
	{
		printf ("\n===============THAY_DOI===============");
		printf("1.Them Mot Do Uong ");
		printf("2.Loai Bo Mot Loai Do uong");
		printf("3.Tim Do Uong ");
		printf("4.Thong ke");
		printf("5.Thanh Toan");
		printf("6.HET Mong Quy Khach Doi ");
		printf("-------------------------------------");
		printf("\n HAY CHON SO BAN MUON");
		scanf("%d",&chon);
		switch (chon)
		{
			case 1:
			{
				printf("\n\tvi tri them: ");
				scanf("%d",&k);
				NhapSoLieu(x);
				ThemDoUong(ds,x,k);
				printf("\ndanh sach do uong sau khi them la :");
				XuatDS(ds);
				break;
			}
			case 2:
			{
				int d;
				DanhSach ds;
				printf("\n\tNhap ma so can tim: ");
				scanf("%d",&d);
				int b=TimDoUong(ds,c);
				if(TimDoUong(ds,c)==-1)
					printf("\nkhong tim thay");
				else
					printf("\nTim thay nhan vien thu %d",b+1);
					break;
			}
			case 3:
			{
				char c[20];
				printf("\n\tnhap ten can tim: ");
				fflush(stdin);
				gets(c);
				int b=TimDoUong(ds,c);
				if(TimDoUong(ds,c)==-1)
					printf("\nKhong tim thay nhan vien: %s",c);
				else
					printf("\nTim thay nhan vien thu %d",b+1);
					break;
				}
			case 4:
			{
			    ThongKe(ds);	
				break;
			}
			case 5:
				{
					ThanhToan(ds,Tong);
					break;
				}
			case 6:
			{
				flat=0;
				break;
			}	
			default: 
			{
				printf("\nkhong co chuc nang nay");
				break;
			}
	    
		}
	}
}
int main()
{
	menu();
}
