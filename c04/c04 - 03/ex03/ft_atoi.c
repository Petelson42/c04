#include <stdio.h>

int ft_atoi(char *str)
{
    int i = 0;
    int result = 0;
    int sign = 1;

    // Ignora espaços em branco no começo da string
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
    {
        i++;
    }

    // Verifica os sinais de '+' ou '-' no começo
    while (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
        {
            sign = -sign;  // Alterna o sinal para negativo
        }
        i++;
    }

    // Converte os caracteres numéricos em inteiro
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');  // Adiciona o dígito ao resultado
        i++;
    }

    // Retorna o resultado com o sinal correto
    return result * sign;
}


int main()
{
    char str1[] = "   -1234";
    char str2[] = "   +42";
    char str3[] = " ---+--+1234ab567";
    char str4[] = "  0";
    
    printf("Resultado 1: %d\n", ft_atoi(str1));  // Deve imprimir: -1234
    printf("Resultado 2: %d\n", ft_atoi(str2));  // Deve imprimir: 42
    printf("Resultado 3: %d\n", ft_atoi(str3));  // Deve imprimir: 1234
    printf("Resultado 4: %d\n", ft_atoi(str4));  // Deve imprimir: 0

    return 0;
}