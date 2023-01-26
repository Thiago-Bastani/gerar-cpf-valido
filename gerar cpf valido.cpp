#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <conio.h>

int calcularPrimeiroDigitoVerificador(int sequenciaNoveDigitos);
int calcularSegundoDigitoVerificador(long long int sequenciaDezDigitos);
int calcularDigitoVerificador(long long int sequenciaNoveDigitos);
void escolherNovePrimeirosDigitos();
void gerarCPFAleatorio();

int main()
{
	std::cout << "\n\nDIGITE [1] PARA ESCOLHER OS NOVE PRIMEIROS DIGITOS\nDIGITE [2] PARA GERAR ALEATORIAMENTE OS NOVE PRIMEIROS DIGITOS \nDIGITE [S] PARA SAIR\n\n\n";
	int ch = 0;
	while (ch != 's')
	{
		ch = 0;
		while (ch != '1' && ch != '2' && ch != 's')
		{
			setbuf(stdin, NULL);
			ch = getch();
		}
		switch (ch)
		{
		case '2':
			gerarCPFAleatorio();
			break;
		case '1':
			escolherNovePrimeirosDigitos();
			break;
		default:
			break;
		}
		std::cout << "\n\n";
	}
}

int calcularPrimeiroDigitoVerificador(int sequenciaNoveDigitos)
{
	int aux = 0;
	int seq = 2;
	while (sequenciaNoveDigitos > 0)
	{
		aux = aux + (sequenciaNoveDigitos % 10) * seq;
		seq++;
		sequenciaNoveDigitos = (int)(sequenciaNoveDigitos / 10);
	}
	return ((aux / 11) >= 2) ? (11 - (aux % 11)) : 0;
}

int calcularSegundoDigitoVerificador(long long int sequenciaDezDigitos)
{
	int aux = 0;
	int seq = 2;
	while (sequenciaDezDigitos > 0)
	{
		aux = aux + (sequenciaDezDigitos % 10) * seq;
		seq++;
		sequenciaDezDigitos = (int)(sequenciaDezDigitos / 10);
	}
	return ((aux / 11) >= 2) ? (11 - (aux % 11)) : 0;
}

int calcularDigitoVerificador(long long int sequenciaNoveDigitos)
{
	int primeiroDigito = calcularPrimeiroDigitoVerificador(sequenciaNoveDigitos);
	int digitoVerificador = 0;
	digitoVerificador = (primeiroDigito * 10) + calcularSegundoDigitoVerificador((sequenciaNoveDigitos * 10) + primeiroDigito);
	return digitoVerificador;
}

void escolherNovePrimeirosDigitos()
{
	int sequenciaNoveDigitos = 0;
	std::cout << "DIGITE OS NOVE PRIMEIROS DIGITOS DO CPF: ";
	std::cin >> sequenciaNoveDigitos;
	int digitoVerificador = 0;
	digitoVerificador = calcularDigitoVerificador(sequenciaNoveDigitos);
	std::cout << "CPF: " << sequenciaNoveDigitos << "-" << digitoVerificador;
}

void gerarCPFAleatorio()
{
	int sequenciaNoveDigitos = 0;
	unsigned seed = time(0);
	srand(seed);
	for (int i = 0; i < 9; i++)
	{
		sequenciaNoveDigitos = (sequenciaNoveDigitos * 10) + rand() % 10;
	}
	int digitoVerificador = 0;
	digitoVerificador = calcularDigitoVerificador(sequenciaNoveDigitos);
	std::cout << "CPF: " << sequenciaNoveDigitos << "-" << digitoVerificador;
	setbuf(stdin, NULL);
}