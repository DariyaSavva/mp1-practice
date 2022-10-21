#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

// табличные значения плотности материалов: ДСП - 650 кг/м^3, ДВП - 800кг/м^3, дерево - 550кг/м^3
int main()
{
    double w, h, d, dsp, dvp, der, n, m;
    double DSP = 0.65;  // в строках 8-11 объявляются переменные,являющиеся 
    double DVP = 0.8;  // аналогами констант в данной программе
    double D = 0.55;
    int S_MEJDY_POLKAMI = 40;
    printf("Vvedite cherez probel vysotu, shirinu i glubinu shkafa\n");
    scanf_s("%lf %lf %lf", &h, &w, &d);
    if ((h < 180) || (h > 220) || (w < 80) || (w > 120) || (d < 50) || (d > 90))
    {
        printf("Nevernye vhodnye dannye");
        return 1;
    }
    n = ((int)h - 1) / S_MEJDY_POLKAMI;  // формула нахождения количества полок
    // учитывается случай, когда при высоте 220 см длина полок по-прежнему = 3 в силу наличия толщины самих полок
    dsp = DSP * 1.5 * d * (2 * h + 2 * w + n * (w - 3));  // 20-22 строки: масса деталей из ДСП, ДВП, дерева соответственно
    dvp = DVP * 0.5 * w * h;
    der = D * w * h;
    m = (dsp + dvp + der) / 1000.0; // общая масса в кг
    printf("Massa shkafa v kg: %lf", m);
    return 0;
}