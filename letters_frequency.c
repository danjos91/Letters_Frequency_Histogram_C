#include <stdio.h>
#include <string.h>
#include <ctype.h>

void count_letters(char* str, int* alphabet_eng)
{
	char ch = ' ';
	int i = 0;

	while(i <= 26){
		alphabet_eng[i] = 0;
		i++;
	}
	i = 0;

	while (i < strlen(str))
	{
		ch = str[i];
		ch = tolower(ch);
		if (ch >= 97 && ch <= 122)
		{
			alphabet_eng[ch - 97]++;
		}
		i++;
	}
}

int get_max(int* data)
{
	int i = 0;
	int max = data[0];

	while (i < 26)
	{
		if(data[i+1] > data[i])
		{
			max = data[i+1];
		}
		i++;
	}
	return max;
}

void print_hist(int* data)
{
	int i = 0;
	int tmp;
	int max;

	max = get_max(data);
	while(i < 26)
	{
		printf("[\033[31;1m%c\033[0m]", i + 97);
		tmp = data[i];
		if(max > 15)
		{
			tmp = tmp * 15 / max;
		}
		while(tmp > 0)
		{
			printf("\033[32;1m=\033[0m");
			tmp--;
		}
		printf("%d\n", data[i]);
		i++;
	}
}

int main(){
	char str[200];
	int* numbers[26];

	while (gets(str)  && strcmp(str, "0") != 0)
	{
		count_letters(str, numbers);
		print_hist(numbers);
	}
	return(0);
}

