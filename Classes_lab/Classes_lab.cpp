
#include <iostream>
#include <string>

class Company {
private:
    std::string name;
    std::string address;
    Employee* employee; // Связь с классом Employee (компания имеет сотрудника)

public:
    Company() {
        name = "";
        address = "";
        employee = nullptr;
    }

    Company(std::string name, std::string address, Employee* employee) : name(name), address(address), employee(employee) {
    }

    void printInfo() {
        std::cout << "Company Name: " << name << std::endl;
        std::cout << "Company Address: " << address << std::endl;
        if (employee != nullptr) {
            std::cout << "Employee: " << employee->getName() << std::endl;
        }
    }
    std::string getName() {
        return name;
    }
};


class Vehicle {
protected:
    std::string manufacturer;
    int year;
    Company* company; // Связь с классом Company (автомобиль принадлежит компании)
    std::string model;
    std::string registration_number;
public:
    Vehicle() {
        manufacturer = "";
        year = 0;
        company = nullptr;
    }

    Vehicle(std::string manufacturer, int year, Company* company) : manufacturer(manufacturer), year(year), company(company) {
    }

    Vehicle(std::string manufacturer, int year) : manufacturer(manufacturer), year(year), company(nullptr) {
    }

    // Дополнительные конструкторы
    Vehicle(std::string manufacturer) : manufacturer(manufacturer), year(0), company(nullptr) {
    }

    Vehicle(int year) : manufacturer(""), year(year), company(nullptr) {
    }

    void setCompany(Company* company) {
        this->company = company;
    }

    void printInfo() {
        std::cout << "Manufacturer: " << manufacturer << std::endl;
        std::cout << "Year: " << year << std::endl;
        if (company != nullptr) {
            std::cout << "Company: " << company->getName() << std::endl;
        }
    }
    std::string getManufacturer() {
        return manufacturer;
    }

    int getYear() {
        return year;
    }
};

class Employee {
private:
    std::string name;
    int age;
    Vehicle* vehicle; // Связь с классом Vehicle (сотрудник имеет автомобиль)

public:
    Employee() {
        name = "";
        age = 0;
        vehicle = nullptr;
    }

    Employee(std::string name, int age, Vehicle* vehicle) : name(name), age(age), vehicle(vehicle) {
    }

    void printInfo() {
        std::cout << "Employee Name: " << name << std::endl;
        std::cout << "Employee Age: " << age << std::endl;
        if (vehicle != nullptr) {
            std::cout << "Vehicle: " << vehicle->getManufacturer() << " " << vehicle->getYear() << std::endl;
        }
    };

    std::string getName() {
        return name;
    }
};

class Truck : public Vehicle {
    private:
        int mass;
        int capacity;
        int current_load;
        bool is_drivable = true;
    public:
        Truck() : Vehicle() {
            capacity = 0;
        }

        Truck(std::string manufacturer, int year, int capacity, Company* company) : Vehicle(manufacturer, year, company), capacity(capacity) {
        }

        void printInfo() {
            Vehicle::printInfo();
            std::cout << "Capacity: " << capacity << std::endl;
        }

        void carry_load(int weight) {
            this->current_load += weight;
            this->mass += current_load;
        }
       
        void unload() {
            std::cout << "Currently unloading, unable to drive" << std::endl;
            this->is_drivable = false;
        }

        void finished_unloading() {
            this->is_drivable = true;
        }
    };

    class Car : public Vehicle {
    private:
        int seats;
        bool has_passengers;
        bool has_speeding_tickets;
        std::string transmission;
    public:
        Car() : Vehicle() {
            model = "";
        }

        Car(std::string manufacturer, int year, Company* company, std::string model) : Vehicle(manufacturer, year, company) {
        }

        Car(std::string manufacturer, int year, std::string model) : Vehicle(manufacturer, year) {
        }

        Car(std::string manufacturer, std::string model) : Vehicle(manufacturer) {
        }

        void printInfo() {
            Vehicle::printInfo();
            std::cout << "Number of Seats: " << seats << std::endl;
        }
        void drive_passengers() {
            this->has_passengers = true;
        }
        void speeding() {
            this->has_speeding_tickets = true;
        }
    };


int main() {
    return 0;
}