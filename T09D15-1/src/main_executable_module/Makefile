all :
	gcc -Wall -Werror -Wextra ../data_libs/data_io.c main_executable_module.c ../data_libs/data_stat.c ../data_module/data_process.c ../yet_another_decision_module/decision.c ../data_libs/data_sort.c -lm -o ../../build/Quest_3
build_with_macro:
	gcc -Wall -Werror -Wextra -D MACRO_IO_DOUBLE main_executable_module.c ../data_libs/data_io_macro.c ../data_libs/data_stat.c ../data_module/data_process.c ../yet_another_decision_module/decision.c ../data_libs/data_sort.c -lm -o ../../build/Quest_4
clean:
	rm -rf ../../build
	mkdir ../../build
rebuild: 
	clean all data_stat.a build_with_static data_process.so build_with_dynamic

data_stat.a:
	gcc -Wall -Werror -Wextra -c ../data_libs/data_stat.c -o  data_stat.o
	ar rcs data_stat.a data_stat.o
	rm -f data_stat.o
build_with_static:
	make data_stat.a
	gcc -Wall -Werror -Wextra main_executable_module.c ../data_libs/data_io.c ../data_module/data_process.c ../yet_another_decision_module/decision.c ../data_libs/data_sort.c -lm -L. data_stat.a -o ../../build/Quest_5
	rm -f data_stat.a

data_process.so: ../data_module/data_process.c
	gcc -Wall -Wextra -Werror --std=c11 -shared -fPIC -o ../../build/data_process.so ../data_module/data_process.c
build_with_dynamic:
	make data_process.so
	gcc -Wall -Werror -Wextra main_executable_module.c ../data_libs/data_io.c ../data_libs/data_stat.c ../yet_another_decision_module/decision.c ../data_libs/data_sort.c -lm -L. ../../build/data_process.so -o ../../build/Quest_6