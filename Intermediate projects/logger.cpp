#include <iostream>
#include <string>
#include <fstream>


namespace nm {
    enum class Logginglevels{
        LOG_INFO,
        LOG_WARNING,
        LOG_ALL,
    };
    
    class Mylogger{
        const std::string defaultlogfile = "defaultlogfile.txt";
        public:
            Mylogger();
            ~Mylogger();
            explicit Mylogger(const std::string& customlogfile);
            Mylogger(const Mylogger& rhs)=delete;
            Mylogger& operator=(const Mylogger& rhs)= delete;
            Mylogger(Mylogger&& rhs) noexcept;
            Mylogger& operator=(Mylogger&& rhs) noexcept;

            void logtofile(const std::string& message);
            void logtoconsole(const std::string& message);
            void logwithlevel(const std::string& message, Logginglevels loglevel);
            void logtoall(const std::string& message);
        private:
            std::fstream fs;
            std::string messagestart;


    };
    void Mylogger::logtofile(const std::string& message){
        messagestart = "FILE log: ";
        fs << message << '\n';
    }
    void Mylogger::logtoconsole(const std::string& message){
        messagestart = "CONSOLE log: ";
        std::cout << messagestart << message <<'\n';
    }
    void Mylogger::logwithlevel(const std::string& message, Logginglevels loglevel){
        switch (loglevel)
        {
        case Logginglevels::LOG_INFO:
            logtoconsole("Log level INFO: " + message);
            break;
        case Logginglevels::LOG_WARNING:
            logtoconsole("Log level WARNING: " + message);
            break;
        case Logginglevels::LOG_ALL:
            logtoconsole("Log level ALL: " + message);
            break;
        default:
            logtoconsole("No logging level: " + message);
            break;
        }
    }
    void Mylogger::logtoall(const std::string& message){
            logtoconsole(message);
            logtofile(message);
    }
    Mylogger::Mylogger(){
    fs.open(defaultlogfile, std::ios::app);
    messagestart = "started logging to a new file. ";
    }
    Mylogger::Mylogger(const std::string& customlogfile){
        messagestart = "started logging to a new file. ";
        fs.open(customlogfile, std::ios::app);
    }
    Mylogger::~Mylogger(){
    fs.close();
    }
    Mylogger::Mylogger(Mylogger&& rhs) noexcept
        :fs{ std::move(rhs.fs) }, messagestart{ rhs.messagestart }
    {
    }
 
    Mylogger& Mylogger::operator=(Mylogger&& rhs) noexcept
    {
        messagestart = std::move(rhs.messagestart);
        fs = std::move(rhs.fs);
        return *this;
    }
}


int main(){
    nm::Mylogger o1;
    o1.logtoconsole("message 1");
    o1.logtofile("Custom file name log message 1: ");
    o1.logwithlevel("Custom log message 3. ", nm::Logginglevels::LOG_WARNING);
    o1.logtoall("log to all test");
    return 0;
}
