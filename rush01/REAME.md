# rush01
System monitoring program

### About this project
* This is a Rushes project at [École 42](https://42.fr)
* Rushes project is a 2 days group project on weekend.
* My teammate is Abdallah Achir.
* The objective of this project is to create a system monitoring program which can show the system information:
	* Hostname/Username
	* OS
	* Date/Time
	* CPU
	* RAM
	* Network
* My teammate work on finding a way to get the system data and I work on everything else.
* We have 2 mode for this: shell mode with ncurses and graphic mode with [SFML](https://www.sfml-dev.org/).

![shell mode](screenshots/screenshot1.png?raw=true)
![graphic mode](screenshots/screenshot2.png?raw=true)

### How to run the program
* [SFML](https://www.sfml-dev.org/) is required. You can install it with Brew.
	```
	brew install sfml
	```
* Run make command, this will create an executable file ft_gkrellm.
	```
	make
	```
* To run with shell mode
	```
	./ft_gkrellm
	```
* To run with graphic mode
	```
	./ft_gkrellm -graphic
	```
