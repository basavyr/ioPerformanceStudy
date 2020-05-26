#include "../include/IO_perf.hh"

// static constexpr int n_data = 10000000;

static const std::string a_text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer nec odio. Praesent libero. Sed cursus ante dapibus diam. Sed nisi. Nulla quis sem at nibh elementum imperdiet.";

//get size of the array in bytes.
const size_t bytes = a_text.size();

std::ofstream file_1("../output/file1.dat");
std::ofstream file_2("../output/file2.dat");

//lambda function to compute the duration of a process
auto duration_ms = [](auto x, auto y) {
    return ((x - y) * 0.001);
};

io::IO_perf::IO_perf(const int N)
{
    start_time = std::chrono::high_resolution_clock::now();
    n_data = N;
    process.time1 = 0.0;
    process.time2 = 0.0;
    bandwidth.time1 = 0.0;
    bandwidth.time2 = 0.0;
    file_capacity = static_cast<double>(bytes * n_data * 0.000001); //in megabytes
    //write 1
    // start_time = std::chrono::high_resolution_clock::now();
    write(file_1, n_data, process.time1); //get the time execution for the function in ms
    // MeasureTime(process.time1);
    bandwidth.time1 = static_cast<double>((file_capacity) / (process.time1 * 0.001));

    //write 2
    // start_time = std::chrono::high_resolution_clock::now();
    write_endl(file_2, n_data, process.time2); //get the time execution of the function in ms
    // MeasureTime(process.time2);
    bandwidth.time2 = static_cast<double>((file_capacity) / (process.time2 * 0.001));
}

io::IO_perf::~IO_perf()
{
    auto end_time = std::chrono::high_resolution_clock::now();
    auto process_start = std::chrono::time_point_cast<std::chrono::microseconds>(start_time).time_since_epoch().count();
    auto process_end = std::chrono::time_point_cast<std::chrono::microseconds>(end_time).time_since_epoch().count();

    std::cout << "N= " << n_data << "\n";
    std::cout << "Total data (in MB) written to file: " << file_capacity << '\n';
    std::cout << "Benchmark finished..." << '\n';
    std::cout << "Writing the data into a file with newline char took: " << (process.time1) << " ms" << '\n';
    std::cout << "IO Bandwitdh: " << bandwidth.time1 << " MB/s" << '\n';
    std::cout << "Writing the data into a file with std::endl took: " << (process.time2) << " ms" << '\n';
    std::cout << "IO Bandwitdh: " << bandwidth.time2 << " MB/s" << '\n';

    std::cout << "Flushed " << n_data << " string streams in " << duration_ms(process_end, process_start) << " ms\n";
    file_1.close();
    file_2.close();
    //set a number of seconds for testing the sleep function of the thread
    // auto seconds = std::chrono::duration<int>(2);
    // std::this_thread::sleep_for(seconds);
}

void io::IO_perf::MeasureTime(double &exec)
{
    auto stop_time = std::chrono::high_resolution_clock::now();
    auto start = std::chrono::time_point_cast<std::chrono::microseconds>(start_time).time_since_epoch().count();
    auto stop = std::chrono::time_point_cast<std::chrono::microseconds>(stop_time).time_since_epoch().count();
    exec = std::forward<double>(duration_ms(stop, start)); //give time in ms
}

//returns also the execution time in ms
//method computes the time in micro-s
void io::IO_perf::write(std::ofstream &out, const int &n_data, double &execution)
{
    auto start = std::chrono::high_resolution_clock::now();
    // showDate(std::chrono::system_clock::now());
    for (int id = 0; id < n_data; ++id)
    {
        out << a_text << '\n';
    }
    out << std::endl;
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
    execution = static_cast<double>(duration * 0.001); //give time in ms
}

//returns also the execution time in ms
//method computes the time in micro-s
void io::IO_perf::write_endl(std::ofstream &out, const int &n_data, double &execution)
{
    auto start = std::chrono::high_resolution_clock::now();
    for (int id = 0; id < n_data; ++id)
    {
        out << a_text << std::endl;
    }
    out << std::endl;
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
    execution = static_cast<double>(duration * 0.001); //give time in ms
}

void io::IO_perf::showDate(std::chrono::system_clock::time_point tp)
{
    std::time_t currentTime = std::chrono::system_clock::to_time_t(tp);
    std::cout << std::ctime(&currentTime) << '\n';
}