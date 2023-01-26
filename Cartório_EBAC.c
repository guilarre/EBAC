#include <stdio.h> //biblioteca de comunicação com o user
#include <stdlib.h> //biblio pra alocar espaço de memória
#include <locale.h> //biblio de alocação de texto por região (acentos etc.)
#include <string.h> //biblio das strings

int registro() //função para cadastro de usuários no sistema
{
    //início da criação de variáveis (strings)
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("Você escolheu o cadastro de nomes!\n\n");
    printf("Digite o CPF para cadastro:\n"); //coletando info do usuário
    scanf("%s", cpf); //%s = string

    strcpy(arquivo, cpf); //copia o valor de uma string para a outra

    FILE *file; //comando FILE declarando um apontador de tipo file
    file = fopen(arquivo, "w"); //cria o arquivo na pasta do codigo
    fprintf(file, cpf); //fprintf printa e salva DENTRO do arquivo
    fclose(file);

    file = fopen(arquivo, "a"); //NAO usamos W pq nao estamos criando um novo, estamos atualizando o arquivo. (append)
    fprintf(file, ","); //adicionando separador antes do prox. item
    fclose(file);

    printf("Digite o nome para cadastro:\n"); //prompt pra pegar proximo item p/ cadastro...
    scanf("%s", nome);
    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fprintf(file, ",");
    fclose(file);

    printf("Digite o sobrenome para cadastro:\n");
    scanf("%s", sobrenome);
    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fprintf(file, ",");
    fclose(file);

    printf("Digite o cargo para cadastro:\n");
    scanf("%s", cargo);
    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);

    printf("O cadastro foi finalizado!\n\n");

    system("pause");
}

int consulta()
{
    setlocale(LC_ALL, "Portuguese");
    char cpf[40];
    char conteudo[200];

    printf("Você escolheu a consulta de nomes!\n\n");
    printf("Digite o CPF de quem você deseja consultar: ");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r"); //procurar pela primary key (cpf)

    if(file == NULL)
    {
        printf("Não foi possível abrir o arquivo, pois não foi localizado.\n");
    }

    while(fgets(conteudo, 200, file) != NULL)  //200 eh o delimitador de tamanho (igual à var. conteudo) ## roda enquanto nao ta nulo (arquivo nao acabou)
    {
        printf("\nEstas são as informações do usuário: ");
        printf("%s", conteudo);
        printf("\n\n");
    }

    system("pause");
}

int deletar()
{
    printf("Você escolheu deletar um nome!\n\n");

    char cpf[40]; //string pq vamos passar mais de um valor p ele; o tipo 'char' tb pode receber numeros e eh bom pra gerenciamento de strings
    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s", cpf);

    if(remove(cpf) == 0)
    {
        printf("O usuário foi deletado com sucesso!\n\n");
        system("pause");
    }
    else
    {
        printf("O usuário deste CPF não se encontra no sistema!\n\n");
        system("pause");
    }
    return 0;

    //failsafe?
}

int main()
{
    int opcao=0; //definindo uma variável local (só dispon. dentro da função main)
    int x=1;

    for(x=1;x=1;) //'macete' que serve pra fazer um laço infinito (inicia qnd x=1, enquanto x=1 e não precisa de incremento)
    {
        system("cls"); //cls = clear screen
        setlocale(LC_ALL, "Portuguese");

        printf("### Cartório da EBAC (Menu principal) ###\n\n");
        printf("Escolha a opção desejada:\n\n");
        printf("\t1 - Cadastrar nome\n");
        printf("\t2 - Consultar nome\n");
        printf("\t3 - Deletar nome\n");
        printf("\t4 - Sair do sistema\n\n");
        printf("Opção: \n\n");//fim do menu

        scanf("%d", &opcao); //pra pegar o input do usuario e colocar dentro de opcao (%d é pra colocar como integer)

        system("cls"); //pra limpar a tela (system = os do python)

        switch(opcao) //chamada das funções
        {
            case 1:
                registro();
                break; //tem que ter em switch/case, pra não sair rodando todos os casos seguintes
            case 2:
                consulta();
                break;
            case 3:
                deletar();
                break;
            case 4:
                printf("Obrigado por utilizar o sistema!\n");
                return 0; //retorna 0, quebra o loop e fecha
                break;
            default:
                printf("Você escolheu uma opção inválida\n\n");
                system("pause");
        }
    }
}