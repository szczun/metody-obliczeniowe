CXX = g++

FLAGS = -lboost_iostreams -Wl,-rpath,/lib/x86_64-linux-gnu

TARGET = main

SRC = main.cpp

all: clean $(TARGET)

clean: 
	rm -f $(TARGET)

$(TARGET): $(SRC)
	$(CXX) -o $(TARGET) $(SRC) $(FLAGS) 



