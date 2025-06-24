#include <stdio.h>

struct {
    char nomeAluno[100];
    int idadeAluno;
    double nota1Aluno;
    double nota2Aluno;
    double mediaAluno;
} infoAlunos[5];

int main() {
    FILE *arquivo;
    int i;


    for (i = 0; i < 5; i++) {
        printf("--- INFORMAÇÕES DO ALUNO %d ---\n", i + 1);

        printf("Digite o nome do aluno:\n");
        scanf("%s", infoAlunos[i].nomeAluno);

        printf("Digite a idade do aluno:\n");
        scanf("%d", &infoAlunos[i].idadeAluno);

        printf("Digite a nota do 1EE do aluno:\n");
        scanf("%lf", &infoAlunos[i].nota1Aluno);

        printf("Digite a nota do 2EE do aluno:\n");
        scanf("%lf", &infoAlunos[i].nota2Aluno);

        infoAlunos[i].mediaAluno = (infoAlunos[i].nota1Aluno + infoAlunos[i].nota2Aluno) / 2;
    }


    arquivo = fopen("alunos.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return 1;
    }


    for (i = 0; i < 5; i++) {
        fprintf(arquivo, "%s %d %.2lf %.2lf %.2lf\n",
                infoAlunos[i].nomeAluno,
                infoAlunos[i].idadeAluno,
                infoAlunos[i].nota1Aluno,
                infoAlunos[i].nota2Aluno,
                infoAlunos[i].mediaAluno);
    }

    fclose(arquivo);


    arquivo = fopen("alunos.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return 1;
    }

    printf("\n--- DADOS LIDOS DO ARQUIVO ---\n");

    for (i = 0; i < 5; i++) {
        fscanf(arquivo, "%s %d %lf %lf %lf",
               infoAlunos[i].nomeAluno,
               &infoAlunos[i].idadeAluno,
               &infoAlunos[i].nota1Aluno,
               &infoAlunos[i].nota2Aluno,
               &infoAlunos[i].mediaAluno);

        printf("\n--- Aluno %d ---\n", i + 1);
        printf("Nome: %s\n", infoAlunos[i].nomeAluno);
        printf("Idade: %d\n", infoAlunos[i].idadeAluno);
        printf("Nota 1: %.2lf\n", infoAlunos[i].nota1Aluno);
        printf("Nota 2: %.2lf\n", infoAlunos[i].nota2Aluno);
        printf("Média: %.2lf\n", infoAlunos[i].mediaAluno);
    }

    fclose(arquivo);

    return 0;
}
