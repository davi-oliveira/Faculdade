#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
	
	//=============== VARIÁVEIS ============================//
	float maior, menor, Soma=0;
	int qtd;
	
	//============ PERGUNTAR QUANTIDADE DE NOTAS ===========//
	cout << "Informe a quantidade de notas: ";
	cin >> qtd;
	
	float notas[qtd];
	
	//============ PERGUNTAR QUAIS SÃO AS NOTAS ==============//
	for(int i = 0; i<qtd; i++){
		cout << "Informe a " << i+1 << " nota:";
		cin >> notas[i];
		Soma+=notas[i];
	}
	
	
	system("cls");
	
	
	
	//================== NOTAS INFORMADAS =====================//
	cout << "\n- Notas informadas: \n";
	for(int i=0; i < sizeof(notas)/4; i++){
		printf("\n Nota %i: %2.f \n", i+1, notas[i]);
	}
	
	//================== MOSTRAR MÉDIA ========================//
	cout << "\n\n- A media eh: " << Soma/qtd;
	
	//================== MAIOR E MENOR NOTA =====================//
	cout << "\n\n\n- Maior e Menor notas: \n";
	for(int i=0; i < sizeof(notas)/4; i++){
		if(i == 0){
			menor = notas[i];
			maior = notas[i];
		}
		if(notas[i] > maior) 
			maior = notas[i];
		
		if(notas[i] < menor){
			menor = notas[i];
		}
	}
	
	cout << "\n Maior nota: " << maior;
	cout << "\n Menor nota: " << menor; 
	
	//================== ACIMA DA MÉDIA ========================//
	cout << "\n\n\n- Notas acima da media: \n";
	for(int i=0; i < sizeof(notas)/4; i++){
		if(notas[i] >= (Soma/qtd))
			cout << "\n " << notas[i];
	}
	
	//================== ABAIXO DA MÉDIA ========================//
	cout << "\n\n\n- Notas abaixo da media: \n";
	for(int i=0; i < sizeof(notas)/4; i++){
		if(notas[i] < (Soma/qtd))
			cout << "\n " << notas[i];
	}
	
	//======================== FIM =============================//
	
	return 0;
}
