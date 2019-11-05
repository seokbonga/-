#include <iostream>
#include <string>

using namespace std;

class DogInfo {
  private:
    string name;
    int age;
    char sex;

  public:
    DogInfo(string name, int age, char sex) {
        this->name = name;
        this->age = age;
        this->sex = sex;
    }
    string getName() { return name; }
    int getAge() { return age; }
    char getSex() { return sex; }
};
