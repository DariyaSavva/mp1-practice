#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include <math.h>

int main()
{
	double x1, x2, y1, y2, r1, r2, s;
	printf("Vvedite radius i koordinaty tsentra pervoy okruzhnosti\n");
	scanf_s("%lf %lf %lf", &r1, &x1, &y1);
	if (r1 <= 0)
	{
		printf("Neverno vveden radius");
		return 1;
	}
	printf("Vvedite radius i koordinaty tsentra vtoroy okruzhnosti\n");
	scanf_s("%lf %lf %lf", &r2, &x2, &y2);
	if (r2 <= 0)
	{
		printf("Neverno vveden radius");
		return 1;
	}
	s = sqrt(pow((x1 - x2), 2.0) + pow((y1 - y2), 2.0));
	printf("%f", s);
	if (s == r1 + r2)
		printf("Okruzhnosti kasaytsya v 1 tochke");
	else if (s > r1 + r2)
		printf("Okruzhnosti ne peresekayutsya");
	else if (s == 0 && r1 == r2)
		printf("Okruzhnosti sovpadayut");
	else
	{
		double R, r;
		if (r1 >= r2)
			R = r1;
		else
			R = r2;
		r = r1 + r2 - R;
		printf("%f%f", r, R);
		if (r + s == R)
			printf("Vnytrennee kasanie okryzhnostey");
		else if (r + s > R)
			printf("Okruzhnosti peresekayutsya v 2 tochkah");
		else
			printf("Odna okruzhnost lejit vnutri drugoy i ne imeet s nei obshchikh tochek");
	}
	return 0;
}