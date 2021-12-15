CC=gcc
AR=ar
OBJECTS_MAIN = main.o
OBJECTS_LIB = my_func.o
FLAGS= -Wall -g
EXE=libclass.so progmaind

#target commands
all: $(EXE)

progmaind: $(OBJECTS_MAIN) 
	$(CC) $(FLAGS) -o progmaind $(OBJECTS_MAIN) ./libclass.so  -lm
progmains: $(OBJECTS_MAIN) libclass.a
	$(CC) $(FLAGS) -o progmains $(OBJECTS_MAIN) libclass.a  -lm

static: libclass.a
dynamic: libclass.so


#shared libs
libclass.so: $(OBJECTS_LIB)
	$(CC) -shared -o libclass.so $(OBJECTS_LIB)

#static libs
libclass.a: $(OBJECTS_LIB)
	$(AR) -rcs libclass.a $(OBJECTS_LIB)


#objects
my_func.o: my_func.c my_func.h
	$(CC) $(FLAGS) -c my_func.c
main.o: main.c my_func.h  
	$(CC) $(FLAGS) -c main.c 

.PHONY: clean all

clean:
	rm -f *.o *.a *.so $(EXE)