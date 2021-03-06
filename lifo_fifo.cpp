#include <iostream>
#include<stdlib.h>
#include "locale.h"

/*Criar uma Pilha(LIFO) e uma Fila(FIFO) em C*/

struct filasimples
{
	int informacao;
	struct filasimples * proximo;
};
struct filasimples * raiz;

void inserir()
{
	int num;
	struct filasimples *r;
	r = (struct filasimples *)malloc(sizeof(struct filasimples));
	if (!r)
	{
		printf("estouro de memória \n");
		system("pause");
		return;
	}
	printf("Digite um número: ");
	scanf("%d", &num);
	r->informacao = num;
	r->proximo = raiz;
	raiz = r;
}
/*FIFO => primeiro a entrar, primeiro a sair*/
void remover_primeiro()
{
	struct filasimples *r, *p;
	if (raiz == NULL)
	{
		printf("Fila vazia\n");
		system("pause");
		return;
	}
	r = raiz;
	while (r->proximo != NULL)
	{
		p = r;
		r = r->proximo;
	}
	if(r==raiz)
	{
		raiz=NULL;
		printf("O número %d foi removido.\n", r->informacao);
		free(r);
	} else {
		printf("O número %d foi removido.\n", r->informacao);
		free(r);
		p->proximo=NULL;
	}
}
/*LIFO=> ultimo a entrar, primeiro a sair*/
void remover_ultimo()
{
	struct filasimples *r;
	if (raiz == NULL)
	{
		printf("Fila vazia\n");
		system("pause");
		return;
	}
	r = raiz;
	raiz=r->proximo;
	printf("O número %d foi removido.\n", r->informacao);
	free(r);
}
void mostrar()
{
	struct filasimples *r;
	r = raiz;
	printf("	FILA\n");
	while (r != NULL)
	{
		printf("%d \n", r->informacao);
		r = r->proximo;
	}
}
int main()
{
	setlocale(LC_ALL, "Portuguese");
	int opcao;
	raiz = NULL;
	do
	{
		printf("\n0 - Sair\n");
		printf("1 - Inserir Elemento\n");
		printf("2 - Mostrar Elementos\n");
		printf("3 - Remover LIFO\n");
		printf("4 - Remover FIFO\n");
		scanf("%d", &opcao);
		printf("\n");
		switch (opcao)
		{
		case 0:
			system("cls");
			break;
		case 1:
			inserir();
			system("cls");
			break;
		case 2:
			mostrar();
			break;
		case 3:
			remover_ultimo();
			printf("Remover último número digitado\n");
			break;
		case 4:
			remover_primeiro();
			break;
		default:
			printf("Opção invalida\n");
			break;
		}
	} while (opcao != 0);
	system("pause");
	return 0;
}
