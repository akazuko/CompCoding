#include<stdio.h>

void merge(int a[],int p,int q,int r)
{
	int i=0,j=0,k,n1=(q-p+1),n2=(r-q);
	int la[n1+1],ra[n2+1];
	la[n1]= 30000;
	ra[n2]=30000;
	for(i=0;i<n1;i++)
		la[i]=a[p+i];
	for(j=0;j<n2;j++)
		ra[j]=a[q+j+1];
	i=0;j=0;
	for(k=p;k<=r;k++)
	{
		if(la[i]<ra[j])
			a[k]=la[i++];
		else
			a[k]=ra[j++];
	}
}

void merge_sort(int a[], int p, int r)
{
	if(p<r)
	{
		int q=(p+r)/2;
		merge_sort(a,p,q);
		merge_sort(a,q+1,r);
		merge(a,p,q,r);
	}
}

int main()
{
	int a[] ={5,9,3,19,3,4,8,6,2,5,7,10};
	merge_sort(a,0,11);
	int i;
	for(i=0;i<12;printf("%d\t",a[i++]));
	return 0;
}