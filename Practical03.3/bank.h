#include<string>
using namespace std;

class bank
{
    int anumber;
    string ahname;
    float abalance;
    static int count;

public:
    bank();
    bank(int num, string name, float bal);

    void display();

    int getAccNo();
    float getBalance();
    void setBalance(float b);

    void update();

    static void displaycount();
};
