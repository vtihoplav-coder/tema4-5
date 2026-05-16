#include <iostream>
#include <string>
using namespace std;

class Logger {
private:
    Logger() = default;
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

public:
    static Logger& instance() {
        static Logger object;
        return object;
    }

    void write(const string& message) {
        cout << "LOG: " << message << endl;
    }
};

class CourseWorkService {
public:
    void run() {
        Logger::instance().write("Запуск сервісу курсової роботи");
    }
};

int main() {
    CourseWorkService service;
    service.run();

    Logger::instance().write("Операцію виконано успішно");
    return 0;
}

