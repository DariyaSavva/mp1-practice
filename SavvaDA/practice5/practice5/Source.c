#include <stdio.h>
#define n 10

char* products[n] = { "milk", "cheese", "oil", "tea", "ginger", "coffee", "salt", "sugar", "chewing gum", "candies" };
int prices[n] = { 86, 70, 216, 54, 567, 200, 457, 45, 5, 67 };
char* barcode[n] = { "1111", "1112", "1113", "1114", "1115", "1116", "1117", "1118", "1119", "1121" };
float discounts[n] = { 0.1, 0.2, 0.25, 0.4, 0.2, 0.3, 0.25, 0.1, 0.1, 0.25 };
int kolvo[n] = { 0 };
int itog_price = 0;
int itog_discount = 0;


void information(int ind) {
	printf("Name: %s; Price: %d rub; Discount: %d percent.\n", products[ind], prices[ind], (int)(discounts[ind] * 100));
}

void add_product(int ind) {
	kolvo[ind]++;
}

int skan_products() {
	int i;
	char tovar[10];
	printf("Enter the product barcode:\n");
	gets(tovar);
	for (i = 0; i < n; i++)
	{
		if (strcmp(tovar, barcode[i]) == 0)
		{
			return i;
		}
	}
	if (strcmp("END", tovar) != 0)
	{
		return -1;
	}
	return -2;
}

void print_chek() {
	int i, sum, discount;
	int itog_summ = 0;
	int itog_discount = 0;
	printf("Name;Price;Amount;Total price\n");
	printf("-----------------------------------\n");
	for (i = 0; i < n; i++)
		if (kolvo[i] > 0)
		{
			sum = kolvo[i] * prices[i];
			itog_summ += sum;
			itog_discount += sum * discounts[i];
			printf("%s - %d rub - %d items - %d rub\n", products[i], prices[i], kolvo[i], sum);
		}
	printf("-----------------------------------\n");
	printf("Total price: %d; Total discount: %d; Resulting price: %d\n", itog_summ, itog_discount, itog_summ - itog_discount);
	printf("Thank you for your purchase!");
}


int main()
{
	int ind_product;
	printf("Welcome to shop! Enter a barcode for each product. When you have scanned all the products, enter END\n");
	do {
		ind_product = skan_products();
		if (ind_product == -1)
		{
			printf("Barcode entered incorrectly.\n");
			continue;
		}
		if (ind_product == -2)
		{
			print_chek();
			break;
		}
		information(ind_product);
		add_product(ind_product);
	} while (1);
}