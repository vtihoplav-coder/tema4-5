#include <memory>
#include <string>
using namespace std;

class ITask {
public:
    virtual ~ITask() = default;
    virtual void print() const = 0;
};

class ReportTask : public ITask {
public:
    void print() const override {
        cout << "Report task: prepare written work" << endl;
    }
};

class TestTask : public ITask {
public:
    void print() const override {
        cout << "Test task: complete questions" << endl;
    }
};

class TaskCreator {
public:
    virtual ~TaskCreator() = default;
    virtual unique_ptr<ITask> createTask() const = 0;

    void run() const {
        auto task = createTask();
        task->print();
    }
};

class ReportTaskCreator : public TaskCreator {
public:
    unique_ptr<ITask> createTask() const override {
        return make_unique<ReportTask>();
    }
};

class TestTaskCreator : public TaskCreator {
public:
    unique_ptr<ITask> createTask() const override {
        return make_unique<TestTask>();
    }
};

int main() {
    unique_ptr<TaskCreator> creator = make_unique<ReportTaskCreator>();
    creator->run();

    creator = make_unique<TestTaskCreator>();
    creator->run();
    return 0;
}

