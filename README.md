## Design and implement a log system with different log levels that can output messages to the console window.

# Requirements

1) Support the next log levels: info, debug, warning and error. The client of the code shouldnot be able to define its own log levels;
2) Support only logging to the console window, no other output is needed (no output files only console);
3) Support a multi-threaded environment, where several threads could log simultaneously;
4) The client should be able to set a custom prefix, it appends automatically to each message;
5) Each log message should start with the date and time (no requirements to the format).