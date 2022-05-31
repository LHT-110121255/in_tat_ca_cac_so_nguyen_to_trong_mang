#include <stdio.h>

bool mark[10001];
bool snt(int n);
void nhap(int *arr, int n);
void xuat(int *arr, int n);
void out_all_snt(int *arr, int n);
int dem_snt(int *arr, int n);
int main()
{
	int n; 
	printf("nhap kich thuoc  mang = ");
	scanf("%d", &n);
	int arr[n];
	nhap(arr, n);
	out_all_snt(arr, n);
	printf("\nCo %d so nguyen to trong mang", dem_snt(arr, n));
}
void nhap(int *arr, int n)
{
	int i;
	for(i = 1; i <= n; i++)
	{
		printf("nhap arr[%d]", i);
		scanf("%d", &arr[i]);
	}
	printf("\nmangg vua nhap \n");
	xuat(arr, n);
}
void xuat(int *arr, int n)
{
	int i;
	for(i = 1; i <= n; i++)
		printf("%d\t", arr[i]);
}
bool snt(int n)
{
	if( n <= 1) return false;
	int a = 2; 
	while(true)
	{
		if(a*a > n) break;
		int p = a*a;
		while(p <= n)
		{
			mark[p] = true;
			p += a;
		}
		++a;
		while(a <= n && mark[a]) ++a;
		if(a > n) break;
	}
	return (mark[n]) ? false : true;
}
void out_all_snt(int *arr, int n)
{
	int i;
	for(i = 1; i <= n; i++)
		(snt(arr[i])) ? printf("\n%d la so nguyen to ", arr[i]) : i;
}
int dem_snt(int *arr, int n)
{
	int dem = 0;
	int i;
	for(i = 1; i <= n; i++)
		(snt(arr[i])) ? ++dem: dem;
	return dem;
}
