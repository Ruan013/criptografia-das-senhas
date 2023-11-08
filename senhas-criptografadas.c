#include <stdio.h>
#include <stdlib.h>

int main() {
    system("color 0F");

    char chave[100] = "#modalGR#GPTW#top#maiorEmpresaTecnologia#baixadaSantista";
    char digitoChave[100];
    char mostrarSenha1[100];
    char mostrarSenha2[100];
    char mostrarSenha3[100];

    inicio:
    printf ("##################################");
    printf("\n\n");
    printf ("      CRIPTOGRAFIA DAS SENHAS     ");
    printf ("\n\n");
    printf ("##################################");
    printf ("\n\n");

    // SENHA 1  CIFRA DE CÉSAR
    char senha1[100];
    int deslocamento = 10;

    printf("Digite a primeira senha: ");
    fgets(senha1, sizeof(senha1), stdin);

    for (int i = 0; senha1[i] != '\0'; i++) {
        char caractere = senha1[i];

        // Verificação se o caractere é uma letra minúscula
        if (caractere >= 'a' && caractere <= 'z') {
            senha1[i] = 'a' + (caractere - 'a' + deslocamento) % 26;
        }
        // Verificação se o caractere é uma letra maiúscula
        else if (caractere >= 'A' && caractere <= 'Z') {
            senha1[i] = 'A' + (caractere - 'A' + deslocamento) % 26;
        }
    }
    FILE *fileSenha1;
    fileSenha1 =fopen("senha1.txt", "w");
    fprintf (fileSenha1, "SENHA - 1: %s\n", senha1);
    fclose (fileSenha1);

    // SENHA 2  SUBSTITUIÇÃO SIMPLES
    char senha2[100];
    char tabela_substituicao[26] = "@CDEF#HI+KL&N*O?Q!ST%VWX9Z";  // Tabela de substituição

    printf("Digite a segunda senha: ");
    fgets(senha2, sizeof(senha2), stdin);

    // Criptografar a senha 2 usando a Cifra de Substituição Simples
    for (int i = 0; senha2[i] != '\0'; i++) {
        char caractere = senha2[i];

        if (caractere >= 'A' && caractere <= 'Z') {
            senha2[i] = tabela_substituicao[caractere - 'A'];
        } else if (caractere >= 'a' && caractere <= 'z') {
            senha2[i] = tabela_substituicao[caractere - 'a'];
        }
    }

    FILE *fileSenha2;
    fileSenha2 =fopen("senha2.txt", "w");
    fprintf (fileSenha2, "SENHA - 2: %s\n", senha2);
    fclose (fileSenha2);


    //SENHA 3  CIFRA DE BLOCO INVERTIDO
    char senha3[100];

    printf("Digite a terceira senha: ");
    fgets(senha3, sizeof(senha3), stdin);

    senha3[strcspn(senha3, "\n")] = '\0'; // Remova o caractere de nova linha

    int tamanho = strlen(senha3);

    // Inverta o bloco de senha
    for (int i = 0; i < tamanho / 2; i++) {
    char temp = senha3[i];
    senha3[i] = senha3[tamanho - i - 1];
    senha3[tamanho - i - 1] = temp;
    }

    FILE *fileSenha3;
    fileSenha3 =fopen("senha3.txt", "w");
    fprintf (fileSenha3, "SENHA - 3: %s\n", senha3);
    fclose (fileSenha3);

    printf ("\n");

    printf ("\nDigite a chave para acessar as senhas criptografadas: ");
    scanf ("%s", &digitoChave);

    if (strcmp(digitoChave, chave) == 0) {
        goto senhas;
    } else {
        goto inicio;
    }

    senhas:
    printf("\nSENHAS CRIPTOGRAFADAS\n\n");

    //SENHA 1
    FILE *fileMostrarSenha1;
    fileMostrarSenha1 = fopen("senha1.txt", "r");

    if (fileMostrarSenha1 == NULL) {
    printf("Erro ao abrir o arquivo da senha 1.\n");
    return 1; // Indica um erro
    }
    while (fscanf(fileMostrarSenha1, "%99[^\n]", mostrarSenha1) == 1) {
    printf("%s\n", mostrarSenha1);
    }
    fclose(fileMostrarSenha1);
    printf("\n\n");

    //SENHA 2
    FILE *fileMostrarSenha2;
    fileMostrarSenha2 = fopen("senha2.txt", "r");

    if (fileMostrarSenha2 == NULL) {
    printf("Erro ao abrir o arquivo da senha 2.\n");
    return 1; // Indica um erro
    }
    while (fscanf(fileMostrarSenha2, "%99[^\n]", mostrarSenha2) == 1) {
    printf("%s\n", mostrarSenha2);
    }
    fclose(fileMostrarSenha2);
    printf("\n\n");

    //SENHA 3
    FILE *fileMostrarSenha3;
    fileMostrarSenha3 = fopen("senha3.txt", "r");

    if (fileMostrarSenha3 == NULL) {
    printf("Erro ao abrir o arquivo da senha 3.\n");
    return 1; // Indica um erro
    }
    while (fscanf(fileMostrarSenha3, "%99[^\n]", mostrarSenha3) == 1) {
    printf("%s\n", mostrarSenha3);
    }
    fclose(fileMostrarSenha3);
    printf("\n");
    system("pause");


return 0;
}
