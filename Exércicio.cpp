#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string
		
int registro() //Fun��o respons�vel por cadastrar o usu�rio
{
	// in�cio cria��o de vari�vel/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
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
	char cpf[40];
    char conteudo[100];
	
    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);
  	
    FILE *file;
    file = fopen(cpf,"r");
  	
    if(file == NULL)
{
	printf("N�oo foi poss�vel abrir o arquivo, n�o localizado!.\n");
}
	
    while(fgets(conteudo, 100, file) != NULL)
{
	printf("\nEssas s�o as informa��es do usu�rio: ");
	printf("%s", conteudo);
	printf("\n\n");
}
  	
    system ("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
    {
    	printf("O us�rio nao se encontra no sistema! \n");
    	system("pause");
	}
}


	
int main()
{
	int opcao=0; 
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
	    system("cls");
	    for(laco=1;laco=1;)
	    {

		     system("cls");

		     setlocale(LC_ALL, "Portuguese"); 
			
		     printf("### Cart�rio da EBAC ###\n\n"); 
		     printf("Escolha a op��o desejada do menu\n\n");
		     printf("\t1 - Registrar nomes\n");
		     printf("\t2 - Consultar nomes\n");
	         printf("\t3 - Deletar nomes\n\n");
		     printf("\t4 - Encerrar o programa\n\n"); 
		     printf("Op��o: ");//fim do menu
				
		     scanf("%d", &opcao); 
		
		    system("cls");
	
		    switch(opcao) 
		    {
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
		
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Sistema finalizado. \n");
			return 0;
			break;
		
			default:
			printf("Essa opção não está disponivel!\n");
			system("pause");
			break;
	    	} 
			
        }	
    }
    
    else
        printf("Senha Incorreta!");
}
