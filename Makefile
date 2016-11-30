CC      =g++
SIGN    =-std=c++0x
OBJS    =bmp.o test.o rgb.o
NAME    =test.out
$(NAME):$(OBJS)
	$(CC) $(SIGN) $(OBJS) -o $(NAME)
test.o:test.cpp
	$(CC) $(SIGN) -c test.cpp
bmp.o:src/bmp.h src/bmp.cpp
	$(CC) $(SIGN) -c src/bmp.cpp
rgb.o:src/rgb.h src/rgb.cpp
	$(CC) $(SIGN) -c src/rgb.cpp
.PHONY: clean
clean:
	rm -f $(OBJS)