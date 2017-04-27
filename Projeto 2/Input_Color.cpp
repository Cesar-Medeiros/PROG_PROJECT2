#include "Header.h"

#include <Windows.h>
/**Pergunta ao utilizador para escolher uma opcao. Previne erros de input.
@return Opcao se o numero introduzido for inteiro, ou -1 se o input nao for um inteiro
*/

int readOption() {

	int option;
	colorCout('?');
	cout << "Escolha uma opcao: ";
	cin >> option;

	char bufferContent;
	cin.get(bufferContent);

	if (cin.fail() || bufferContent != '\n') {
		cin.clear();
		cin.ignore(10000, '\n');
		colorCout('!');
		cout << "Input invalido\n\n";
		option = -1; //Ter a certeza que o lixo de memoria que ficou na opcao nao seja nenhuma das opcoes
	}

	return option;
}

/**Le um numeros (unsigned int). O parametro texto e uma string que e apresentada ao utilizador.
@param

textoImprimir imprime um texto para a consola;
var Variavel onde vai ser guardado o numero;
simboloPergunta True para apresentar o simbolo ?

*/

void readNum(const char coutText[], uint &num, bool displaySymbol) {

	char bufferContent;

	do {
		if (displaySymbol)
			colorCout('?');

		cout << coutText;
		cin >> num;
		cin.get(bufferContent);

		if ((cin.fail() || bufferContent != '\n')) {
			cin.clear();
			cin.ignore(10000, '\n');
			colorCout('!');
			cout << "Invalid Input\n\n";

		}

	} while (cin.fail() || bufferContent != '\n');
}

void colorCout(char symbol) {
	int colorNum;
	bool validSymbol = true;
	switch (symbol) {

	case '?': colorNum = 9; break;
	case '!': colorNum = 12; break;
	case '*': colorNum = 10; break;
	default: validSymbol = false;
	}

	if (validSymbol) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
		cout << "[" << symbol << "] ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
}