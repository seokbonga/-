
#include <iostream>
using namespace std;

class Doing {
public:
private:
	int stress;
	int time;
	int satiety;
	void playing() {
		cout << ("playing . . . \n");
		stress -= 10;//stress�� 10��ŭ ����
		time += 30;//30�е��� ������
		satiety += 10;


	}
		
	void walking() {
		cout << ("waiking. . .\n");
		stress -= 10;
		time += 30;
		satiety -= 10;
	}
	void poop() {
		cout << ("Choco is pooping!!");
		stress -= 20;
		time += 5;
		satiety -= 40;
	}
	void feeding() {
		cout << ("Delicious!");
		stress -= 5;
		time += 10;
		satiety += 70;
	}
	void sleeping() {
		cout << "Choco is sleepy!!";
		cout << "zzz. . . ";
		stress -= 50;
		time += 200;
		satiety -= 50;
	} //�ֱ⸶�� �ʿ��ϴٰ� ���

};