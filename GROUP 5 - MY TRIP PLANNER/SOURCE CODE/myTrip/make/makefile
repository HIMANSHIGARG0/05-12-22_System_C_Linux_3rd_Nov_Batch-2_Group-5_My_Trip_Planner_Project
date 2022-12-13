CC = gcc
INC = include
SRC = src
OBJ = obj
BIN = bin

CFLAGS = -c -g -Wall
OFLAGS = -lm -o
IFLAGS = -I $(INC)

VFLAGS = v --tool=memcheck --leak-check=yes --show-reachable=yes

EXECS = $(BIN)/myTrip


$(BIN)/myTrip:$(OBJ)/main.o $(OBJ)/destinations.o $(OBJ)/hotels.o $(OBJ)/register.o
	$(CC) $(OFLAGS)myTrip $(OBJ)/main.o $(OBJ)/destinations.o $(OBJ)/hotels.o $(OBJ)/register.o
	mv myTrip $(BIN)

$(OBJ)/main.o: $(SRC)/main.c $(INC)/destinations.h
	$(CC) $(CFLAGS) $(SRC)/main.c $(IFLAGS)
	mv main.o $(OBJ)

$(OBJ)/destinations.o:$(SRC)/destinations.c $(INC)/destinations.h
	$(CC) $(CFLAGS) $(SRC)/destinations.c $(IFLAGS)
	mv destinations.o $(OBJ)

$(OBJ)/hotels.o:$(SRC)/hotels.c $(INC)/hotels.h
	$(CC) $(CFLAGS) $(SRC)/hotels.c $(IFLAGS)
	mv hotels.o $(OBJ)

$(OBJ)/register.o:$(SRC)/register.c $(INC)/register.h
	$(CC) $(CFLAGS) $(SRC)/register.c $(IFLAGS)
	mv register.o $(OBJ)

clean:
	rm -f $(OBJ)/*.o
	rm -f $(BIN)/myTrip
	@echo "Cleaning Done!"

valgrind:$(EXECS)
	        valgrind $(VFLAGS) $(BIN)/myTrip


