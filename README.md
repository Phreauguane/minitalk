# Minitalk

Minitalk is a simple communication program in the form of a client and a server. Communications between the client and the server are done using UNIX signals SIGUSR1 and SIGUSR2 (more about that on the links below).

### How to use it ?

Clone this repository on your device.

Open a terminal in the repository.

Run `make all`.

Then you can start the server using `./server`.

The server will print his PID.

Then run he client with `./client <server_pid> <message>`.

### how i works ?

As I said, this program uses UNIX signals to communicate. 

The client sends data to the server bit by bit using SIGUSR1 for 1 and SIGUSR2 for 0.

After each signal is sent the client waits for the server's confirmation.
(a limit of 50ms per bit is set, after that the client exits with an error)

### usefull links :

https://medium.com/@oduwoledare/42-minitalk-explained-5b236adc2c24

https://www.youtube.com/watch?v=83M5-NPDeWs
