#include "Header.h"

void insertBusStops(Line &line);
void insertTime(Line &line);
void editStopsDurations(std::vector<Line> &lines, unsigned int posLine);


void addLine(const std::string &fileName, std::vector<Line> &lines) {

	

	unsigned int id = readID(lines);
	unsigned int freq;
	readNum("Introduza a frequencia com que o autocarro passa (em minutos): ", freq);
	
	Line line;
	line.setId(id);
	line.setFreq(freq);
	insertBusStops(line);
	insertTime(line);
	sortID(line, lines);

	
	colorCout('*');
	std::cout << "Linha adicionada com sucesso ao ficheiro " << fileName << std::endl;

}

void changeLine(const std::string &fileName, std::vector<Line> &lines) {

	
	int posLine = ask_TestID(lines); //Tentar perguntar Insira o ID da linha;
	if (posLine == -1) return;


	std::cout << "\n\nIdentifier: " << lines.at(posLine).getId() << std::endl;
	std::cout << "Frequency: " << lines.at(posLine).getFreq() << std::endl;

	for (int i = 0; i < lines.at(posLine).getBusStops().size(); i++)
		std::cout << "Stop " << i << ": " << lines.at(posLine).getBusStop(i) << std::endl;

	for (int i = 0; i < lines.at(posLine).getTimings().size(); i++)
		std::cout << "Duration " << i << ": " << lines.at(posLine).getTiming(i) << std::endl;




	std::cout << "\n\n|               Edit Lines               |\n";
	std::cout << "|----------------------------------------|\n";
	std::cout << "|     (1)  ID                            |\n";
	std::cout << "|     (2)  Frequency                     |\n";
	std::cout << "|     (3)  Stops/Durations               |\n";
	std::cout << "|     (0)  Go Back                       |\n\n";

	bool validNumber;

	do {

		validNumber = true;

		int option = readOption(); //Le a opcao e faz os devidos testes para prevenir input invalido


		switch (option)
		{

		case 0: //Unica maneira de sair
			return;

		case 1: {
			unsigned int id = readID(lines);
			lines.at(posLine).setId(id);
			sortID(lines);
			break;
		}


		case 2:
			
			unsigned int freq;
			readNum("Introduza a frequencia com que o autocarro passa (em minutos): ", freq);
			lines.at(posLine).setFreq(freq);
			break;

		case 3:
			editStopsDurations(lines, posLine);
			break;


		default:
			validNumber = false;
			break;
		}

	} while (!validNumber);

	
	colorCout('*');
	std::cout << "Linha alterada com sucesso no ficheiro " << fileName << std::endl;
}

void removeLine(const std::string &fileName, std::vector<Line> &lines) {

	int pos = ask_TestID(lines); //Devolve a posicao da linha atraves da introducao do id ou devolve -1 se nao encontrar 

	if (pos != -1) {
		lines.erase(lines.begin() + pos);
		
		colorCout('*');
		std::cout << "Linha removida com sucesso ao ficheiro " << fileName << std::endl;
	}
	else {
		
		colorCout('!');
		std::cout << "Nao foi possivel eliminar a linha." << std::endl;
	}

}
