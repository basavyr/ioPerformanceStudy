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

## Fixed issues:

1. The `centos:latest` container needs *Development Tools* and not just *gcc*, otherwise it will complain on building the project with `CMake`.
2. The `ubuntu:latest` container needs the environment variables to be declared in the command line:

```yaml
 - run:
    name: "set env vars again"
    command: |
            echo 'debconf debconf/frontend select Noninteractive' | debconf-set-selections
            echo export DEBIAN_FRONTEND=noninteractive >> $BASH_ENV
            source $BASH_ENV
```

Guide for implementing the environment variables into command line after container was properly set up can be found [here](https://circleci.com/docs/2.0/env-vars/#setting-an-environment-variable-in-a-shell-command)