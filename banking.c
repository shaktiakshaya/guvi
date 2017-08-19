#include<stdio.h>
#include<string.h>
void main()
{
int n,np,r[10],a[10][10],c[10][10],need[10][10],i,j,x,k,avl[10]flag=0,proc[10],pi=0,pcheck=0;
printf("Enter the number of resources \n");
scanf("%d",&n);
printf("Enter the number of processes \n");
scanf("%d",&np);

//INITIAL RESOURCES
for(i=0;i<n;i++)
{
printf("Enter the initial resources at start for %d resource:",i);
scanf("%d",&r[i]);
}

//CLAIM
for(i=0;i<n;i++)
for(j=0;j<np;j++)
{
printf("Claim of R%d for P%d "",i,j);
scanf("%d",&c[i][j]);
}

//ALLOCATION
for(i=0;i<n;i++)
for(j=0;j<np;j++)
{
printf("Allocation of R%d for P%d "",i,j);
scanf("%d",&a[i][j]);
}

//NEED
for(i=0;i<n;i++)
for(j=0;j<np;j++)
need[j][i]=c[j][i]-a[j][i];

//AVAILABLE RESOURCES
for(i=0;i<n;i++)
	avl[i]=0;
for(i=0;i<n;i++)
	for(j=0;j<np;j++)
		avl[i]+=a[j][i];
for(i=0;i<n;i++)
	avl[i]=r[i]-avl[i];


for(x=0;x<10;x++)
	for(i=0;i<np;i++)
	{
	for(j=0;j<n;j++)
			if(avl[j] >= need[i][j])
			flag++;
		if(flag==n)
		{
			pcheck=0;
			if(pi!=0)
			for(k=0;k<pi;k++)
				if(i!=proc[k])
				pcheck++;
			if(pcheck==pi)
				{
				proc[pi+1]==i;
				for(k=0;k<n;k++)
					avl[k]+=a[i][k];
				printf("Process %d has been executed",i);
				for(k=0;k<n;k++)
					printf("%d",avl[k]);
				pcheck=0;
				}
		}
	flag=0;
	}
	if(pi!=np)
		printf("Unable to find safe sequence");
}


