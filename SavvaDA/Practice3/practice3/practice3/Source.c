#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 5

int main()
{
	srand(time(NULL));
	int n, count, ch, bulls, cows, try, value, i, j, number, arr[size], c, flag;
	printf("Welcome to the Bulls and Cows game!\nEnter the length of the word : (from 2 to 5)\n");
	do
	{
		count = scanf_s("%d", &n);
		if (count == 1)
		{
			if ((n < 6) && (n > 1))
				break;
			else
				printf("Invalid range");
		}
		else
			printf("Not a number");
		while (ch = getchar() != '\n');
	} while (1);
	arr[0] = 1 + rand() % 9;
	for (i = 1; i < n; i++)
	{
		do {
			c = 0 + rand() % 10;
			flag = 1;
			for (j = 0; j < i; j++)
			{
				if (c == arr[j])
				{
					flag = 0;
					break;
				}
			}
			if (flag)
				break;
		} while (1);
		arr[i] = c;
	}
	printf("The computer selected a %d-digit number with non-repeating digits.\n", n);
	do {
		printf("Try to guess the number: ");
		scanf_s("%d", &try);
		bulls = 0; cows = 0;
		for (i = 0; i < n; i++)
		{
			value = try % 10;
			try /= 10;
			if (arr[n - 1 - i] == value)
				bulls++;
			for (j = 0; j < n; ++j)
			{
				if (arr[j] == value)
					cows++;
			}
		}
		if (bulls != n)
			printf("bulls: %d, cows: %d\n", bulls, cows);
		else
		{
			printf("You have won!!");
			break;
		}

	} while (1);
}