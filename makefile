CC=gcc
LIBNAME=libhw7
LIB=$(LIBNAME).so.1.0
CFLAGS=-Wall
OBJS1= print.o register.o search.o sort.o delete.o
OBJS2= hw7Main.o
INCDIR=.
LIBDIR=.
all:main
$(LIB): $(OBJS1)
	$(CC) -fPIC -shared -Wl,-soname,$(LIBNAME).so.1 $(OBJS1) -o $@ -lc
	ln -sf $(LIBNAME).so.1.0 $(LIBNAME).so
	ln -sf $(LIBNAME).so.1.0 $(LIBNAME).so.1
%.o:%.c
	$(CC) -fPIC -c $(CFLAGS) -I$(INCDIR) -o $@ $<

main: $(LIB) $(OBJS2)
	$(CC) -o main $(OBJS2) -L$(LIBDIR) -lhw7
clean:
	-rm -rf $(OBJS1) $(OBJS2) $(LIB) $(LIBDIR)/$(LIBNAME).so* main 

