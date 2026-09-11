CXX = g++
CXXFLAGS = -O3 -Wall -std=c++11
TARGET = sorting_comp
SRCS = sorting.cpp algorithms/sort.cpp algorithms/mergesort.cpp algorithms/quicksort.cpp algorithms/patiencesort.cpp

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)