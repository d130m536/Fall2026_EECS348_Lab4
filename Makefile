# compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11
# enables common warnings, enables extra warnings, compiles using C11 standard

# list of compiled object files to build lab 4 program
# OBJECTS = nfl_score.o temp_conv.o

# final exe file name
# TARGET = lab_four

# final exe file names, one per task
TARGET1 = nfl_score
TARGET2 = temp_conv

# default target when running make
# all: $(TARGET)

# default target when running make: build both executables
all: $(TARGET1) $(TARGET2)

# each task is its own program, built from its own single .o file -
# no shared OBJECTS list, since each has its own main() and can't be
# linked into the same binary as the other
# link all objects into final binary
# $(TARGET): $(OBJECTS)
#	$(CC) $(CFLAGS) -o $@ $^
# $@ = automatic variable for target name
# $^ = automatic variable for all prerequisites (.o files)

# link nfl_score.o into its exe
$(TARGET1): nfl_score.o
	$(CC) $(CFLAGS) -o $@ $^

# link temp_conv.o into its exe
$(TARGET2): temp_conv.o
	$(CC) $(CFLAGS) -o $@ $^

# pattern rule tells make how to compile any source file (.c) into object (.o) 
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
# $< = first prerequisite file (i.e. nfl_score.c)

# remove .o files and both executables
clean:
	rm -rf *.o $(TARGET1) $(TARGET2)

# defining comments are for personal future reference :)
# commented out code is for one single exe file "lab_four"
