#include <stdio.h>// biblioteca de comunica��o com o usuario 
#include <stdlib.h>//biblioteca de aloca��o de espa�o e memoria
#include <locale.h>//biblioteca de texto por regi�o
#include <string.h>//biblioteca reponsavel por cuidar das strings

int registro() // fun��o de registrar os usuarios no sistema
{
	//inicio da variavel/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da variavel/string
	
	printf("digite o CPF a ser consultado:   ");  // coletando as informa��es dos usarios
	scanf("%s", cpf); // refere-se as string
	
	strcpy( arquivo, cpf); // responsavel por copiar os valores das strings
	
	FILE *file; // cria arquivo
	file = fopen(arquivo, "w"); //cria arquivo
	fprintf(file,cpf); // salvar o valor da variavel
	fclose(file); //fecha oarquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file); 
	
	
	printf("digite o nome a ser cadastrado:  ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file); 
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file); 
	
	printf("digite o sobrenome a ser cadastrado:  ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file); 
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file); 
	
	
	printf("digite o cargo a ser cadastrado:  ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file); 
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "portuguese");//definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("digite o cpf a ser conultado:  ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("n�o foi possivel abrir o arquivo, n�o localizado \n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\nEssas s�o as informa��es do usuario:  ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	
}

int deletar()
{
	char cpf[40];
	
	printf("digite o cpf a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE*file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("o usu�rio n�o se encontra no sistema!\n");
		system("pause");
			
	}
	
	
	
}

	
	


int main()
   {
   
    int opcao=0; //definindo variaveis
	int x=1;
	char senhadigitada[10]= "a";
	int comparacao;
	
	printf("    cartorio da EBAC    \n\n");
	printf("login do administrador\n\n digite a sua senha:  ");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
   {
	system("cls");
	  for(x=1;x=1;)
 	  {
	   
	      system("cls");
	  
	      setlocale(LC_ALL, "portuguese");//definindo a linguagem
	 
	       printf("    cartorio da EBAC    \n\n");//inicia o menu
	       printf("Escolha  a op��o desejada do menu:\n\n");
	       printf("\t1 - registrar nomes\n");
	       printf("\t2 - consultar nomes\n");
	       printf("\t3 - deletar nomes\n");
	       printf("op��o: ");//fim do menu
	 
	       scanf("%d", &opcao);//armazenando a escoolha do usuario
	
	       system("cls");//inicio da sele��o, "cls" � responsavel por limpa a tela
	
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
	         
			 default:
		     printf("essa op��o n�o esta disponivel\n");
	 	     system("pause");
		     break;	
	        
			} 
		}
    
	}  
	  
	  else
	  printf("senha incorreta");


}
