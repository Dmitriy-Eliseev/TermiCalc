# TermiCalc
Simple console calculator with trigonometric functions

## Compilation
```
gcc termicalc.c tinyexpr.c -lm -O3 -o calc
```
or just use the make command
```
make
```

### Supported platforms
- Windows: tested on Windows 7, 8.1, 10, 11
- Linux: tested on Ubuntu 20.04, Linux Mint 21.3, Debian 10.13, OpenSuse Leap 15.4, Elbrus Linux 7.2 (e2k),
         Armbian 23.11(aarch64)
- BSD: tested on NetBSD 9.4, OpenBSD 7.4
## Usage
```
calc [expression ...]
```
```
calc [expression1] [expression2] [expression ...]
```
```
calc
```
If no expressions are specified, the program runs interactively and accepts expressions from the keyboard. To exit interactive mode, enter q.

If one or more expressions are specified, the program calculates them and displays the results on the screen.

To get help on the program, use one of the following parameters: "help", "--help", "h", "?" or enter "h" or "?" to the interactive mode line.
### Usage examples
![usage examples](https://github.com/Dmitriy-Eliseev/TermiCalc/blob/460feb58358f1bbe63a86ad54397155404dcd150/usage_examples.png)
