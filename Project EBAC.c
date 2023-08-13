#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string
#include <stdbool.h> //Ela é responsável por definir o tipo de dado "bool"
		
int registro() //Funcao responsavel por cadastrar os usuarios no sistema 
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
    
    //inicio criacao de variaveis 
    char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); //%s refere-se a armazenar string 
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "W" tem o significo de write 
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,"\n");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\n");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\n");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	

    file = fopen(arquivo, "a");
	fprintf(file,"\n");
	fclose(file);
	
    system("pause");

}

int consulta()
{
	char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);

    FILE *file;
    file = fopen(cpf, "r"); // responsavel pelo comando de read 

    if (file == NULL)
    {
        printf("Não foi possivel abrir o arquivo, não localizado!.\n");
    }

    printf("\nEssas são as informações do usuário: ");
	while (fgets(conteudo, 200, file) != NULL)
    {
        printf("%s", conteudo);
        printf("\n\n");
    }
	system("pause");
    
}

bool confirmacao()
{
    char resposta;
    printf("Deseja prosseguir com o cancelamento do CPF? (S/N): ");
    scanf(" %c", &resposta);
    return resposta == 'S' || resposta == 's';
}

int deletar()
{
    char cpf[40];

    printf("Digite o CPF a ser deletado: ");
    scanf("%s", cpf);

    if (confirmacao())
    {
        if (remove(cpf) == 0)
        {
            printf("O CPF foi removido do sistema.\n");
        }
        else
        {
            printf("Ocorreu um erro ao remover o CPF do sistema.\n");
        }
    }
    else
    {
        printf("O cancelamento do CPF foi cancelado pelo usuário.\n");
    }
}
	
int main()
	{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{

		system("cls");// responsavel por limpar a tela 

		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
			
		printf("### Cartório da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a opção desejada do menu\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção: ");//fim do menu
				
		scanf("%d", &opcao); //armazenando a escolha do usuário
		
		system("cls");
	
		switch(opcao) //inicio da seleção
		{
			case 1:
			registro(); // chamada de funcoes 
			break;
			
			case 2:
			consulta();
			break;
		
			case 3:
			deletar();
			break;
		
			default:
			printf("Essa opção não está disponivel!\n");
			system("pause");
			break;
		} //fim da seleção
			
	}	
}
