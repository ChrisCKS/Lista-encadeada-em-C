#include <stdio.h>
#include <stdlib.h>

struct Lista{ //criei um dado tipo No
	int valor;		//possui um valor tipo int
	struct Lista * proximo;	//possui um ponteiro para o elemento No
}typedef Lista;

Lista * novaLista(){
	return NULL;
}
//INSERIR NO INICIO
Lista * Inserir_inicio(Lista * lista, int valor){ //recebe um ponteiro para lista e um valor
	printf("A");
	Lista *novo = (Lista*)malloc(sizeof(Lista)); //MALLOC aloca o espaço suficiente e SIZEOF diz o tamanho do espaço que No precisa, "(No*) indica que o retorno precisa ser do tipo ponteiro
	novo->valor = valor; //a região de memoria apontada por novo na posição valor vai receber o valor que queremos inserir
	novo->proximo = lista;
	printf("Add");
	return novo;
}

//INSERIR NO FIM
Lista * inserirFim(Lista *lista , int valor){
	Lista * novo = (Lista*) malloc(sizeof(Lista));
	Lista * backuplista = lista;
	novo->valor = valor;
	novo->proximo = NULL;
	
	if(lista->proximo== NULL){
		lista->proximo = novo;
	
	}
	else{
		lista = lista->proximo;
		while(lista->proximo != NULL){
			lista = lista->proximo;
		}
		lista->proximo = novo;

	}
	return backuplista;

}


//IMPRIMIR LISTA
void imprimir(Lista *lista){
	Lista * inicio = lista;
	printf("A");
	while(inicio != NULL){
		printf("[%d]->" , inicio->valor);
		inicio = inicio->proximo;	
	}
	printf("\n\n");
}

//BUSCAR NA LISTA
Lista * buscar(Lista *lista , int num){
	Lista *aux ,*lista1 = NULL;
	
	aux = lista;
	if(aux->valor == num){
		return aux;
	}
	while(aux->valor !=num)
		aux = aux->proximo;
	return aux;
}

int getSize(Lista * lista){
	int size = 0;
	while(lista->proximo!=NULL){
		size+=1;
	}
	return size;
}

//TENTATIVA DE DIVIDIR A LISTA, POREM N�O CONSEGUI FINALIZAR

Lista * dividir(Lista * lista, int posicao , int result){
	Lista * lista1 = lista;
	Lista * lista2 = lista;
	int i, item =getSize(lista)-posicao;
  	for(i = 0; i<item; i++){
    	
    	lista=(Lista *) lista->proximo;
    	lista1 = (Lista *) lista->proximo;
	}
	lista->proximo = NULL; 
	if(result==1){
		return lista2;
	}else if(result==0){
		return lista1;
	}
}


//INICIO DA LISTA
int main(){
	Lista * lista;
	lista = novaLista();
	int opcao , valor;
	printf("TESTE");
	do{
		printf("TESTE");
		printf("1 - Inserir no inicio\n2 - Imprimir\n3 - Inserir no fim\n4 - Buscar\5 - Sair\n");
		scanf("%d" , &opcao);
		printf("AAAAAA");
		switch (opcao){
			case 1:
				printf("Digite um valorteste1: ");
				scanf("%d" , &valor);
				lista = Inserir_inicio(lista, valor);
				break;
				case 2:
					printf("2");
					imprimir(lista);
					break;
					case 3:
						printf("Digite um valor3: ");
						scanf("%d" , &valor);
						lista = inserirFim(lista , valor);
						break;
						case 4:
							printf("Digite o valor que procura: ");
							scanf("%d" , &valor);
							Lista * busca;
							busca  = buscar(lista, valor);
							printf("O valor buscado: %d\n" , busca->valor);
							break;
							case 5:
								printf("Finalizando\n");
								break;
			default :
			printf("Opcao invalida\n");
					
		}
				
	}while(opcao !=5);
}
