#include<stdio.h>
#include<string.h>
int max(int a,int b)
{
	return(a>b)?a:b;
}
int main()
{
	char s[50];
	int dp[100][100];
	int n,i,len;
	
	printf("enter string");
	scanf("%s",s);
	n=strlen(s);
	
	for(i=0;i<n-len;i++)
	{
		dp[i][i]=1;
	}
	for(len=2;len<=n;len++)
	{
		for(i=0;i<n;i++)
		{
			int j=i+len-1;
			if(s[i]==s[j])
			{
				if(len==2)
					dp[i][j]=2;
				else
					dp[i][j]=2+dp[i+1][j-1];
			}
			else
			{
				dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
			}
		}
	}
	printf("longest pallindromic subsequence:%d\n",dp[0][n-1]);
	return 0;
	
	
	
}
