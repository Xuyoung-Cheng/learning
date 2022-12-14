OBJS := main.o cmd_ls.o cmd_cp.o cmd_handle.o
TARGET := tinyshell

$(TARGET) : $(OBJS)
	@gcc $^ -o $@
	@echo "Done."

%.o : %.c
	@gcc -c $< -o $@

clean :
	@rm -rf *.o $(TARGET)
