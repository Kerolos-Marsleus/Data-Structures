CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -g -fsanitize=address
CPPFLAGS := -I../Task05_Linked_list

SRCS := main.cpp \
        01_Stack_Array.cc \
        02_Stack_ll.cpp \
        ../Task05_Linked_list/01_LC707_Singly_Linked_List.cc

HDRS := 01_Stack_Array.hpp \
        02_Stack_ll.hpp \
        ../Task05_Linked_list/01_LC707_Singly_Linked_List.hpp

TARGET := stack.out

$(TARGET): $(SRCS) $(HDRS)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(SRCS) -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: run clean