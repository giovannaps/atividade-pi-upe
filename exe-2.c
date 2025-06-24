#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arquivo;
    char texto[1000];
    int contador = 0;
    char caractere;

    arquivo = fopen("texto.txt", "w+");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    printf("Digite um texto:\n");
    fgets(texto, sizeof(texto), stdin);

    fputs(texto, arquivo);

    rewind(arquivo);

    while ((caractere = fgetc(arquivo)) != EOF) {
        if ((caractere >= 'A' && caractere <= 'Z') || (caractere >= 'a' && caractere <= 'z')) {
            contador++;
        }
    }

    printf("O arquivo possui %d letras.\n", contador);

    fclose(arquivo);

    return 0;
}
