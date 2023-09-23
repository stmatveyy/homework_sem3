// Задание сырое, и уже не хочу его переделывать, но пусть валяется тут



#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <iterator>
std::map <const int, float> all_users;
const float INITIAL_DEPOSIT = 100;
std::vector <int> arr;

/// Функции
std::map <const int, float> generate() {
	for (int i = 1001; i <= 1100; i++) {
		all_users[i] = 0;
	}
	return all_users;
}

void balance_inq(std::vector <int> arr) {
	int inq_num = 1001;
	bool found = true;
	while (inq_num != 0) {
		std::cout << "Choose an account number (1001 - 1100) to be inquired. Press \"0\" to exit. " << "\n";
		std::cout << "Now open: " << "\n\n";
		for (int i = 0; i < arr.size(); i++) {
			std::cout << arr[i] << "," << "\n";
		}
		std::cout << "Your choice: ";
		std::cin >> inq_num;
		bool found = std::binary_search(arr.begin(), arr.end(), inq_num);
		if (!found) {
			std::cout << "Incorrect number! Account either doesn't exist or isn't opened yet.. " << "\n\n";
		}
		else if (inq_num == 0) {
			std::cout << "\n";
			break;
		}

		else {
			std::cout << "An account " << inq_num << " balance is " << all_users[inq_num] << "\n\n";
		}
	}
}

std::map <const int, float>  withdraw(std::vector <int> arr) {
	int dep_num = 1001;
	bool found = true;
	float withdrawal;
	while (dep_num != 0) {
		std::cout << "Choose an account number (1001 - 1100) to withdraw money. Press \"0\" to exit. " << "\n";
		std::cout << "Now open: " << "\n";
		for (int i = 0; i < arr.size(); i++) {
			std::cout << arr[i] << "," << "\n\n";
		}
		std::cout << "Your choice: ";
		std::cin >> dep_num;
		bool found = std::binary_search(arr.begin(), arr.end(), dep_num);
		if (!found) {
			std::cout << "Incorrect number! Account either doesn't exist or isn't opened yet.. " << "\n\n";
		}
		else if (dep_num == 0) {
			std::cout << "\n";
			break;
		}

		else {
			std::cout << "Great! Now insert a withdrawal in $: " << "\n"; std::cin >> withdrawal;
			if (all_users[dep_num] < withdrawal) {
				std::cout << "Insufficient funds, try again... " << "\n";
			}

			else {
				all_users[dep_num] -= withdrawal;
				std::cout << "An account " << dep_num << " balance is " << all_users[dep_num] << "\n\n";
			}
		}
	}
	return all_users;
}

std::map <const int, float> deposit(std::vector <int> arr) {
	int dep_num = 1001;
	bool found = true;
	float deposit;
	while (dep_num != 0) {

		std::cout << "Choose an account number (1001 - 1100) to deposit into. Press \"0\" to exit. " << "\n";
		std::cout << "Now open: " << "\n";

		for (int i = 0; i < arr.size(); i++) {
			std::cout << arr[i] << "," << "\n\n";
		}
		std::cout << "Your choice: ";
		std::cin >> dep_num;
		std::cout << "\n";
		bool found = std::binary_search(arr.begin(), arr.end(), dep_num);
		if (!found) {
			std::cout << "Incorrect number! Account either doesn't exist or isn't opened yet.. " << "\n\n";
		}
		else if (dep_num == 0) {
			std::cout << "\n";
			break;
		}

		else {
			std::cout << "Great! Now insert a deposit in $: "; std::cin >> deposit;
			all_users[dep_num] += deposit;
			std::cout << "An account " << dep_num << " balance is " << all_users[dep_num] << "\n\n";
		}
	}
	return all_users;
}

void close(std::vector <int> arr) {
	int cl_index = 1010;

	while (cl_index != 0) {
		std::cout << "Choose an accout to close. Type \"0\" to exit. " << "\n";

		std::cout << "Now open: " << "\n";
		for (int i = 0; i < arr.size(); i++) {
			std::cout << arr[i] << "," << "\n\n";
		}
		std::cout << "Your choice: ";
		std::cin >> cl_index;
		bool found = std::binary_search(arr.begin(), arr.end(), cl_index);
		if (!found) {
			std::cout << "Incorrect number! Account either doesn't exist or isn't opened yet.. " << "\n\n";
		}
		else {
			auto it2 = std::find(arr.begin(), arr.end(), cl_index);
			int index = it2 - arr.begin();
			std::cout << index << "\n";

			auto it = arr.begin(); // Алгоритмы нахождения индекса и удаления нашел в интернете, реализация не моя :(
			std::advance(it, index);
			arr.erase(it);
		}
	}
}

std::map <const int, float> interest(std::map <const int, float> arr) {
	float inter;
	std::cout << "Type a interest rate in persents: " << "\n"; std::cin >> inter;
	inter /= 100;
	for (int i = 1001; i <= 1100; i++) {
		arr[i] += arr[i] * inter;
	}
	return arr;
}

void view_acc(std::map <const int, float> arr) {
	for (int i = 1001; i <= 1051; i++) {
		std::cout << "Account number: " << i << " Balance: " << arr[i] << "\t\t" << "Account number: " << i + 50 << " Balance: " << arr[i + 50] << "\n";
	}
};


int main() {
	std::map <const int, float> fin_map = generate();
	int open_num = 1002;
	std::vector <int> arr;
	char user_choice = ' ';
	while (user_choice != 'E') {
		std::cout << "\nChoose an action to perform: " << "\n";
		std::cout << "O --- Open an account" << "\n";
		std::cout << "B --- A Balance inquiry" << "\n";
		std::cout << "D --- Make a deposit" << "\n";
		std::cout << "W --- Make a withdrawal" << "\n";
		std::cout << "C --- Close an account" << "\n";
		std::cout << "I --- Compute an intesert (Perform on all accounts)" << "\n";
		std::cout << "P --- View all acounts" << "\n";
		std::cout << "E ------ Exit" << "\n\n";
		std::cout << "Your choice: ";
		std::cin >> user_choice;

		switch (user_choice) {

		case 'O':
			while (open_num != 0) {
				bool found = std::binary_search(arr.begin(), arr.end(), open_num);
				if (open_num < 1001 || open_num > 1100 || found == true) {
					std::cout << "Wrong imput, try again! " << "\n\n";
				}

				else if (arr.size() > 100) {
					std::cout << "You have opened more than 100 accounts. Close at least one to proceed... " << "\n";
				}

				else if (open_num != 0) {
					arr.push_back(open_num);
					all_users[open_num] += INITIAL_DEPOSIT;
					std::cout << "New account " << open_num << " balance is " << all_users[open_num] << "\n\n";
				}
			}
			open_num = 1002;
			break;
		case 'B':
			balance_inq(arr);
			break;

		case 'D':
			fin_map = deposit(arr);
			break;

		case 'W':
			fin_map = withdraw(arr);
			break;

		case 'C':
			close(arr);
			break;

		case 'I':
			fin_map = interest(fin_map);
			break;

		case 'P':
			view_acc(fin_map);
			break;

		case 'E':
			break;

		default:
			std::cout << "Wrong command! Try again or press E to exit... " << "\n";
		}

	}
	return 0;
}
