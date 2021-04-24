#include <iostream>
using namespace std;

class Case {
private:
    char value;
public:
    Case();
    Case(char);
    ~Case();
    char getValue();
    void setValue(char);
    void operator=(const Case& C);
    friend ostream& operator<<(ostream& flot, Case C) {
        flot << C.value;
        return flot;
    }
};