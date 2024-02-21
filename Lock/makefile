CPP = g++ -std=c++11 
#CPPFLAGS = -g -pedantic-errors -Wall -Wextra
CPPFLAGS = -g -Wall -Wextra
PRODUCTION = -pedantic-errors -Wall -Wextra
TARGET = outDebug
CLASSNAME = Lock
OBJ = main.o $(CLASSNAME).o

$(TARGET): $(OBJ)
	$(CPP) $(CPPFLAGS) -o $(TARGET) $(OBJ)

main.o: main.cpp $(CLASSNAME).hpp
	$(CPP) $(CPPFLAGS) -c main.cpp

SimpleString.o: $(CLASSNAME).cpp $(CLASSNAME).hpp
		$(CPP) $(CPPFLAGS) -c $(CLASSNAME).cpp

cl:
	rm -f $(OBJ) $(TARGET)
	clear
run:
	./$(TARGET)
vlg:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)
dump:
	objdump -d $(TARGET) > dump.txt
sym:
	nm $(TARGET)
# strings outDebug #useful to see all
# readelf --symbols a.out
# readelf -s a.out
#objdump -t a.out