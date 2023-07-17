# stop_thread_example

This is a toy project to demonstrate a user-stoppable worker thread in C++. The implementation took help from Chat-GPT and Github Copilot.

## Build

```bash
mkdir build
cd build
cmake ..
make
```

## Run

```bash
cd build
./stop_thread_example
```


## Example output

### Basic navigation

```bash
❯ ./stop_thread_example
Worker thread is already running.
(2023-07-16 19:53:06) (0x1e0ba9e00) Enter a command: 
help
Available commands: help, whoami, start, stop, quit
(2023-07-16 19:53:08) (0x1e0ba9e00) Enter a command: 
whoami
You are the user
(2023-07-16 19:53:10) (0x1e0ba9e00) Enter a command: 
(2023-07-16 19:53:16) (0x16bc8b000) Working...
(2023-07-16 19:53:26) (0x16bc8b000) Working...
(2023-07-16 19:53:36) (0x16bc8b000) Working...
(2023-07-16 19:53:46) (0x16bc8b000) Working...
```

### Controlling the worker thread

```bash
(2023-07-16 19:54:08) (0x1e0ba9e00) Enter a command: 
stop
(2023-07-16 19:54:10) (0x1e0ba9e00) Enter a command: 
start
(2023-07-16 19:54:16) (0x1e0ba9e00) Enter a command: 
start
Worker thread is already running.
(2023-07-16 19:54:19) (0x1e0ba9e00) Enter a command: 
(2023-07-16 19:54:26) (0x16bc8b000) Working...
stop
(2023-07-16 19:54:29) (0x1e0ba9e00) Enter a command: 
quit

```


## How to verify the number of threads

I didn't get the `htop` to correctly show threads on my M1 Mac. So I ended up using `ps -M <pid>`.

By using `man ps`, we can see:

`-M      Print the threads corresponding to each task.`

After the worker thread was started:

```bash
PID   TT   %CPU STAT PRI     STIME     UTIME COMMAND
<pid> s000    0.0 S    31T   0:00.00   0:00.00 ./stop_thread_example
<pid>         0.0 S    31T   0:00.00   0:00.00 
```

After the worker thread was stopped:

```bash
PID   TT   %CPU STAT PRI     STIME     UTIME COMMAND
<pid> s000    0.0 S    31T   0:00.00   0:00.00 ./stop_thread_example

```
