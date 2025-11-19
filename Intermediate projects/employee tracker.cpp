#include <iostream>
#include <string>
#include <vector>
#include <memory>

namespace nm{
    class Person{
        private:
            std::string name;
            int age;
        public:
            Person();
            Person(const std::string& aname, int argage);
            Person(const Person& rhs);
            Person& operator=(const Person& rhs);
            Person(Person&& rhs) noexcept;
            Person& operator=(Person&& rhs) noexcept;


            void printname();
            void printage();
            void printdata();

            std::string getname() const;
            int getage() const;
            void setname(const std::string& aname);
            void setage(int argage);

            virtual ~Person();
            virtual void formatprint();

    };
    Person::Person(const Person& rhs): name(rhs.name), age(rhs.age){}
    Person& Person::operator=(const Person& rhs) {
        name = rhs.name;
        age = rhs.age;
        return *this;
    }
    Person::Person(Person&& rhs) noexcept : name(std::move(rhs.name)), age(std::move(rhs.age)) {}
    Person& Person::operator=(Person&& rhs) noexcept {
        name = std::move(name);
        age = std::move(age);
        return *this;
    }
    Person::Person():
        name{"default name"}, age{-1}{}

    Person::Person(const std::string& aname, int argage):
        name{aname}, age{argage}{}
    void Person::printage() {
        std::cout << age << '\n';
    }
    void Person::printname() {
        std::cout << name << '\n';
    }
    void Person::printdata() {
        std::cout << name << ' '<< age << '\n';
    }
    std::string Person::getname() const {
    return name;
    }
    int Person::getage() const {
    return age;
    }
    void Person::setage(int argage) {
        age = argage;
    }
    void Person::setname(const std::string& aname) {
    name = aname;
    }
    void Person::formatprint() {
        std::cout << "Person's name: " << name <<", age: "<<age <<'\n' ;
    }


    class Employee : public Person{
    private:
            std::string jobtitle;
    public:
        Employee();
        Employee(const std::string& aname, int argage, cost std::string& ajobtitle);
    };
    Employee::Employee() : person(), jobtitle{"the defaualt role"}{}
    Employee::Employee(const std::string& aname, int argage, const
    std::string& ajobtitle) : Person(aname, argage), jobtitle{ ajobtitle }
    {}

}
using namespace nm;
int main() {
    
        // a vector unique pointers
        std::vector<std::unique_ptr<Person>> v2;
        v2.emplace_back(std::make_unique<Employee>("Sample Name 1", 20,
       "Developer"));
        Chapter 41 Projects
        421
         v2.emplace_back(std::make_unique<Employee>("Sample Name 2", 25,
        "Engineer"));
        v2.emplace_back(std::make_unique<Employee>("Sample Name 3", 30,
       "Quality Assurance"));
        v2.emplace_back(std::make_unique<Employee>("Sample Name 4", 35,
       "Human Resources"));
        v2.emplace_back(std::make_unique<Employee>("Sample Name 5", 40,
       "Manager"));
        v2.emplace_back(std::make_unique<Employee>("Sample Name 6", 45,
       "CEO"));
        for (const auto& el : v2)
        {
            el->formatprint();
        }
        std::cout << "Testing..." << '\n';
        // testing
        Employee o3; // The default constructor invoked
        Employee o4("Sample name 7", 50, "Accountant");
        // copy assignment test:
        o3 = o4;
        o3.formatprint();

}
