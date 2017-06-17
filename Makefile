compila: main.cpp src/memory.cpp src/screen.cpp src/descriptor_table.cpp src/directory_table.cpp src/ram_file_table.cpp src/workflow.cpp
	gcc -o SO main.cpp src/memory.cpp src/screen.cpp src/descriptor_table.cpp src/directory_table.cpp src/ram_file_table.cpp src/workflow.cpp -Wall -Wno-write-strings
