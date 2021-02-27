# Archivo make para crear el programa para tirar dados
# usando bibliotecas compartidas
CFLAGS = -O
OBJS = lst22-01.o
LIBS = libtirar.so

all: dado

dado: $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) -L. -ltirar

lst22-01.o: lst22-01.cxx
	$(CC) -c lst22-01.cxx

lst22-02.o: lst22-02.cxx
	$(CC) -fPIC -c $<

libtirar.so: lst22-02.o
	$(RM) libtirar*
	$(CC) -shared -Wl,-soname,libtirar.so.1 \
	-o libtirar.so.1.o $<
	ln -s libtirar.so.1.o libtirar.so.1
	ln -s libtirar.so.1 libtirar.so

 clean:
	$(RM) dado *.o libtirar*
