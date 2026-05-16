#include <iostream>
using namespace std;

class FileService {
public:
    void load() { cout << "File loaded" << endl; }
};

class ValidationService {
public:
    void validate() { cout << "Data validated" << endl; }
};

class ExportService {
public:
    void exportReport() { cout << "Report exported" << endl; }
};

class ReportFacade {
    FileService files;
    ValidationService validation;
    ExportService exportService;
public:
    void prepareReport() {
        files.load();
        validation.validate();
        exportService.exportReport();
    }
};
class ILogger {
public:
    virtual ~ILogger() = default;
    virtual void log(const string& text) = 0;
};

class OldLogger {
public:
    void writeLog(const string& text) {
        cout << "Old logger: " << text << endl;
    }
};

class LoggerAdapter : public ILogger {
    OldLogger& oldLogger;
public:
    LoggerAdapter(OldLogger& logger) : oldLogger(logger) {}
    void log(const string& text) override {
        oldLogger.writeLog(text);
    }
};


class IStorage {
public:
    virtual ~IStorage() = default;
    virtual void save(const string& text) = 0;
};

class FileStorage : public IStorage {
public:
    void save(const string& text) override {
        cout << "Saved to file: " << text << endl;
    }
};

class ReportService {
    IStorage& storage;
public:
    ReportService(IStorage& s) : storage(s) {}
    void createReport() {
        storage.save("student report");
    }
};


class IOutputDevice {
public:
    virtual ~IOutputDevice() = default;
    virtual void print(const string& text) = 0;
};

class ConsoleOutput : public IOutputDevice {
public:
    void print(const string& text) override {
        cout << text << endl;
    }
};

class Report {
protected:
    IOutputDevice& output;
public:
    Report(IOutputDevice& out) : output(out) {}
    virtual void show() = 0;
};

class TextReport : public Report {
public:
    TextReport(IOutputDevice& out) : Report(out) {}
    void show() override {
        output.print("Text report");
    }
};


