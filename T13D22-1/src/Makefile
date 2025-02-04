GCC=gcc
CFLAGS= -Wall -Wextra -Werror --std=c11

BUILD=../build

all:
	$(GCC) $(CFLAGS) cipher.c logger.c -o $(BUILD)/cipher
	$(GCC) $(CFLAGS) cipher.c logger.c -o $(BUILD)/logging_cipher

cipher:
	$(GCC) $(CFLAGS) cipher.c logger.c -o $(BUILD)/cipher
clean_cipher:
	rm -f $(BUILD)/cipher
rebuild_cipher: clean_1 cipher

logging_cipher:
	$(GCC) $(CFLAGS) cipher.c logger.c -o $(BUILD)/logging_cipher
clean_logging_cipher:
	rm -f $(BUILD)/logging_cipher
rebuild_logging_cipher: clean_1 logging_cipher