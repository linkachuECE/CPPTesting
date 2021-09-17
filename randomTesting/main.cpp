#include <string>
#include <iostream>
#include <regex>

class Address{
private:
    std::string m_streetName{}, m_city{}, m_state{};
    int m_addNo{}, m_zipCode{};
public:
    void setStreetName(const std::string& streetName){m_streetName = streetName;}
    void setAddNo(int addNo){m_addNo = addNo;}
    void setCity(const std::string& city){m_city = city;}
    void setState(const std::string& state){m_state = state;}
    void setZip(int zipCode){m_zipCode = zipCode;}

    std::string getStreetName()const{return m_streetName;}
    int getAddNo()const{return m_addNo;}
    std::string getCity()const{return m_city;}
    std::string getState()const{return m_state;}
    int getZip()const{return m_zipCode;}

    friend std::ostream& operator<<(std::ostream& out, Address address){
        out << '\t' << address.m_addNo << std::endl;
        out << '\t' << address.m_streetName << std::endl;
        out << '\t' << address.m_city << std::endl;
        out << '\t' << address.m_state << std::endl;
        out << '\t' << address.m_zipCode << std::endl;
        return out;
    }
};

class Person{
private:
    std::string m_name{};
    Address m_address{};

public:
    void setName(std::string name){m_name = name;}
    void setAddress(std::smatch& matches){
        m_address.setAddNo(stoi(matches[1]));
        m_address.setStreetName(matches[2]);
        m_address.setCity(matches[3]);
        m_address.setState(matches[4]);
        m_address.setZip(stoi(matches[5]));
    }

    friend std::ostream& operator<<(std::ostream& out, Person person){
        out << person.m_name << std::endl;
        out << person.m_address << std::endl;
        return out;
    }
};

void parseAddress(std::string& infoString, Person& person){
    // Example addresses:
    // 204 S. Pine Lane, Carbondale, IL 62901
    // 54 Nova Lane, Carbondale, IL 62901
    // 211 North Broadway, Saint Louis, MO 63102

    std::regex pattern(R"((\d*) ([\w\s\.]*), ([\w\s]*), (\w{2}) (\d*))");
    std::smatch matches;

    std::regex_match(infoString, matches, pattern);
    person.setAddress(matches);
}

void promptForInfo(Person& person){
    std::string input{};
    std::cout << "Enter a name: ";
    std::getline(std::cin, input);
    person.setName(input);
    input.clear();

    std::cout << "Enter your address: ";
    std::getline(std::cin, input);
    parseAddress(input, person);
}

int main(){
    Person me;

    promptForInfo(me);

    std::cout << me << std::endl;

    return 0;
}