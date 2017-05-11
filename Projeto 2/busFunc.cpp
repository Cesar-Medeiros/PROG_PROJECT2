
#include "Header.h"
#include <utility>

unsigned int addDriver(const std::string &fileName, std::vector<Driver> &drivers);

void readBus(std::vector<Driver> &drivers, std::vector<Bus> &bus,std::string fileName) {

	std::fstream busFile;
	busFile.open(fileName, std::ios::in);
	
	if (!busFile.is_open())
		return;
	
	busFile.peek(); //Para posteriormente testar se e o ficheiro esta vazio

	while (!busFile.eof()) { // <--- Com a condicao anterior a flag eof fica se o ficheiro estiver vazio 


		uint orderInLine, driverId, lineId;
		std::vector<Shift> shifts;

		char separationChar;

		busFile >> orderInLine >> separationChar >> driverId >> separationChar >> lineId >> separationChar;

		uint startTime, endTime;
		bool endOfLine = false;

		while (!endOfLine) {
			busFile >> separationChar >> startTime >> separationChar >> endTime >> separationChar;
			Shift shift = Shift(lineId, driverId, orderInLine, startTime, endTime);


			if (startTime > 10079 || endTime > 10079 || startTime > endTime) {}

			else if (shifts.empty())
				shifts.push_back(shift);

			else if (endTime < shifts.at(0).getStartTime())
				shifts.insert(shifts.begin(), shift);

			else {

				for (size_t i = 0; i < shifts.size() - 1; i++) {
					if (shift.getEndTime() < shifts.at(i + 1).getStartTime()) {
						shifts.insert(shifts.begin() + i, shift);
						break;
					}
				}


				
			}
			char character = busFile.get();
			if (character == '\n')
				endOfLine = true;
		}

		bool found;

		for (size_t i = 0; i < drivers.size(); i++) {

			if (drivers.at(i).getId() == driverId) {
				found = true;
				drivers.at(i).setShifts(shifts);
			}
		}
		

		if (!found) {
			char answer;
			colorCout('!');
			std::cout << "Condutor com o Id = " << driverId << " nao foi encontrad.\n\n";
			colorCout('?');
			std::cout << "Deseja adicionar (S/N): "; //Melhor criar funcao auxiliar S/N
			std::cin >> answer;
			std::cin.ignore(1000, '\n');
			if (answer == 'N')
				break;
		}
			/*std::cout << "Insira o nome do condutor: ";
			std::string driverName;
			getline(std::cin, driverName);
			Driver(driverId,driverName, )
			*/


			Bus busTemp = Bus(orderInLine, driverId, lineId, shifts);

			if (bus.empty())
				bus.push_back(busTemp);

			else {

				for (size_t i = 0; i < bus.size() - 1; i++) {
					if (busTemp.getBusOrderInLine() < bus.at(i + 1).getBusOrderInLine()) {
						bus.insert(bus.begin() + i, busTemp);
						break;
					}
				}
			}

		busFile.peek();
	}
	

	busFile.close();
}

void writeBus(const std::vector<Bus> &bus, std::string fileName) {
	
	std::fstream busFile;
	busFile.open(fileName, std::ios::out);

	if (!busFile.is_open()) {
		//Fazer alguma coisa antes		
		return;
	}

	for (unsigned int i = 0; i < bus.size(); i++) {
		busFile << bus.at(i).getBusOrderInLine() << " ; " << bus.at(i).getDriverId() << " ; " << bus.at(i).getLineId() << " ; ";
		
		for (unsigned int j = 0; j < bus.at(i).getSchedule().size(); j++) {
			busFile << "[" << bus.at(i).getSchedule().at(j).getStartTime() << " , " << bus.at(i).getSchedule().at(j).getEndTime() << "]";
			
			if (j + 1 != bus.at(i).getSchedule().size())
				busFile << " ; ";
		}
		busFile << std::endl;
	}

}