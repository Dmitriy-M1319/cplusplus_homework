CC = g++
CXXFLAGS = -g -Wall -Wextra -pedantic
BUILD_DIR = ./build
OBJS = $(BUILD_DIR)/insects.o $(BUILD_DIR)/anthill.o

my_anthill: $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS) main.cpp -o $(BUILD_DIR)/my_anthill

tests: $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS) insects_tests.cpp -o $(BUILD_DIR)/insects_tests
	$(CC) $(CXXFLAGS) $(OBJS) anthill_tests.cpp -o $(BUILD_DIR)/anthill_tests

$(BUILD_DIR)/insects.o: insects.cpp
	$(CC) $(CXXFLAGS) -c insects.cpp -o $(BUILD_DIR)/insects.o

$(BUILD_DIR)/anthill.o: anthill.cpp
	$(CC) $(CXXFLAGS) -c anthill.cpp -o $(BUILD_DIR)/anthill.o

