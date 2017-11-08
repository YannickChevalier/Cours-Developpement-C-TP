MODULES:=entrees operations


INCLUDE_PATH:= ../../include
LIBRARY_PATH:= ../../lib
CFLAGS:=-Wall -g -I $(INCLUDE_PATH) -L$(LIBRARY_PATH)

TEST_BIN:=$(patsubst %,test_%,$(MODULES))

%.o: %.c $(INCLUDE_PATH)/%.h
	gcc $(CFLAGS) -c $< -o $@


test_%: test_%.c %.o
	gcc $(CFLAGS) -o $@ test_$(*).c $(*).o

test: $(TEST_BIN)
	for i in $(TEST_BIN) ; do \
		./$$i ; \
	done	

clean:
	-\rm *~ *.o $(TEST_BIN)
