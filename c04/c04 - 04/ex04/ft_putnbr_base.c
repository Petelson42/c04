#include <unistd.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

int is_valid_base(char *base)
{
    int i, j;
    int len = ft_strlen(base);

    if (len < 2) // A base precisa ter pelo menos dois caracteres
        return 0;

    // Verificar se a base contém caracteres repetidos ou + / -
    for (i = 0; i < len; i++)
    {
        if (base[i] == '+' || base[i] == '-' || base[i] == ' ' || base[i] == '\t')
            return 0;
        for (j = i + 1; j < len; j++)
        {
            if (base[i] == base[j])
                return 0; // Base contém caracteres repetidos
        }
    }
    return 1; // A base é válida
}

void ft_putnbr_base(int nbr, char *base)
{
    int base_len = ft_strlen(base);

    // Verifique se a base é válida
    if (!is_valid_base(base))
        return;

    // Caso o número seja negativo, imprima o sinal e trabalhe com seu valor absoluto
    if (nbr < 0)
    {
        write(1, "-", 1);
        nbr = -nbr; // Trabalha com o número positivo
    }

    // Imprime a parte recursiva do número dividindo pela base
    if (nbr >= base_len)
    {
        ft_putnbr_base(nbr / base_len, base);  // Recursão para a parte mais significativa
    }

    // Imprime o último dígito, que corresponde ao valor de 'nbr' mod base_len
    write(1, &base[nbr % base_len], 1);
}

int main()
{
    ft_putnbr_base(42, "0123456789");        // Base decimal
    write(1, "\n", 1);

    ft_putnbr_base(42, "01");               // Base binária
    write(1, "\n", 1);

    ft_putnbr_base(42, "0123456789ABCDEF"); // Base hexadecimal
    write(1, "\n", 1);

    ft_putnbr_base(42, "poneyvif");         // Base personalizada
    write(1, "\n", 1);

    ft_putnbr_base(-42, "0123456789");      // Número negativo em base decimal
    write(1, "\n", 1);

    return 0;
}
