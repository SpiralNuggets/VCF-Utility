#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include "include/vcard.h"
#include "include/text_io.h"


void parsecard(char* filename){ 
    std::ifstream ifs(filename);
    ifs.open(filename);
    TextReader tr(ifs);
    std::vector<vCard> cards = tr.parseCards();
    std::stringstream s;
    TextWriter tw(s);
    tw << cards;
    std::cout<<s.str();
}

void createcard(char* filename){
    std::stringstream s;
    vCard card;
    std::string command;
    std::cout << "---[Steve please add program name here] vCard Creator Intepreter---" << std::endl;
    while (true){
        command = "";
        std::cout << ">";
        std::cin >> command;
        if (command == "name"){
            std::string prefix,firstname,lastname;
            std::cout << "Prefix: ";
            std::cin >> prefix;
            std::cout << "First Name: ";
            std::cin >> firstname;
            std::cout << "Last Name: ";
            std::cin >> lastname;
            card << vCardProperty::createName(firstname,lastname,"",prefix);
        }
        else if (command == "birthday"){
            int day, month, year;
            std::cout << "Day: ";
            std::cin >> day;
            std::cout << "Month (in number): ";
            std::cin >> month;
            std::cout << "Year: ";
            std::cin >> year;
            card << vCardProperty::createBirthday(year,month,day);
        }
        else if (command == "address"){
            std::string street,city,state,country,postcode;
            std::cout << "Street: ";
            std::cin >> street;
            std::cout << "City: ";
            std::cin >> city;
            std::cout << "State or Province: ";
            std::cin >> state;
            std::cout << "Country: ";
            std::cin >> country;
            std::cout << "Postcode: ";
            std::cin >> postcode;
            card << vCardProperty::createAddress(street,city,state,postcode,country);
        }
        else if (command == "org"){
            std::string name;
            std::cout << "Name of the Organization: ";
            std::cin >> name;
            card << vCardProperty::createOrganization(name);
        }
        else if (command == "quit"){
            break;
        }
        else{
            std::cout<<"Wrong command bro";
        }
        std::ofstream file;
        file.open(filename);
        std::stringstream s;
        TextWriter tw(s);
        tw << card;
        file << s.str();
        file.close();
    }
    
}

void helptext(){
    std::cout<< "Vcard utils lol\nAvailable arguments\n -r: Parses the card in the raw form into the console\n -w [filename]: Make a vcard file by using the intepreter to input the properties.\n\tname - Add names\n\tbirthday - Add birthday\n\taddress - Adds an address \n\torg - Add an organization name";
}

int main(int argc, char* argv[]){
    if (argc == 1){
        helptext();
    }
    else{
        if (strcmp(argv[1],"-r")==0){
            parsecard(argv[2]);
        }
        else if (strcmp(argv[1],"-w")==0){
            createcard(argv[2]);
        }
        else{
            helptext();
        }
    }
}
