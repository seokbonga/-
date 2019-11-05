#include <iostream>

using namespace std;

class dogState {
  private:
    int satiety;
    int stress;

  public:
    dogState(int satiety, int stress) {
        this->satiety = satiety;
        this->stress = stress;
    }
    void showDogState() {
        cout << "포만감 : " << satiety << endl;
        cout << "스트레스 : " << stress << endl;
    }
};
