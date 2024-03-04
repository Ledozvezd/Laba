#include <stdio.h>


void Replace(char* ptr)
{
	int k = 0;
	int temp;
	while (ptr[k] != '\0')
	{
		if (ptr[k] == (char)39)
		{
			temp = (int)ptr[++k];
			ptr[--k] = (temp / 10)+48;
			ptr[++k] = (temp % 10)+48;
			ptr[++k] = ' ';
		}
		else
		{
			k++;
		}
	}

	k = 0;

	while (ptr[k] != '\0')
	{
		if (ptr[k] == ' ')
		{
			ptr[k] = ptr[k+1];
		}
		else
		{
			k++;
		}
	}
}

void main()
{
	char string[] = "a'4'aaxo['8'[pxx\0";
	char* ptr = string;
	Replace(ptr);
	printf(string);
	scanf_s(string);
}