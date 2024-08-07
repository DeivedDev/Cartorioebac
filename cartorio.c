#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria 
#include <locale.h> //Bibliotecas de aloca��es de texto por regi�o
#include <string.h> //Bibliotecas respons�vel por cuidar das string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//Inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cra��o das vari�veis/string
	
	printf("Digite o CPF a ser Cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,","); //Salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coleta informa��o do usu�rio
	scanf("%s",nome); //%s refere-se a string
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
		
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}
	
int consulta()
{
	setlocale(LC_ALL, "portuguese"); //Define a linguegem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%S",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");//cria o arquivo e o "r" significa ler
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}
	
int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL);
	{
		printf("O usu�rio n�o se encontra no sistema !.\n");
		system("pause");
	}		
	
}


int main()
	{
	int opcao=0; //Definindo as vari�veis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	setlocale(LC_ALL, "portuguese");
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
		system ("cls");
		for(laco=1;laco=1;)
		{
	
			setlocale(LC_ALL, "portuguese"); //Definindo a libguegem
		
			printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu
			printf("Escolha a op��o desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Concultar nomes\n");
			printf("\t3 - Deletar nomes\n\n");
			printf("\t4 - sair do sistema\n\n");
				printf("op��o "); //Fim do menu
		
			scanf("%d",&opcao); //Armazenando a escolha do usu�rio
		
			system("cls");
		
			switch(opcao) //Inicio da sele��o do menu
			{
				case 1:
				registro(); //chamada de fun��es
				break;
			
				case 2:
				consulta();
				break;
			
				case 3:
				deletar();
				break;
			
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
				
				default:
				printf("Essa op��o n�o est� dispon�vel!\n");
				system("pause");
				break;
				
			} //Fim da sele��o do menu
		
		}	
	
	}
	else
		printf("Senha incorreta!");
	
}
