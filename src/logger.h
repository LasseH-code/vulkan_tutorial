/* date = June 23rd 2022 11:37 am */

#include <iostream>
#include <string>
#include <windows.h>
#include <wincon.h>

#ifndef LOGGER_H
#define LOGGER_H

namespace lhg
{
#define LOG_INFO(msg) log_info(__FILE__, __LINE__, msg)
#define LOG_DEBUG(msg) log_debug(__FILE__, __LINE__, msg)
#define LOG_WARN(msg) log_warning(__FILE__, __LINE__, msg)
#define LOG_ERROR(msg) log_error(__FILE__, __LINE__, msg)
#define LOG_CRIT(msg) log_critical(__FILE__, __LINE__, msg)
        
        struct Col
        {
                public: 
                const char* att;
                const int col;
                
                Col(const char* att, const int col)
                        : col(col), att(att){};
        };
        
        static Col normal_col = Col("\033[om", FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        static Col debug_col = Col("\033[om", FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        static Col warning_col = Col("\033[om", FOREGROUND_RED);
        static Col error_col = Col("\033[om", FOREGROUND_RED | FOREGROUND_INTENSITY);
        static Col critical_col = Col("\033[om", FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | /*FOREGROUND_INTENSITY |*/ BACKGROUND_RED | BACKGROUND_INTENSITY);
        
        static bool use_attributes = false;
        
        static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        
        static void log_line(const char* file, const size_t line, const char* msg, const char* col_att, const char* norm_att)
        {
                std::cout << col_att << '[' << file << ':' << line << "]: " << msg << norm_att << std::endl;
        }
        
        static void log(const char* file, const size_t line, const char* msg, const Col col)
        {
                char* col_att = (char*) col.att;
                char* norm_att = (char*) normal_col.att;
                if (!use_attributes)
                {
                        col_att = (char*) "";
                        norm_att = (char*) "";
                        SetConsoleTextAttribute(hConsole, col.col);
                        log_line(file, line, msg, col_att, norm_att);
                        SetConsoleTextAttribute(hConsole, normal_col.col);
                        return;
                }
                log_line(file, line, msg, col_att, norm_att);
        }
        
        static void log_info(const char* file, const size_t line, const char* msg)
        {
                log(file, line, msg, normal_col);
        }
        static void log_debug(const char* file, const size_t line, const char* msg)
        {
                log(file, line, msg, debug_col);
        }
        static void log_warning(const char* file, const size_t line, const char* msg)
        {
                log(file, line, msg, warning_col);
        }
        static void log_error(const char* file, const size_t line, const char* msg)
        {
                log(file, line, msg, error_col);
        }
        static void log_critical(const char* file, const size_t line, const char* msg)
        {
                log(file, line, msg, critical_col);
        }
}

#endif //LOGGER_H