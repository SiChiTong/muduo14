

#ifndef TMUDUO_LOGFILE_H
#define TMUDUO_LOGFILE_H

#include <mutex>
#include <muduo/base/Types.h>
#include <memory>
#include <string>

namespace muduo
{
    namespace FileUtil
    {
        class AppendFile;
    }
    class LogFile : noncopyable
    {
    public:
        LogFile(const std::string &basename,
                size_t rollSize,
                bool threadSafe = true,
                int flushTnterval = 3,
                int checkEveryN = 1024);

        ~LogFile();

        void append(const char *logline, int len);

        void flush();

        bool rollFile();

    private:
        void append_unlocked(const char *logline, int len);

        static std::string getLogFileName(const std::string &basename, time_t *now);

        const std::string basename_;
        const size_t rollSize_;
        const int flushInterval_;
        const int checkEveryN_;

        int count_;

        std::unique_ptr<std::mutex> mutex_;
        time_t startOfPeriod_;
        time_t lastRoll_;
        time_t lastFlush_;

        std::unique_ptr<FileUtil::AppendFile> file_;
        const static int kRollPerSeconds_ = 60 * 60 * 24;
    };
}
#endif //TMUDUO_LOGFILE_H
