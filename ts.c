#include<stdio.h>

int dist[20][20],n,cost=0,completed[10];

void insert()
{
	printf("Enter the no. of cities:\n");
	scanf("%d",&n);
	
	printf("Cost of Matrix\n\n");
	
	int i,j;
	for(i=0;i<n;i++)
	{
		printf("Row:%d\n",i+1);
		for(j=0;j<n;j++)
		{
			scanf("%d",&dist[i][j]);
		}
		completed[i]=0;
	}
}

int least(int c)
{
	int nc=999;
	int kmin,min=999;
	int i;
	
	for(i=0;i<n;i++)
	
	{
		if((dist[c][i]!=0) && (completed[i]==0))
		{
			if(dist[c][i]+dist[i][c]<min)
			{
			
				min=dist[c][i]+dist[i][c];
				kmin=dist[c][i];
				nc=i;
			}
		}
	}
	if(min!=999)
	{
		cost+=kmin;
	}
	return nc;
}

void mincost(int city)
{
	int ncity;
	int i;
	
	completed[city]=1;
	
	printf("%d-->",city+1);
	ncity=least(city);
	
	if(ncity==999)
	{      
		ncity=0;
		printf("%d",ncity+1);
		cost+=dist[city][ncity];
		return;
			}	
	mincost(ncity);	
}


int main()
{
	insert();
	
	mincost(0);
	printf("Minimum Cost:%d\n",cost);
	return 0;
}
