#include <stdio.h>

int ft_strlen(char *str)
{
    int length = 0;

    // Percorre a string até encontrar o caractere nulo ('\0')
    while (str[length] != '\0')
    {
        length++;
    }

    return length;
}

int main() {
    char str[] = "Olá, mundo!";
    int length = ft_strlen(str);
    printf("O comprimento da string é: %d\n", length);  // Exibe o comprimento da string
    return 0;
}