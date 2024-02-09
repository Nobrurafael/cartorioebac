 #include <stdio.h> //biblioteca de comunicaçao com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsavel por cadastrar os usuários no sistema
{
	//inido criação de variáveis/string
	
   char arquivo[40];
   char cpf[40];
   char nome[40];
   char sobrenome[40];
   char cargo[40];
   //final da criaçao de variáveis/string
   
   printf("digite o cpf a ser cadastrado:");//coletando informaçao do usuario
   scanf("%s", cpf); //%s refere-se a string
   
   strcpy(arquivo, cpf); // responsavel por copiar os valores das string
   
   FILE *file; //cria o arquivo 
   file = fopen(arquivo, "w"); //cria o aruivo e o "w" significa escrever
   fprintf(file,cpf); // salvo o valor da variavel
   fclose(file); // fecha o arquivo
   
   file = fopen(arquivo, "a");
   fprintf(file, ",");
   fclose(file);
   
   printf("digite o nome a ser cadastrado: ");
   scanf("%s",nome);
   
   file = fopen(arquivo, "a");
   fprintf(file,nome);
   fclose(file);
   
   file = fopen(arquivo, "a");
   fprintf(file, ",");
   fclose(file);
   
   printf("digite o sobrenome a ser cadastrado: ");
   scanf("%s",sobrenome);
   
   file = fopen(arquivo, "a");
   fprintf(file,sobrenome);
   fclose(file);
   
   file = fopen(arquivo, "a");
   fprintf(file,",");
   fclose(file);
   
   printf("digite o cargo a ser cadastrado:");
   scanf("%s",cargo);
   
   file = fopen(arquivo, "a");
   fprintf(file,cargo);
   fclose(file);
   
   system("pause");
     
}


int consulta()
{
	setlocale(LC_ALL, "portuguese"); //definindo a linguagem
	
    char cpf[40];
    char conteudo[20];
    
    printf("digite o cpf a ser coonsultado");
    scanf("%s",cpf);
    
    FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("nao foi possivel abrir o arquivo, nao localizado!\n");
		
	} 
	
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\Essas sao as informações do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
		
		system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("digite o cpf do usuario a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("o usuario não se encontra no sistema!.\n");
		system("pause");
	}
	
}




int main()
{
	int opcao=0; //definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	   system ("cls");
	
	   setlocale(LC_ALL, "portuguese"); //definindo a linguagem
	   
	   printf("###seja bem vindo ao cartório da ebac###\n\n"); //inicio do menu
	   printf("por favor, escolha uma das opçoes abaixo:\n\n");
	   printf("\t1 - registrar nomes\n");
	   printf("\t2 - consultar nomes\n");
	   printf("\t3 - deletar nomes\n\n\n");
	   printf("\t4 - Sair do sistema\n\n");
	   printf("opçao: ");//fim do menu
	  
       scanf("%d", &opcao); //armazenando escolha do usuario

       system("cls"); //responsavel por limpar a tela

       
       switch(opcao) // inicio da seleção do menu
       {
       	    case 1:
       		registro();// chamada de funções
       		break;
       		
       		case 2:
       		consulta();
       		break;
       			
       			
       		case 3:
       		deletar();
       		break;
       		
       		case 4:
       		printf("obrigado por utilizar o sistema!\n");
			return 0;
			break;
       		
       		default:
       		printf("essa opção não está disponivel!\n");
       		system("pause");
       		break;
            
			}
        
	   
		}
		
	}    


   
      


