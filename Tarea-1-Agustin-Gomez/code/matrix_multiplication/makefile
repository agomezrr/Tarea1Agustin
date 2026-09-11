CXX = g++
CXXFLAGS = -O3 -Wall -std=c++11
TARGET = matrix_mult
SRCS = matrix_multiplication.cpp algorithms/naive.cpp algorithms/strassen.cpp

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)