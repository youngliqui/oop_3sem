#include <string>

class Chip {

// Дружественная функция для вывода списка микросхем указанной информационной ёмкости
friend void printByCapacity(std::vector<Chip> chips, int capacity);

private:
	std::string type;
	int capacity;
	std::string name;
	std::string productionDate;

public:
	Chip() {};
	~Chip() {};

	void init(std::string type, int capacity, std::string name, std::string productionDate) {
		this->type = type;
		this->capacity = capacity;
		this->name = name;
		this->productionDate = productionDate;
	}

	std::string getType() const {
		return type;
	};
	int getCapacity() const {
		return capacity;
	};
	std::string getName() const {
		return name;
	}
	std::string getProductionDate() const {
		return productionDate;
	}
};
