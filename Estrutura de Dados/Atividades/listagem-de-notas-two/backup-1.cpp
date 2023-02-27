#include <stdio.h>
#include <iostream>

using namespace std;

struct Alunos {
	char Nome[30];
	int Idade;
	bool Aprovado;
	char sexo;
	float Media;
	float Notas[11];
};

int main(){
	
	//=============== VARIAVEIS ============================//
	float maior, menor, mediaFacul;
	int qtd, somaIdade = 0;
	
	//=========== PERGUNTAR MÉDIA DA FACULDADE =============//
	cout << "Informe a media da faculdade: ";
	cin >> mediaFacul;
	
	//============ PERGUNTAR QUANTIDADE DE NOTAS ===========//
	cout << "Informe a quantidade de alunos que deseja informar: ";
	cin >> qtd;
	
	struct Alunos alunos[1000];
	
	//============ PERGUNTAR INFORMAÇÕES ==============//
	for(int i = 0; i < qtd; i++){
		//NOME
		cout << "Informe o nome do " << i+1 << ". aluno:";
		cin >> alunos[i].Nome;
		
		//SEXO
		do{
			cout << "Informe o sexo de " << alunos[i].Nome << "[M/F]:";
			cin >> alunos[i].sexo;
			
			if(toupper(alunos[i].sexo) != 'M' && toupper(alunos[i].sexo) != 'F')
				cout << "Valor invalido! Insira novamente:\n";
				
		}while(toupper(alunos[i].sexo) != 'M' && toupper(alunos[i].sexo) != 'F');

		//IDADE
		if(toupper(alunos[i].sexo) == 'M')
			cout << "Informe a idade do aluno " << alunos[i].Nome << ":";
		else if(toupper(alunos[i].sexo) == 'F')
			cout << "Informe a idade da aluna " << alunos[i].Nome << ":";
		else
			cout << "Entrada invalida!";
			
		cin >> alunos[i].Idade;
		somaIdade += alunos[i].Idade;
			
		//NOTAS
		for(int n=1; n <= 10; n++){
			if(n == 1)
				alunos[i].Notas[0] = 0;
				
			cout << "Informe a " << n << ". nota de " << alunos[i].Nome << ":";
			cin >> alunos[i].Notas[n];
			//scanf("%f", &alunos[i].Notas[n]);
			alunos[i].Notas[0] += alunos[i].Notas[n];
			//alunos[1].sexo = 'F';
		}
	}

	system("cls");
	
	//============= VERIFICAR SE FOI APROVADO ==================//
	int homensAprov = 0, mulheresAprov = 0;
	cout << "- Alunos aprovados:\n\n";
	for(int i=0; i < qtd; i++){
		alunos[i].Media = alunos[i].Notas[0]/10;
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
	for(int i=0; i < qtd; i++){
		if(alunos[i].Aprovado == false)
			cout << " " << alunos[i].Nome << "\n";
	}
	
	//============= PERCENTUAL POR GÊNERO ==================//
	int homens = 0, mulheres = 0;
	cout << "\n\n- Percentual por genero:\n\n";
	for(int i=0; i < qtd; i++){
		if(toupper(alunos[i].sexo) == 'M')
			homens++;
		else
			mulheres++;
	}
	
	cout << " Porcentagem de homens: " << (100*homens)/qtd;
	cout << "\n Porcentagem de mulheres: " << (100-(100*homens)/qtd);
	
	//=========== PERCENTUAL DE APROVACAO POR GENERO =====================//
	cout << "\n\n Porcentagem de ALUNOS aprovados: " << (100*homensAprov)/homens;
	cout << "\n Porcentagem de ALUNAS aprovadas: " << (100*mulheresAprov)/mulheres;
	
	
	//========== ALUNOS MAIS NOVOS JOVENS ESTUDAM MAIS OU NAO ==========//
	cout << "\n\n- Alunos jovens estudam mais que alunos mais velhos ou nao:\n\n";
	int mediaIdade = somaIdade/qtd, jovens = 0, velhos = 0;
	for(int i=0; i < qtd; i++){
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
	for(int i = 0; i < qtd; i++){
		cout << "\n\n -------- " << alunos[i].Nome << " -------- \n";
		alunos[i].Aprovado ? (cout << " Situacao: Aprovado\n") : (cout << " Situacao: Reprovado\n");
		alunos[i].sexo == 'M' ? (cout << " Sexo: Masculino\n") : (cout << " Sexo: Feminino\n");
		cout << " Media: " << alunos[i].Media << "\n";
	}
	
	return 0;
}
