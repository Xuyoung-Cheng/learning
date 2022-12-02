CC := gcc

TARGET := main_exec
OBJECT := main.o fun.o

$(TARGET) : $(OBJECT)
	$(CC) $^ -o $@

%.o : %.c
	$(CC) -c $< -o $@

clean:
	rm -rf *.o main_exec
