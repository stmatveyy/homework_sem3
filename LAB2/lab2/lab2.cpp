#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <ctime>
#include <utility>
#include <functional>
#include <algorithm>

std::vector <std::string> names = {"John","Mark","Olivia","Jack","Tom","Bruce","Henry","Nick","Roger","Matthew"}; // Дефолт-значния
std::vector <int> grades = { 100,20,40,50,100,40,30,20,10,100 }; // Дефолт-значения

std::vector <std::string> rand_names = {
"Benjamin","Brandon","John","Mark","Olivia","Jack",
"Tom","Bruce","Henry","Zack","Roger","Matthew",
"Christopher","Christian","Abraham","Brian","Francis",
"Gerld","Hayden","Carlos","Chase","Cody","Celia","Destiny","Elizabeth",
"Sofia", "Polly", "Fiona", "Hannah", "Isabella"
};

std::vector <int> ::iterator it_grades;
std::vector <std::string> ::iterator it_names;


// РЕАЛИЗАЦИИ ВЫВОДОВ ВЕКТОРОВ
// 
// Index-based
void output_index_based(std::vector <std::string> names, std::vector <int> grades) {
    for (int i = 0; i < names.size(); i++) {
        std::cout << "Name: " << names[i] << "  Grade: " << grades[i] << "\n";
    }

}

// Iterator-based
void output_it_based(std::vector <std::string> names, std::vector <int> grades) {
    for (it_names = names.begin(), it_grades = grades.begin(); it_names < names.end(), it_grades < grades.end(); it_names++, it_grades++) {
        std::cout << "Name: " << *it_names << "  Grade: " << *it_grades << "\n";
    }
}

// Range-based for loop
void output_for_based(std::vector <std::string> const& input1, std::vector <int> const& input2) {
    for (auto const& i1 : input1) {
        std::cout << "Name: " << i1 << "\n";
    }
    for (auto const& i2 : input2) {
        std::cout << "Grade: " << i2 << "\n";
    }
}


int get_random_num(int end) {
    return rand() % (end + 1);
}


std::pair <std::vector <std::string>, std::vector <int>> random_input_values(std::vector<std::string>& names, std::vector <int>& grades) {
    int students_qua;
    names = {};
    grades = {};
    std::cout << "Input the number of students: "; std::cin >> students_qua;
    for (int i = 0; i < students_qua; i++) {
        
        names.push_back(rand_names[get_random_num(rand_names.size())]);
        grades.push_back(get_random_num(100));
    }
    
    return std::make_pair(names, grades);
}


std::pair <std::vector <std::string>, std::vector <int>> user_input_values(std::vector<std::string>& names, std::vector <int>& grades) {
    int students_qua;
    std::string curr_student_name;
    int curr_student_grade;
    names = {};
    grades = {};
    std::cout << "Input the number of students: "; std::cin >> students_qua;
    for (int i = 0; i <= students_qua-1; i++) {
        std::cout << "Input the " << i+1 << " student`s name: "; std::cin >> curr_student_name;
        std::cout << "Now input his/her grade: "; std::cin >> curr_student_grade;
        names.push_back(curr_student_name);
        grades.push_back(curr_student_grade);
    }
    return std::make_pair(names, grades);
}


float average(std::vector <int> grades) {
    size_t students_qua = grades.size();
    int sum = 0;
    for (int i = 0; i <= students_qua-1; i++) {
        sum += grades[i];
    }
    return sum / students_qua;
}


std::pair <std::vector <std::string>, std::vector <int>>shaker_sort(std::vector<std::string>& names, std::vector <int>& grades) {
    bool Is_sorted = true; // с помощью этой переменной узнаем, меняли ли ячейки свое значение

    do { // сортируем пузырьком в двух направлениях
        Is_sorted = true;
        for (int i = 0; i < grades.size()-1; i++) {   // справа налево
            if (grades[i] > grades[i + 1]) { // если предыдущий элемент меньше следующего:
                std::swap(grades[i], grades[i + 1]); //меняем местами оценки
                std::swap(names[i], names[i + 1]); // и имена, чтобы все совпадало по индексам
                Is_sorted = false; // записываем в переменную, что замена производилась
            }
        }
        for (int i = grades.size()/2; i >= 1; i--) { // слева направо
            if (grades[i] < grades[i - 1]) { // если следующий элемент меньше предыдущего:
                std::swap(grades[i], grades[i - 1]); // меняем местами оценки
                std::swap(names[i], names[i - 1]); // и имена
                Is_sorted = false; // замена была
            }
        }
    } while (Is_sorted == false); // пока ячейки менялись, делаем сортировку

    return std::make_pair(names, grades);
}


float median(std::vector <int>& grades) {
    auto p = shaker_sort(names, grades);
    int index;
    if (p.second.size() % 2 == 0) {
        int index1 = p.second.size() / 2;
        int index2 = index1 - 1;
        return (p.second[index1] + p.second[index2]) / 2.0;
    }
    else {
        index = p.second.size() / 2;
        return p.second[index];
    }
}


std::pair <int, std::vector <std::string>> mode(std::vector<std::string>& names, std::vector <int>& grades) {

    auto p = shaker_sort(names, grades);
    std::vector <std::string> mode_names = {};
    std::vector <int> moda = {};

    for (int i = 1; i < p.second.size() - 1; i++) {
        if (p.second[i] == p.second[i - 1]) {
            moda.push_back(p.second[i]);
                if (p.second[i] != p.second[i + 1]) {
                    moda.push_back(p.second[i]);
                }
        }
    }
    if (moda.size() == 0) {
        return std::make_pair(404,mode_names);
    }
    else {
        std::sort(moda.begin(), moda.end(), std::greater<int>());

        int b = moda[0], a = 0, c = 0;
        for (int i = 0; i < moda.size(); i++) {
            if (moda[i] == b) {
                a = moda[i];
                c++;
            }
        }

        for (int i = 0; i < p.second.size(); i++) {
            if (p.second[i] == a) {
                mode_names.push_back(p.first[i]);
            }
        }
        return std::make_pair(a, mode_names);

    }
    
}


int main()
{

    int choice;
    float avg;
    float med;
    std::pair <std::vector <std::string>, std::vector <int>> students_data;
    std::pair<int, std::vector<std::string>> mode_;

    std::cout << "Hi! Choose how to initialize the data:\n " << "1 --- Default values\n" << "2 --- Random values\n" << "3 --- Custom values " << "\n" << "Your choice: ";
    std::cin >> choice;

    switch (choice)
    {

    case 1:

        std::cout << "The default values are: " << "\n"; output_index_based(names, grades);

        avg = average(grades);
        med = median(grades);
        mode_ = mode(names, grades);

        std::cout << "\n" << "The average value is: " << avg << "\n";
        std::cout << "The median is: " << med << "\n";

        if (mode_.first == 404) {

            std::cout << "There is no mode in the list" << "\n";
            break;
        }

        else {

            std::cout << "The mode is: " << mode_.first << "\n\n";
            std::cout << "The names with such mode: " << "\n";

            for (int i = 0; i < mode_.second.size(); i++) {
                std::cout << mode_.second[i] << "\n";
            }

            break;
        }

    case 2:

        srand(time(0));

        students_data = random_input_values(names, grades);
        std::cout << "The random values are: " << "\n"; output_index_based(students_data.first, students_data.second);

        avg = average(students_data.second);
        med = median(students_data.second);
        mode_ = mode(students_data.first, students_data.second);

        std::cout << "\n" << "The average value is: " << avg << "\n";
        std::cout << "The median is: " << med << "\n";
        if (mode_.first == 404) {

            std::cout << "There is no mode in the list" << "\n";
            break;
        }
        else {

            std::cout << "The mode is: " << mode_.first << "\n\n";
            std::cout << "The names with such mode: " << "\n";

            for (int i = 0; i < mode_.second.size(); i++) {
                std::cout << mode_.second[i] << "\n";
            }

            break;
        }

    case 3:

        students_data = user_input_values(names, grades);
        std::cout << "Your values are: " << "\n"; output_index_based(students_data.first, students_data.second);

        avg = average(students_data.second);
        med = median(students_data.second);
        mode_ = mode(students_data.first, students_data.second);

        std::cout << "\n" << "The average value is: " << avg << "\n";
        std::cout << "The median is: " << med << "\n";

        if (mode_.first == 404) {

            std::cout << "There is no mode in the list" << "\n";
            break;

        }

        else {

            std::cout << "The mode is: " << mode_.first << "\n\n";
            std::cout << "The names with such mode: " << "\n";

            for (int i = 0; i < mode_.second.size(); i++) {
                std::cout << mode_.second[i] << "\n";
            }

            break;

        }
        
    default:

        std::cout << "Wrong choice! Try again... " << "\n";
        break;

    }

    return 0;
}
