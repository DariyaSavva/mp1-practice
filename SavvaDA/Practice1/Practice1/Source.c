#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

// ��������� �������� ��������� ����������: ��� - 650 ��/�^3, ��� - 800��/�^3, ������ - 550��/�^3
int main()
{
    double w, h, d, dsp, dvp, der, n, m;
    double DSP = 0.65;  // � ������� 8-11 ����������� ����������,���������� 
    double DVP = 0.8;  // ��������� �������� � ������ ���������
    double D = 0.55;
    int S_MEJDY_POLKAMI = 40;
    printf("Vvedite cherez probel vysotu, shirinu i glubinu shkafa\n");
    scanf_s("%lf %lf %lf", &h, &w, &d);
    if ((h < 180) || (h > 220) || (w < 80) || (w > 120) || (d < 50) || (d > 90))
    {
        printf("Nevernye vhodnye dannye");
        return 1;
    }
    n = ((int)h - 1) / S_MEJDY_POLKAMI;  // ������� ���������� ���������� �����
    // ����������� ������, ����� ��� ������ 220 �� ����� ����� ��-�������� = 3 � ���� ������� ������� ����� �����
    dsp = DSP * 1.5 * d * (2 * h + 2 * w + n * (w - 3));  // 20-22 ������: ����� ������� �� ���, ���, ������ ��������������
    dvp = DVP * 0.5 * w * h;
    der = D * w * h;
    m = (dsp + dvp + der) / 1000.0; // ����� ����� � ��
    printf("Massa shkafa v kg: %lf", m);
    return 0;
}