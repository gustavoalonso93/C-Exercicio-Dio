#include <stdio.h>
#include <string.h>
#define MAX 1000


int main()
{
int var;
printf("Entre com o valor Decimal: ");
scanf("%d",&var);  

printf("Conversao para Binario: ");
FunBin(var);
printf("Conversao decimal para Hexadecimal: ");
FunHex(var);
printf("Conversao decimal para Octal: ");
FunOctal(var);

return 1;
}

void FunBin(int _var) {
    int resto;
    int binario[32]; 
    int i = 0;
    
    if (_var == 0) {
        printf("0");
        return;
    }
    
    while (_var > 0) {
        resto = _var % 2;
        binario[i] = resto;
        _var = _var / 2;
        i++;
    }
    
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binario[j]);
    }
    printf("\n");
}

void FunHex(int _var) {
    char hexadecimal[32];
    int indice = 0;

    if (_var == 0) {
        printf("0");
        return;
    }
 
    while (_var > 0) {
        int resto = _var % 16;
        if (resto < 10)
            hexadecimal[indice] = resto + '0';  
        else
            hexadecimal[indice] = resto - 10 + 'A';  
        _var = _var / 16;
        indice++;
    }
    hexadecimal[indice] = '\0';

    int tamanho = indice;
    for (int i = 0; i < tamanho / 2; i++) {
        char temp = hexadecimal[i];
        hexadecimal[i] = hexadecimal[tamanho - i - 1];
        hexadecimal[tamanho - i - 1] = temp;
    }

    printf("%s", hexadecimal);
    printf("\n");
}

void FunOctal(int _var) {
    char octal[32];
    int indice = 0;

    if (_var == 0) {
        printf("0");
        return;
    }

    while (_var > 0) {
        int resto = _var % 8;
        octal[indice] = resto + '0';
        _var = _var / 8;
        indice++;
    }
    octal[indice] = '\0';

    int tamanho = indice;
    for (int i = 0; i < tamanho / 2; i++) {
        char temp = octal[i];
        octal[i] = octal[tamanho - i - 1];
        octal[tamanho - i - 1] = temp;
    }

    printf("%s", octal);
    printf("\n");
}
