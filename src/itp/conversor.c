#include <stdio.h>
#include <string.h>

int main()
{
    char entrada[6];
    fgets(entrada, sizeof(entrada), stdin);

    int temperatura;
    char escala;

    if (entrada[1] == ' ')
    {
        temperatura = entrada[0] - '0';
        escala = entrada[2];
    }
    else
    {
        temperatura = ((entrada[0] - '0') * 10) + (entrada[1] - '0');
        escala = entrada[3];
    }

    float conversao_celsius_para_kelvin = temperatura + 273.15;
    float conversao_celsius_para_Farenheit = temperatura * 1.8 + 32;

    float conversao_farenheit_para_celsius = (temperatura - 32) / 1.8;
    float conversao_farenheit_para_kelvin = conversao_farenheit_para_celsius + 273.15;

    float conversao_kelvin_para_celsius = temperatura - 273.15;
    float conversao_kelvin_para_farenheit = conversao_kelvin_para_celsius * 1.8 + 32;

    if (escala == 'C')
    {
        float temperatura_celsius = (float)temperatura;
        printf("Celsius: %.2f\n", temperatura_celsius);
        printf("Farenheit: %.2f\n", conversao_celsius_para_Farenheit);
        printf("Kelvin: %.2f\n", conversao_celsius_para_kelvin);
    }
    if (escala == 'F')
    {
        float temperatura_farenheit = (float)temperatura;

        printf("Celsius: %.2f\n", conversao_farenheit_para_celsius);
        printf("Farenheit: %.2f\n", temperatura_farenheit);
        printf("Kelvin: %.2f\n", conversao_farenheit_para_kelvin);
    }
    if (escala == 'K')
    {
        float temperatura_kelvin = (float)temperatura;

        printf("Celsius: %.2f\n", conversao_kelvin_para_celsius);
        printf("Farenheit: %.2f\n", conversao_kelvin_para_farenheit);
        printf("Kelvin: %.2f\n", temperatura_kelvin);
    }

    return 0;
}
