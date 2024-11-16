#include <unistd.h>  // Necessário para usar a função write

void ft_putstr(char *str)
{
    // Percorre a string e imprime cada caractere usando write
    while (*str)
    {
        write(1, str, 1);  // O primeiro parâmetro é o file descriptor (1 = stdout)
        str++;  // Avança para o próximo caractere
    }
}

int main()
{
    char str[] = "Olá, mundo!";
    ft_putstr(str);  // Chama a função para imprimir a string
    return 0;
}