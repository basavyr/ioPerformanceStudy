#include "../include/IO_perf.hh"

void run_IO_test(const int N)
{
    auto x = std::make_unique<io::IO_perf>(N);
}

void run_fixed_size_test(const int N, int reps)
{
    for (auto id = 0; id < reps; ++id)
        auto x = std::make_unique<io::IO_perf>(N);
}

void run_uninterrupted_test(const int N)
{
    for (;;)
        auto x = std::make_unique<io::IO_perf>(N);
}

int main()
{
    int N = 1000000;
    int reps = 100;
    // int it = 1;
    // while (N)
    // {

    //     std::cout << "**********Test " << it << "**********" << '\n';
    //     run_IO_test(N);
    //     N = N / 10;
    //     it++;
    // }
    run_fixed_size_test(N, reps);
}