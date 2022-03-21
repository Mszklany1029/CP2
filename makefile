COURSE = cs240
SEMESTER = spring2022
CP_NUMBER = 1
LASTNAME = Szklany
GITUSERID = Mszklany1029
EXE = play

REPODIR = ../$(COURSE)-$(SEMESTER)-cp$(CP_NUMBER)-$(GITUSERID)
TARFILE = CP$(CP_NUMBER)_$(LASTNAME)_$(USER)_$(GITUSERID).tar

FLAGS = -Wall -Wextra -g
# FLAGS = -Wall -O3
CC = g++
BIN = bin
OBJ = obj

all: $(BIN)/$(EXE)

$(BIN)/$(EXE): $(OBJ)/Player.o $(OBJ)/Team.o $(OBJ)/League.o $(OBJ)/Play.o
	$(CC) $(FLAGS) $(OBJ)/Player.o $(OBJ)/Team.o $(OBJ)/League.o $(OBJ)/Play.o -o $@

$(OBJ)/Play.o: Play.cpp Player.h Team.h League.h
	$(CC) $(FLAGS) -c Play.cpp -o $@

$(OBJ)/League.o: League.cpp League.h Team.h Player.h
	$(CC) $(FLAGS) -c League.cpp -o $@

$(OBJ)/Team.o: Team.cpp Team.h Player.h
	$(CC) $(FLAGS) -c Team.cpp -o $@

$(OBJ)/Player.o: Player.cpp Player.h
	$(CC) $(FLAGS) -c Player.cpp -o $@

tar:	clean
	tar cvvf $(TARFILE) $(REPODIR)
	gzip $(TARFILE)

clean:
	rm -f $(OBJ)/*.o $(BIN)/$(EXE) *.tar.gz
