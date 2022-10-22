#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS


int main()
{
	srand(time(NULL));
	int try_number, number, count, mode, ch0;
	count = 0;  // счётчик кол-ва попыток
	printf("Which game mode do you choose: 1 or 2? ");
	do {
		scanf_s("%d", &mode);
	} while (mode != 2 && mode != 1);
	if (mode == 1)
	{
		printf("The program guessed a number from 0 to 1000. Try to guess!\n");
		number = 0 + rand() % 1001;
		do {
			int correctione;
			correctione = scanf_s("%d", &try_number);
			while (correctione != 1) {
				printf("Invalid input\n");
				while (ch0 = getchar() != '\n');
				correctione = scanf_s("%d", &try_number);
			}
			count++;
			if (number < try_number)
				printf("The hidden number <\n");
			else if (number > try_number)
				printf("The hidden number >\n");
			else
				printf("Congratulations!!! You guessed the number! Number of attempts made: %d", count);
		} while (try_number != number);
	}
	else
	{
		int start = 0, end = 1000;
		char ch;
		printf("Guess a number from 0 to 1000, and the program will try to guess it.\n");
		printf("If the hidden number is less, enter '<'\n");
		printf("if it is greater, enter '>'\n");
		printf("if the program guessed correctly, enter '='\n");
		do {
			printf("My version: %d\n", (start + end) / 2);
			while (ch0 = getchar() != '\n');
			scanf_s("%c", &ch, 1);
			while (ch != '<' && ch != '>' && ch != '=') {
				while (ch0 = getchar() != '\n');
				printf("invalid input\n");
				scanf_s("%c", &ch, 1);
			}
			if (ch == '>')
				start = (start + end) / 2 + 1;
			else if (ch == '<')
				end = (start + end) / 2 - 1;
			else
				printf("The program guessed the number! Number of attempts: %d", count);
			count++;
		} while (ch != '=');
	}
	return 0;
}
