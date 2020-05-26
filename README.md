# IO Performance Study

Different performance measurements for IO streams in C++ 

IO performance measurements:
 1. Measure time execution of IO stream buffer
 2. Measure and compare IO writing time of `“\n”` with `std::endl`
 3. [optional] Compare serial vs. parallel algorithm for writing to file

The project is built with CMake and there is an integration with CircleCI for CI/CD workflow.

Some useful guides in working with timing functions:

* [How to get duration, as int milli's and float seconds from `chrono?`](https://stackoverflow.com/questions/14391327/how-to-get-duration-as-int-millis-and-float-seconds-from-chrono)

## Benchmark results

Results can be seen [here](benchmarks.md).