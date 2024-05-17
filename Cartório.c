#include <stdio.h> 
#include <stdlib.h> 
#include <locale.h> 
#include <string.h>

int registro(){
//Definindo variáveis
	setlocale(LC_ALL, "Portuguese"); 
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	int decisao=0;
	
//Coletando informação do usuário	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s" , cpf);
	strcpy(arquivo, cpf);
//ARQUIVO BANCO DE DADOS
	FILE*file;
	file = fopen(arquivo, "w");
	fprintf(file,cpf);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
//Coletando informação do usuário e atualizando arquivo	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fprintf(file, " ");
	fclose(file);
//Coletando informação do usuário e atualizando arquivo		
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fprintf(file, ",");
	fclose(file);
//Coletando informação do usuário e atualizando arquivo		
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fprintf(file, " ");
	fclose(file);
	printf("\nUsuário registrado com sucesso!!!\n");
	
	
	printf("\nVocê gostaria de registrar mais algum usuário?\n");
	printf("\t1 - SIM\n");
	printf("\t2 - NÃO E SAIR DO SISTEMA\n");
	printf("\t3 - VOLTAR PARA O MENU\n");
	scanf("%d", &decisao);
	
	system("cls");
	
	switch(decisao){
		case 1:
		registro();
		break;
		
		case 2:
		printf("\nObrigado por utilizar o sistema!!!\n");
		exit (0);
		break;
		
		case 3:
		tudo2();
		break;
		
		default:
			
		printf("Por favor digite uma opção válida!!!\n");
		registro();
		system("pause");
		break;
	    }
	
	system("cls");	
}

int consulta(){
	setlocale(LC_ALL, "Portuguese"); 
//Definindo variáveis
	char cpf[40]; 
	char conteudo[200];
	int cons=0;
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
//Coletando informação do usuário e lendo o arquivo	
	FILE*file;
	file=fopen(cpf,"r");
	
	if(file == NULL){
		printf("Não foi possível localizar o CPF.\n");
	}
	
	while(fgets(conteudo,200, file)!= NULL){
		printf("\nEssas são as Informações do usuário: ");
		printf("%s",conteudo);
 		printf("\n");
	}
	
	printf("\nVocê gostaria de consultar mais algum usuário?\n");
	printf("\t1 - SIM\n");
	printf("\t2 - NÃO E SAIR DO SISTEMA\n");
	printf("\t3 - VOLTAR PARA O MENU\n");
	scanf("%d", &cons);
		
	system("cls");
	
		switch(cons){
		case 1:
		consulta();
		break;
		
		case 2:
		printf("\nObrigado por utilizar o sistema!!!\n");
		exit (0);
		break;
		
		case 3:
		tudo2();
		break;
		
		default:
			
		printf("Por favor digite uma opção válida!!!\n");
		system("pause");
		consulta();
		break;
	    }
	    
		system("pause");
}

int deletar(){
//Definindo variáveis
	char cpf[40];
	int del=0;
//Coletando informação do usuário e removendo arquivo	
	printf("Digite o CPF do usuário a ser deletado: \n");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE*file;
	file = fopen(cpf,"r");
	
	if (file==NULL){
		printf("\nO Usuário não foi encontrado no sistema\n");
	}
	
	printf("\nVocê gostaria de deletar mais algum usuário?\n");
	printf("\t1 - SIM\n");
	printf("\t2 - NÃO E SAIR DO SISTEMA\n");
	printf("\t3 - VOLTAR PARA O MENU\n");
	scanf("%d", &del);
		
	system("cls");
	
	switch(del){
		case 1:
		deletar();
		break;
		
		case 2:
		printf("\nObrigado por utilizar o sistema!!!\n");
		exit (0);
		break;
		
		case 3:
		tudo2();
		break;
		
		default:
			
		printf("Por favor digite uma opção válida!!!\n");
		deletar();
		system("pause");
		break;
	    }
	    
}

int acesso(){
//Definindo variáveis
    char login[15] = "admin";
    char login1[15];
    char senha[15] = "admin";
    char senha1[15];        
    int login_efetuado = 0;

    while(!login_efetuado){
        printf("Digite o Login: ");
        scanf("%s", login1);

        printf("Digite a Senha: ");
        scanf("%s", senha1);
//Comparação de senha e login do administrador
        if (strcmp(login, login1) == 0 && strcmp(senha, senha1) == 0){
            printf("\nLogado com sucesso!!!\n\n");
            login_efetuado = 1;
            system("pause");
            tudo2();
        }
        else
            printf("\n\nDados Incorretos!!!\n\n");    
    }

}

int main(){	
	acesso();
}
int tudo2(){
		
//Definindo variáveis
	int opcao=0; 
	int laco=1;
	
	for(laco=1;laco=1;){
	
	system("cls");
//Linguagem
	setlocale(LC_ALL, "Portuguese"); 
//Inicia do menu	
	printf("### Cartório da EBAC ###\n\n"); 
	printf("Escolha a opção desejada do menu:\n\n");
	printf("\t1 - Registrar Nomes\n");
	printf("\t2 - Consultar Nomes\n");
	printf("\t3 - Deletar Nomes\n"); 
	printf("\n\t4 - Sair do sistema\n");
	printf("Opção:");
	
	scanf("%d", &opcao);
//Armazenando escolha do usuario
//Fim do menu
	system("cls");
//inicio da seleção e chamada de funções
	switch(opcao){
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
		printf("Obrigado por utilizar o sistema!!!\n");
		exit (0);
		break;
		
		default:
			
		printf("Por favor digite uma opção válida!!!\n");
		system("pause");
		break;
	    }
//Final da seleção
	}
}
