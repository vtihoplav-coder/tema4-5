#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class ScheduleEntity {
protected:
    string name;
public:
    ScheduleEntity(const string& n) : name(n) {}
    virtual ~ScheduleEntity() = default;
    virtual void print() const {
        cout << "Entity: " << name << endl;
    }
};

class Teacher : public ScheduleEntity {
    string department;
public:
    Teacher(const string& n, const string& d)
        : ScheduleEntity(n), department(d) {}
    void print() const override {
        cout << "Teacher: " << name << ", department: " << department << endl;
    }
    void showDepartment() const {
        cout << department << endl;
    }
};

class Room : public ScheduleEntity {
    int capacity;
public:
    Room(const string& n, int c) : ScheduleEntity(n), capacity(c) {}
    void print() const override {
        cout << "Room: " << name << ", capacity: " << capacity << endl;
    }
};

void showEntity(const ScheduleEntity& entity) {
    entity.print();
}

void checkTeacher(ScheduleEntity* entity) {
    Teacher* t = dynamic_cast<Teacher*>(entity);
    if (t != nullptr) {
        cout << "This object is Teacher. Department: ";
        t->showDepartment();
    }
}

int main() {
    vector<unique_ptr<ScheduleEntity>> items;
    items.push_back(make_unique<Teacher>("Ivanenko", "Computer Science"));
    items.push_back(make_unique<Room>("A-101", 30));

    for (const auto& item : items) {
        item->print();
        checkTeacher(item.get());
    }

    return 0;
}
