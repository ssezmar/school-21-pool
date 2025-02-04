CC=gcc
CFLAGS= -Wall -Wextra -Werror --std=c11

BUILD=../build

all: door_struct list_test

door_struct: dmanager_module.o
	$(CC) $(CFLAGS) -o $(BUILD)/Quest_1 $(BUILD)/dmanager_module.o

rebuild_door_test: clean door_test

list_test: list_test.o list.o
	$(CC) $(CFLAGS) -o $(BUILD)/Quest_2 $(BUILD)/list_test.o $(BUILD)/list.o

rebuild_list_test: clean list_test

list.o: list.c
	$(CC) $(CFLAGS) -c -o $(BUILD)/list.o list.c

list_test.o: list_test.c
	$(CC) $(CFLAGS) -c -o $(BUILD)/list_test.o list_test.c

stack_test: stack_test.o stack.o
	$(CC) $(CFLAGS) -o $(BUILD)/Quest_3 $(BUILD)/stack_test.o $(BUILD)/stack.o

rebuild_stack_test: clean stack_test

stack.o: stack.c
	$(CC) $(CFLAGS) -c -o $(BUILD)/stack.o stack.c

stack_test.o: stack_test.c
	$(CC) $(CFLAGS) -c -o $(BUILD)/stack_test.o stack_test.c

dmanager_module.o: dmanager_module.c
	$(CC) $(CFLAGS) -c -o $(BUILD)/dmanager_module.o dmanager_module.c

clean:
	rm -rf $(BUILD)
	mkdir $(BUILD)

rebuild: clean all
