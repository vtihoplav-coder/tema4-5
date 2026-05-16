#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int grade;

public:
    Student(string n = "", int g = 0) : name(n), grade(g) {}

    friend ostream& operator<<(ostream& out, const Student& s) {
        out << left << setw(15) << s.name << setw(5) << s.grade;
        return out;
    }

    friend istream& operator>>(istream& in, Student& s) {
        in >> s.name >> s.grade;
        return in;
    }
};

ostream& tableFormat(ostream& out) {
    out << fixed << showpos << setprecision(3);
    return out;
}

int main() {
    Student st;
    cout << "Введіть ім'я та оцінку: ";
    cin >> st;

    cout << "Результат: " << st << endl;
    cout << "Приклад форматування числа: " << tableFormat << 10.0 << endl;

    ofstream file("result.txt");
    file << "Студент: " << st << endl;
    file.close();
    return 0;
}

