#include <string>
#include <vector>

class Tool {

private:
	std::string name;
	std::string model;
	bool status;
	std::string startTime;
	std::string endTime;

public:
	Tool();
	Tool(std::string name, std::string model, bool status, std::string startTime, std::string endTime);

	~Tool();

	void initialize();
	void display();

	friend void showAvailableTools(std::vector<Tool*> tools);
	friend void showAvailableToolsForTime(std::vector<Tool*> tools, std::string time);
	int *x;
	std::string getName();
	std::string getModel();
	bool getStatus();
	std::string getStartTime();
	std::string getEndTime();
};