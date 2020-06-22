
all:
	echo "hey there" >runme ; gcc final_server.c -c;objcopy --add-section .RUN_ME=runme --set-section-flags .RUN_ME=noload,readonly -O elf64-x86-64 final_server.o server2.o; gcc server2.o -o final_server


clean:
	rm -rf *.o

.PHONY: all clean