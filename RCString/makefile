CPP = g++ -std=c++11 
CPPFLAGS = -g -pedantic-errors -Wall -Wextra
#CPPFLAGS = -g -Wall -Wextra

TARGET = outDebug

OBJ = main.o RCString.o

$(TARGET): $(OBJ)
	$(CPP) $(CPPFLAGS) -o $(TARGET) $(OBJ)

main.o: main.cpp RCString.hpp
	$(CPP) $(CPPFLAGS) -c main.cpp

SimpleString.o: RCString.cpp RCString.hpp
		$(CPP) $(CPPFLAGS) -c RCString.cpp

cl:
	rm -f $(OBJ) $(TARGET)
	clear
run:
	./$(TARGET)
vlg:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)


