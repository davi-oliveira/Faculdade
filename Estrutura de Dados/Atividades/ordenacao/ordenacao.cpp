#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h> 
#include <cstdlib>
#include <ctime>

using namespace std;

void manFill(int vetor[], int qtdNum){
	for(int i = 0; i < qtdNum; i++){
		cout << "Digite o " << i+1 << ". valor:";
		cin >> vetor[i];
	}
}

void autoFill(int vetor[], int qtdNum){
	int inicial, final;
	cout << "\nDigite o numero inicial para os valores aleatorios: ";
	cin >> inicial;
	
	cout << "\nDigite o numero final para os valores aleatorios: ";
	cin >> final;
	
	srand (time(NULL));
	
	for(int i = 0; i < qtdNum; i++)
		vetor[i] = (rand()+inicial) % final+1;
	
	cout << "O vetor foi preenchido com sucesso usando valores aleatorios.";
	
}

void clear(int vetor[], int qtdNum){ 
	for(int i = 0; i < qtdNum; i++)
		vetor[i] = 0;	
	
	cout << "O vetor foi limpo com sucesso.";
}

void imprimir(int vetor[], int qtdNum){
	for(int i = 0; i < qtdNum; i++)
		cout << "Elemento " << i+1 << ": " << vetor[i] << "\n";
}

void BubleSort(int vetor[], int qtdNum){
	int aux = 0;
	int operacoes = 0;
	
	for(int i=0; i < qtdNum-1; i++){
		for(int j=0; j < qtdNum-1-i; j++){
			if(vetor[j] > vetor[j+1]){
				aux = vetor[j];
				vetor[j] = vetor[j+1];
				vetor[j+1] = aux;
				operacoes++;
			}
		}
	}
	
	cout << "O vetor foi organizado em ordem crescente usando BubleSort. Foram realizadas " << operacoes << " trocas";
}

void SelectionSort(int vetor[], int qtdNum){
	int operacoes;
    for (int i = 0; i < qtdNum - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < qtdNum; j++) {
            if (vetor[j] < vetor[min_idx]) {
                min_idx = j;
            }
        }
        int temp = vetor[i];
        vetor[i] = vetor[min_idx];
        vetor[min_idx] = temp;
    }

	cout << "O vetor foi organizado em ordem crescente usando SelectionSort. \n";
}

void InsertionSort(int vetor[], int qtdNum){
	int aux = 0;

	for(int i=0; i < qtdNum; i++){
		if(vetor[i] > vetor[i+1] && i >= 0){
			aux = vetor[i+1];
			vetor[i+1] = vetor[i];
			vetor[i] = aux;
			i-=2;
		}
	}

	cout << "O vetor foi organizado em ordem crescente usando InsertionSort. \n";
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return i+1;
}

void QuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}


void Baguncar(int vetor[], int qtdNum){,.,    
    for (int i = 0; i < qtdNum - 1; i++) {
        int j = rand() % (qtdNum - i) + i;
        int temp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = temp;
    }

	cout << "O vetor foi baguncado. \n";
}

int showMenu(){
	int resposta = 0;
	cout << "\n=============== EXERCICIO DE ORDENACAO ==================\n";
	cout << "|  1) Preencher o vetor manualmente                     |\n";
	cout << "|  2) Preencher o vetor automaticamente                 |\n";
	cout << "|  3) Limpar o vetor                                    |\n";
	cout << "|  4) Imprimir o vetor de dados                         |\n";
	cout << "|  5) Ordenar com BubleSort                             |\n";
	cout << "|  6) Ordenar com SelectionSort                         |\n";
	cout << "|  7) Ordenar com InsertionSort                         |\n";
	cout << "|  8) Ordenar com QuickSort                             |\n";
	cout << "|  9) Baguncar vetor                                    |\n";
	cout << "|  10) Sair do programa                                 |\n";
	cout << "=========================================================\n";
	
	cout << "\nDigite a opcao desejada: ";
	cin >> resposta;
	
	return resposta;
}

int main(){
	int qtdNum;
	cout << "Digite a quantidade de elementos pretendidos:";
	cin >> qtdNum;
	int vetor[qtdNum];
	bool continuar = true;
	
	do{
		switch(showMenu()){
			case 1: manFill(vetor, qtdNum); break;
			case 2: autoFill(vetor, qtdNum); break;
			case 3: clear(vetor, qtdNum); break;
			case 4: imprimir(vetor, qtdNum); break;
			case 5: BubleSort(vetor, qtdNum); break;
			case 6: SelectionSort(vetor, qtdNum); break;
			case 7: InsertionSort(vetor, qtdNum); break;
			case 8: {
				QuickSort(vetor, 0, qtdNum); break;
				cout << "O vetor foi organizado em ordem crescente usando QuickSort. \n";
				break;
			}
			case 9: Baguncar(vetor, qtdNum); break;	
			case 10: continuar = false;
			default: cout << "Opcao Invalida\n";
		}
	}while(continuar==true);
	return 0;
}
