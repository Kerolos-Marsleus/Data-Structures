CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -g -fsanitize=address
CPPFLAGS := -I../Task05_Linked_list

SRCS := main.cpp \
        02_Queue_ll.cpp \
        ../Task05_Linked_list/01_LC707_Singly_Linked_List.cc

HDRS := 02_Queue_ll.hpp \
        ../Task05_Linked_list/01_LC707_Singly_Linked_List.hpp

TARGET := queue.out

$(TARGET): $(SRCS) $(HDRS)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(SRCS) -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: run clean