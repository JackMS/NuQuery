SE_PREFIX = $(HOME)/se

CFLAGS = -g -O2 -Wall
CPPFLAGS = -I$(SE_PREFIX)/include
LDFLAGS = -L$(SE_PREFIX)/lib -Wl,-rpath=$(SE_PREFIX)/lib
LDLIBS = -lse

.PHONY: clean

burn_query: nuquery.o

clean:
	-$(RM) nuquery *.o
