#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h> 

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
	
	for(int n=0; n < qtdNum; n++){
		for(int i=0; i< qtdNum; i++){
			if(vetor[i] > vetor[i+1]){
				aux = vetor[i+1];
				vetor[i+1] = vetor[i];
				vetor[i] = aux;
			}
		}
	}
	
	cout << "O vetor foi organizado em ordem crescente usando BubleSort. \n";
}

void SelectionSort(int vetor[], int qtdNum){
	int aux = 0;
	
	for(int n=0; n < qtdNum; n++){
		for(int i=n+1; n < qtdNum; n++){
			cout << "\n Verificando para os numeros: " << vetor[n] << " e " << vetor[i];
			
			if(vetor[n] > vetor[i]){
				cout << "\n " << vetor[n] << "eh maior que " << vetor[i];
				aux = vetor[i];
				vetor[i] = vetor[n];
				vetor[n] = aux;
			}
		}
	}
	
	cout << "O vetor foi organizado em ordem crescente usando SelectionSort. \n";
}
void InsectionSort(int vetor[]){}
void QuickSort(int vetor[]){}

void Baguncar(int vetor[], int qtdNum){

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
	cout << "|  7) Ordenar com InsectionSort                         |\n";
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
			case 7: InsectionSort(vetor); break;
			case 8: QuickSort(vetor); break;
			case 9: Baguncar(vetor, qtdNum); break;	
			case 10: continuar = false;
		}
	}while(continuar==true);
	return 0;
}
