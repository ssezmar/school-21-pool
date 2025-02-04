GCC=gcc
CFLAGS= -Wall -Wextra -Werror --std=c11

BUILD=../build

print_module:
	$(GCC) $(CFLAGS) print_module.c main_module_entry_point.c -D Q1 -o $(BUILD)/Quest_1
clean_q1:
	rm -f $(BUILD)/Quest_1
rebuild_q1: clean_1 print_module

documentation_module:
	$(GCC) $(CFLAGS) print_module.c main_module_entry_point.c documentation_module.c -D Q2 -o $(BUILD)/Quest_2
clean_q2:
	rm -f $(BUILD)/Quest_2
rebuild_q2: clean_2 documentation_module

bst_create_test:
	$(GCC) $(CFLAGS) bst.c bst_create_test.c -o $(BUILD)/Quest_3
clean_q3:
	rm -f $(BUILD)/Quest_4
rebuild_q3: clean_3 bst_create_test

bst_insert_test:
	$(GCC) $(CFLAGS) bst.c bst_insert_test.c -o $(BUILD)/Quest_4
clean_q4:
	rm -f $(BUILD)/Quest_4
rebuild_q4: clean_3 bst_create_test

bst_traverse_test:
	$(GCC) $(CFLAGS) bst.c bst_traverse_test.c -o $(BUILD)/Quest_5
clean_q5:
	rm -f $(BUILD)/Quest_5
rebuild_q5: clean_3 bst_create_test