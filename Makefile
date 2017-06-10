compila: main.cpp src/disk.cpp src/ram.cpp src/screen.cpp src/descriptor_table.cpp src/directory_table.cpp
	g++ -o SO main.cpp src/disk.cpp src/ram.cpp src/screen.cpp src/descriptor_table.cpp src/directory_table.cpp -Wall
