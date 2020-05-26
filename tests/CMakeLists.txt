add_executable(io io.cc)

target_link_libraries(io LINK_PUBLIC io_perf)

install(DIRECTORY DESTINATION "output")

install(TARGETS io RUNTIME DESTINATION bin)
