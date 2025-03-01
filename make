# Compiler and flags
CC = cc68x
AS = gen
CFLAGS = -g -c
LDFLAGS = -g
RM = rm

# Source files and objects
SRCS = model.c event.c tst_s3.c
OBJS = model.o event.o tst_s3.o
EXEC = tst_s3

# Default target
all: $(EXEC)

# Linking
$(EXEC): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(EXEC)

# Compiling C files
model.o: model.c model.h
	$(CC) $(CFLAGS) -o model.o model.c

event.o: event.c model.h
	$(CC) $(CFLAGS) -o event.o event.c

tst_s3.o: tst_s3.c model.h
	$(CC) $(CFLAGS) -o tst_s3.o tst_s3.c

# Clean rule
clean:
	$(RM) -f *.o $(OBJS) $(EXEC)
