#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct Alunos {
	char Nome[30];
	int Idade;
	bool Aprovado;
	char sexo;
	float Media;
	float Notas[11];
};
struct Alunos alunos[100];

//============= QUANTIDADE DE ALUNOS ===================//
int qtdAlunos(){
	int contador = 0;
	for(int i = 0; i < 100; i++){
		if(alunos[i].Idade > 0)	
			contador++;
	}
	return contador;
}

int main(){
	
	//=============== VARIAVEIS ============================//
	float maior, menor, mediaFacul;
	int qtdNotas, somaIdade = 0;
	
	
	//=========== PERGUNTAR MÉDIA DA FACULDADE =============//
	cout << "Informe a media da faculdade: ";
	cin >> mediaFacul;
	
	//============ PERGUNTAR QUANTIDADE DE NOTAS ===========//
	cout << "Informe a quantidade de notas que deseja informar: ";
	cin >> qtdNotas;
	
	//============ PERGUNTAR INFORMAÇÕES ==============//
	int prosseguir = 0;
	do{
		//NOME
		cout << "Informe o nome do " << qtdAlunos()+1 << ". aluno:";
		cin >> alunos[qtdAlunos()].Nome;
		
		//SEXO
		do{
			cout << "Informe o sexo de " << alunos[qtdAlunos()].Nome << "[M/F]:";
			cin >> alunos[qtdAlunos()].sexo;
			
			if(toupper(alunos[qtdAlunos()].sexo) != 'M' && toupper(alunos[qtdAlunos()].sexo) != 'F')
				cout << "Valor invalido! Insira novamente:\n";
				
		}while(toupper(alunos[qtdAlunos()].sexo) != 'M' && toupper(alunos[qtdAlunos()].sexo) != 'F');

		//IDADE
		if(toupper(alunos[qtdAlunos()].sexo) == 'M')
			cout << "Informe a idade do aluno " << alunos[qtdAlunos()].Nome << ":";
		else if(toupper(alunos[qtdAlunos()].sexo) == 'F')
			cout << "Informe a idade da aluna " << alunos[qtdAlunos()].Nome << ":";
		else
			cout << "Entrada invalida!";
			
		cin >> alunos[qtdAlunos()].Idade;
		somaIdade += alunos[qtdAlunos()-1].Idade;
			
		//NOTAS
		for(int n=1; n <= qtdNotas; n++){
			if(n == 1)
				alunos[qtdAlunos()].Notas[0] = 0;
				
			cout << "Informe a " << n << ". nota de " << alunos[qtdAlunos()-1].Nome << ":";
			cin >> alunos[qtdAlunos()-1].Notas[n];
			alunos[qtdAlunos()-1].Notas[0] += alunos[qtdAlunos()-1].Notas[n];
		}
		
		//PROSSEGUIR
		do{
			cout << "Deseja cadastrar outro aluno? (1- Sim | 2- Nao)";
			cin >> prosseguir;
		}while(prosseguir != 1 && prosseguir != 2);
	
	}while(prosseguir == 1);
		
	system("cls");
	
	//============= VERIFICAR SE FOI APROVADO ==================//
	int homensAprov = 0, mulheresAprov = 0;
	cout << "- Alunos aprovados:\n\n";
	for(int i=0; i < qtdAlunos(); i++){
		alunos[i].Media = alunos[i].Notas[0]/qtdNotas;
		alunos[i].Aprovado = alunos[i].Media >= mediaFacul;
		if(alunos[i].Aprovado == true){
			cout << " " << alunos[i].Nome << "\n";
			
			if(alunos[i].sexo == 'M')
				homensAprov++;
			else if(alunos[i].sexo == 'F')
				mulheresAprov++;
		}	
	}
	
	cout << "\n- Alunos reprovados:\n\n";
	for(int i=0; i < qtdAlunos(); i++){
		if(alunos[i].Aprovado == false)
			cout << " " << alunos[i].Nome << "\n";
	}
	
	//============= PERCENTUAL POR GÊNERO ==================//
	int homens = 0, mulheres = 0;
	cout << "\n\n- Percentual por genero:\n\n";
	for(int i=0; i < qtdAlunos(); i++){
		if(toupper(alunos[i].sexo) == 'M')
			homens++;
		else
			mulheres++;
	}
	
	cout << " Porcentagem de homens: " << (100*homens)/qtdAlunos();
	cout << "\n Porcentagem de mulheres: " << (100-(100*homens)/qtdAlunos());
	
	//=========== PERCENTUAL DE APROVACAO POR GENERO =====================//
	cout << "\n\n Porcentagem de ALUNOS aprovados: " << (100*homensAprov)/homens;
	cout << "\n Porcentagem de ALUNAS aprovadas: " << (100*mulheresAprov)/mulheres;
	
	
	//========== ALUNOS MAIS NOVOS JOVENS ESTUDAM MAIS OU NAO ==========//
	cout << "\n\n- Alunos jovens estudam mais que alunos mais velhos ou nao:\n\n";
	int mediaIdade = somaIdade/qtdAlunos(), jovens = 0, velhos = 0;
	for(int i=0; i < qtdAlunos(); i++){
		if(alunos[i].Idade > mediaIdade && alunos[i].Aprovado == true)
			velhos++;
		else if(alunos[i].Idade <= mediaIdade && alunos[i].Aprovado == true)
			jovens++;
	}
	
	if(velhos > jovens)
		cout << " Eh INCORRETO dizer que alunos jovens estudam mais que alunos mais velhos";
	else 
		cout << " Eh CORRETO dizer que alunos jovens estudam mais que alunos mais velhos";
		
	//============ LISTAR ALUNOS ===========================================//
	cout << "\n\n\n- Relatorio Final";
	for(int i = 0; i < qtdAlunos(); i++){
		cout << "\n\n -------- " << alunos[i].Nome << " -------- \n";
		cout << " Idade: " << alunos[i].Idade << "\n";
		alunos[i].Aprovado ? (cout << " Situacao: Aprovado\n") : (cout << " Situacao: Reprovado\n");
		alunos[i].sexo == 'M' ? (cout << " Sexo: Masculino\n") : (cout << " Sexo: Feminino\n");
		
		cout << " Notas: ";
		
		//Listar Notas do aluno
		for(int n=1; n <= qtdNotas; n++){
			if(n != qtdNotas)
				cout << alunos[i].Notas[n] << ", ";
			else cout << alunos[i].Notas[n] << "\n";
		}
		
		cout << " Media: " << alunos[i].Media << "\n";
	}
	return 0;
}
