#include <unistd.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

// Função que valida a base
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
            if (base[i] == base[j]) // Base contém caracteres repetidos
                return 0;
        }
    }
    return 1; // A base é válida
}

// Função que converte o caractere para o valor correspondente na base
int ft_char_to_value(char c, char *base)
{
    int i = 0;
    while (base[i] != '\0')
    {
        if (base[i] == c)
            return i;  // Retorna o valor do caractere na base
        i++;
    }
    return -1;  // Retorna -1 se o caractere não for válido na base
}

// Função que converte a string para o número inteiro na base fornecida
int ft_atoi_base(char *str, char *base)
{
    int i = 0;
    int result = 0;
    int sign = 1;
    int base_len;

    // Verificar se a base é válida
    if (!is_valid_base(base))
        return 0;

    base_len = ft_strlen(base);

    // Ignorar espaços em branco no início da string
    while (str[i] == ' ' || str[i] == '\t')
        i++;

    // Verificar se há um sinal no início
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (str[i] == '+')
    {
        i++;
    }

    // Converter a string para número na base
    while (str[i] != '\0')
    {
        int value = ft_char_to_value(str[i], base);
        if (value == -1) // Se o caractere não for válido na base
            return 0;

        result = result * base_len + value;
        i++;
    }

    return result * sign;
}
int main()
{
    char *str1 = "101010";
    char *base1 = "01"; // Base binária
    printf("Resultado: %d\n", ft_atoi_base(str1, base1)); // 42 (binário 101010)

    char *str2 = "-2A";
    char *base2 = "0123456789ABCDEF"; // Base hexadecimal
    printf("Resultado: %d\n", ft_atoi_base(str2, base2)); // -42 (hexadecimal 2A)

    char *str3 = "  +42";
    char *base3 = "0123456789"; // Base decimal
    printf("Resultado: %d\n", ft_atoi_base(str3, base3)); // 42 (decimal)

    char *str4 = "  ---+--+1234";
    char *base4 = "0123456789"; // Base decimal
    printf("Resultado: %d\n", ft_atoi_base(str4, base4)); // 1234 (decimal)

    return 0;
}