#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int fact(int);
int rank(char *);
int init(int *,char *);
void update(int *,char);

int fact(int n)
{
	return n<=1 ? 1:n*fact(n-1);
}

int init(int *count,char *s) 
{
	int i,rep=0;
	for(i=0;s[i];i++)
		count[s[i]-97]++;
	for(i=0;i<26;i++)
		if(fact(count[i])>1)
			rep+=fact(count[i]);
	for(i=0;i<25;i++) 
		count[i+1]+=count[i];
	return rep;
}

void update(int *count,char c) 
{	
	int i;
	for(i=c-97;i<26;i++)
		count[i]--;
}

int rank(char *s)
{
	int i,*count,r=0,len=strlen(s),rep;
	count=calloc(26,sizeof(int));
	rep=init(count,s);
	for(i=0;s[i];i++) {
		r+=(count[s[i]-97]-1)*fact(len-i-1);
		update(count,s[i]);
	}
	return fact(len)-r;
}


int main()
{
	char s[11];
	scanf("%s",s);
	printf("%d\n",rank(s));
	return 0;
}

/*You need to create an other array for repetitions*/

