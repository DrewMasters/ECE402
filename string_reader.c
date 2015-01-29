#include <stdio.h>

int main(int argc, char **argv)
{
	char input[100], l2, l1;
	int i, size, m, n, c, j;
	
	/*
		c=current clause
		i, j=iterator values
		size=size of equation input
		m=number of clauses
		n=number of variables
		l1=previous character 
		l2=two characters ago
		input=variable used to read stdin and in final part of program
			is the equation being analyzed
	*/
	c=0;

	printf("Input number of clauses\n");
	gets(input);
	m=atoi(&input);
	printf("Input number of variables\n");
	gets(input);
	n=atoi(input);
	printf("Input equation\n");
	gets(input);

	printf("input: %s\n", input);

	size = (int) strlen(input);

	int c_mi[m][n];

	for (i=0; i<m; i++)
	{
		for (j=0; j<n; j++)
		{
			c_mi[i][j]=0;
		}
	}
	l1='0';
	l2='-';
	
	for (i=0; i<size; i++)
	{
		if (i!=0) l1=input[i-1];
		if (i!=0&&i!=1) l2=input[i-2];

		if (l1==')'&&input[i]=='(') c=c+1;
		if (l1=='X')
		{
			if (l2=='^') c_mi[c][input[i]-'0'-1]=-1;
			else c_mi[c][input[i]-'0'-1]=1;
		}
		
	}

	for (i=0; i<m; i++)
	{
		for (j=0; j<n; j++)
		{
			printf("%d",c_mi[i][j]);
		}
		printf("\n");
	}
}
