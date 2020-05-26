#ifndef IO_PERF
#define IO_PERF

#include <iostream>
#include <utility>
#include <vector>
#include <memory>
#include <chrono>
#include <thread>
#include <string>
#include <fstream>

namespace io
{
    class IO_perf
    {
    private:
        // std::chrono::time_point<std::chrono::high_resolution_clock> process_start_time;
        std::chrono::time_point<std::chrono::high_resolution_clock> start_time;

    public:
        IO_perf(const int);
        ~IO_perf();
        void MeasureTime(double &);                                  //returns the time in miliseconds of a process
        void write_endl(std::ofstream &, const int &, double &);     //write to a file using endl command
        void write(std::ofstream &, const int &, double &);          //write in a file using the newline character
        static void showDate(std::chrono::system_clock::time_point); //needs system clock instead of the high_resolution_clock because the hrc doesn't have converstion of time_point
        struct Process
        {
            double time1, time2;
            Process()
            {
                time1 = 0.0;
                time2 = 0.0;
            }
        };

    private:
        int n_data;
        double file_capacity;
        Process process;
        Process bandwidth;
    };

} // namespace io

#endif // IO_PERF
