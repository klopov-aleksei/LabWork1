TARGET = start
CXX = g++
CXXFLAGS = -I. -std=c++17 -g -fPIC -Wall -Werror -Wpedantic -O2
SRCS = main.cpp bmp_reader.cpp rotation.cpp filters.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^
  
%.o: %.cpp bmp_reader.h
	$(CXX) $(CXXFLAGS) -c $< -o $@
  
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
