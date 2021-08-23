#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <any>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp> 
#include "json.hpp"
using namespace std;
using json = nlohmann::json;

class BankManager {
    std::string filename;
    public:
        BankManager(std::string filename_input) {
            filename = filename_input;
        }
        json getJson() {
            ifstream file(filename);
            json data;
            file >> data;
            return data;
        }
        void writeJson(json data) {
            ofstream file(filename);
            file << data;
        }
        int askOption() {
            cout << "1: Create an account\n2: Close an account\n3: List accounts\n4: Check balance\n5: Withdraw\n6: Deposit\n\n";
            cout << "Enter option: ";
            int opt; cin >> opt;
            return opt;
        }
        void addAccount() {
            json data = getJson();
            json new_account;

            cout << "Enter new account name: ";
            std::string acc_name;
            cin >> acc_name;
            cout << "Enter PIN: ";
            std::string acc_pin;
            cin >> acc_pin;

            boost::uuids::random_generator generator;
            boost::uuids::uuid uuid1 = generator();
            std::string acc_id = boost::uuids::to_string(uuid1);

            new_account["acc_id"] = acc_id;
            new_account["acc_name"] = acc_name;
            new_account["acc_pin"] = acc_pin;
            new_account["acc_balance"] = 0;

            data["data"].push_back(new_account);
            writeJson(data);
            cout << "Account created" << endl;
        }
        void closeAccount() {
            json data = getJson();
            cout << "Enter ID of to be deleted account: ";
            std::string acc_id;
            cin >> acc_id;
            for (int i = 0; i <= data["data"].size(); ++i) {
                if (i == data["data"].size()) {
                    cout << "Account ID not found" << endl;
                    break;
                }
                if (data["data"][i]["acc_id"] == acc_id) {
                    data["data"].erase(i);
                    cout << "Account closed" << endl;
                    break;
                }
            }
            writeJson(data);
        }
        void listAccounts() {
            json data = getJson();
            for (int i = 0; i < data["data"].size(); ++i) {
                cout << data["data"][i] << endl;
            }
        }
        void checkBalance() {
            json data = getJson();
            cout << "Enter account ID: ";
            std::string acc_id;
            cin >> acc_id;
            for (int i = 0; i <= data["data"].size(); ++i) {
                if (i == data["data"].size()) {
                    cout << "Account ID not found" << endl;
                    break;
                }
                if (data["data"][i]["acc_id"] == acc_id) {
                    cout << "Account balance: $" << data["data"][i]["acc_balance"] << endl;
                    break;
                }
            }
        }
        void withdraw() {
            json data = getJson();
            cout << "Enter account ID: ";
            std::string acc_id;
            cin >> acc_id;
            cout << "Enter withdrawal amount: ";
            int wth;
            cin >> wth;
            for (int i = 0; i <= data["data"].size(); ++i) {
                if (i == data["data"].size()) {
                    cout << "Account ID not found" << endl;
                    break;
                }
                if (data["data"][i]["acc_id"] == acc_id) {
                    if (data["data"][i]["acc_balance"].get_ref<json::number_integer_t&>() > wth) {
                        data["data"][i]["acc_balance"].get_ref<json::number_integer_t&>() -= wth;
                        cout << "Money withdrawn\n";
                    } else { cout << "Not enough balance\n"; }
                    cout << "Account balance: $" << data["data"][i]["acc_balance"] << endl;
                    break;
                }
            }
            writeJson(data);
        }
        void deposit() {
            json data = getJson();
            cout << "Enter account ID: ";
            std::string acc_id;
            cin >> acc_id;
            cout << "Enter deposit amount: ";
            int dep;
            cin >> dep;
            for (int i = 0; i <= data["data"].size(); ++i) {
                if (i == data["data"].size()) {
                    cout << "Account ID not found" << endl;
                    break;
                }
                if (data["data"][i]["acc_id"] == acc_id) {
                    data["data"][i]["acc_balance"].get_ref<json::number_integer_t&>() += dep;
                    cout << "Money deposited\n";
                    cout << "Account balance: $" << data["data"][i]["acc_balance"] << endl;
                    break;
                }
            }
            writeJson(data);
        }
};

int main() {
    std::string filename = "record_file.json";
    BankManager manager(filename);
    cout << "C++ BANK MANAGER\n";
    cout << "================\n\n";
    while (true) {
        int opt = manager.askOption();
        switch (opt) {
            case 1: manager.addAccount(); break;
            case 2: manager.closeAccount(); break;
            case 3: manager.listAccounts(); break;
            case 4: manager.checkBalance(); break;
            case 5: manager.withdraw(); break;
            case 6: manager.deposit(); break;
            default: cout << "Invalid option" << endl;
        }
        cout << "Want to use again? (y/n) ";
        char again; cin >> again;
        if (again != 'y') { break; }
    }
    cout << "Thank you!" << endl;
    return 0;
}