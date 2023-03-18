#include <stdio.h>
#include <string.h>
#include <locale.h>

	struct ESTUDANTE
	{
		int 	matricula;
		char 	nome[65];
		char 	curso[35];
		char 	endereco[65];
		char	email[35];
		int 	colocacao;
		float 	media_vestibular;
	};
	struct ESTUDANTE vet_estud[500];
	
cadastrar(int ale)
{
		printf("Matricula: ");
		scanf("%d", &vet_estud[ale].matricula);
		fflush(stdin);
		
		printf("Nome: ");
		gets(vet_estud[ale].nome);
		
		printf("Endereço: ");
		gets(vet_estud[ale].endereco);
	
		printf("Curso: ");
		gets(vet_estud[ale].curso);
		
		printf("E-mail: ");
		gets(vet_estud[ale].email);
		fflush(stdin);
			
		printf("Média-vestibular: ");
		scanf("%f", &vet_estud[ale].media_vestibular);
		fflush(stdin);
		
		printf("Colocação: ");
		scanf("%d", &vet_estud[ale].colocacao);
		fflush(stdin);
}

consultar()
{
	int i,matricula_aux;
	char encontrou = 'N';
	
	printf("Forneça a matricula para verificação: ");
	fflush(stdin);
	scanf("%d", &matricula_aux);
	
	for (i = 0; i < 500; i++)
	{
		if(matricula_aux == vet_estud[i].matricula)
		{
			encontrou = 'S';
			printf("\n\n");
			printf("\nMatricula.............: %d", vet_estud[i].matricula);
			printf("\nNome..................: %s", vet_estud[i].nome);
			printf("\nEndereço..............: %s", vet_estud[i].endereco);
			printf("\nCurso.................: %s", vet_estud[i].curso);
			printf("\nEmail.................: %s", vet_estud[i].email);
			printf("\nMédia Vestibular......: %f", vet_estud[i].media_vestibular);
			printf("\nColocação.............: %d", vet_estud[i].colocacao);
			getch();
		}
	}
	if(encontrou == 'N')
	{
		printf("Nao existe essa matricula!!!");
		getch();
	}
}


alterar()
{
	int i,matricula_aux;
	char encontrou = 'N';
 		
	printf("Forneça a matricula que deseja alterar: ");
	fflush(stdin);
	scanf("%d", &matricula_aux);
	
	for (i = 0; i < 500; i++)
	{
		if(matricula_aux == vet_estud[i].matricula)
		{
			encontrou = 'S';
			printf("\n\n");
			fflush(stdin);
			
			printf("Nome: ");
			gets(vet_estud[i].nome);
			
			printf("Endereço: ");
			gets(vet_estud[i].endereco);
			
			printf("Curso: ");
			gets(vet_estud[i].curso);
			
			printf("E-mail: ");
			gets(vet_estud[i].email);
			fflush(stdin);
				
			printf("Média-vestibular: ");
			scanf("%f", &vet_estud[i].media_vestibular);
			fflush(stdin);
			
			printf("Colocação: ");
			scanf("%d", &vet_estud[i].colocacao);
			fflush(stdin);
		}
	}
	if(encontrou == 'N')
	{
		printf("Nao achou");
		getch();
	}
}

excluir(int ale)
{
	
	int i,matricula_aux,y,indice_aux;
	char encontrou = 'N';
 		
	printf("Forneça a matricula que deseja excluir: ");
	fflush(stdin);
	scanf("%d", &matricula_aux);
	
	for (i = 0; i < 500; i++)
	{
		if(matricula_aux == vet_estud[i].matricula)
		{
			encontrou = 'S';
			indice_aux = i;
		}
	}
	if(encontrou == 'N')
	{
		printf("Nao achou");
		getch();
	}
	else
	{
		for (y = indice_aux; y < 500; y++)
		{
			if((y + 1) < 500)
			{
				vet_estud[y].matricula = vet_estud[y+1].matricula;
				strcpy(vet_estud[y].nome , vet_estud[y+1].nome);
				//vet_estud[y].nome = vet_estud[y+1].nome;
				strcpy(vet_estud[y].endereco , vet_estud[y+1].endereco);
				//vet_estud[y].endereco = vet_estud[y+1].endereco;
				strcpy(vet_estud[y].curso , vet_estud[y+1].curso);
				//vet_estud[y].curso = vet_estud[y+1].curso;
				strcpy(vet_estud[y].email , vet_estud[y+1].email);
				//vet_estud[y].email = vet_estud[y+1].email;
				vet_estud[y].media_vestibular = vet_estud[y+1].media_vestibular;
				vet_estud[y].colocacao = vet_estud[y+1].colocacao;
			}else{
				vet_estud[y].matricula=0;
				strcpy(vet_estud[y].nome , "");
				//vet_estud[y].nome="";
				strcpy(vet_estud[y].endereco , "");
				//vet_estud[y].endereco="";
				strcpy(vet_estud[y].curso, "");
				//vet_estud[y].curso="";
				strcpy(vet_estud[y].email , "");
				//vet_estud[y].email="";
				vet_estud[y].media_vestibular=0;
				vet_estud[y].colocacao=0;
			}
		}
		ale=ale -1;
	}
}

main()
{
	int ale =-1;
	char opcao;
	do{
		system("cls");
		printf("MENU");
		system("cls");
		setlocale(LC_ALL, "PORTUGUESE");
		printf("1 - Cadastrar........: \n");
		printf("2 - Consultar........: \n");
		printf("3 - Alterar..........: \n");
		printf("4 - Excluir..........: \n");
		printf("5 - SAIR.............: \n");
		printf("\nEntre com sua opção: ");
		scanf("%c", &opcao);
		
		switch (opcao)
		{
			
			case '1':
				ale=ale +1;
				cadastrar(ale);
				break;
			case '2':
				consultar();
				break;
			case '3':
				alterar();
					break;
			case '4':
				excluir(ale);
					break;
			default:
				break;
		}
	}while(opcao != 53);
}
