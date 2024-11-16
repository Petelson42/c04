#include <unistd.h>  // Necessário para usar a função write

void ft_putchar(char c)
{
    write(1, &c, 1);  // Função auxiliar para imprimir um caractere
}

void ft_putnbr(int nb)
{
    if (nb == -2147483648)  // Caso especial para o menor valor de int
    {
        write(1, "-2147483648", 11);  // Imprime diretamente a string do valor
        return;
    }
    if (nb < 0)
    {
        ft_putchar('-');  // Imprime o sinal negativo
        nb = -nb;  // Torna o número positivo
    }
    if (nb >= 10)
    {
        ft_putnbr(nb / 10);  // Chamada recursiva para imprimir os dígitos
    }
    ft_putchar(nb % 10 + '0');  // Imprime o último dígito
}

int main()
{
    ft_putnbr(42);         // Chama a função para imprimir o número 42
    write(1, "\n", 1);     // Imprime uma nova linha
    ft_putnbr(-2147483648);  // Teste com o menor valor de int
    write(1, "\n", 1);     // Imprime uma nova linha
    return 0;
}