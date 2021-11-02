.PHONY: loops recursived clean
CC = gcc
AR = ar
loopFails = basicClassification.o advancedClassificationLoop.o
recFails = basicClassification.o advancedClassificationRecursion.o
FLAGS= -Wall -g
all: recursived loopd recursives loops mains maindloop maindrec
mains: main.o libclassrec.a
	$(CC) $(FLAGS)  -o mains main.o libclassrec.a -lm
maindloop: main.o libclassloops.so 
	$(CC) $(FLAGS)  -o maindloop main.o ./libclassloops.so -lm
maindrec: main.o libclassrec.so 
	$(CC) $(FLAGS)  -o maindrec main.o ./libclassrec.so -lm
loops: $(loopFails)
	$(AR) -rcs libclassloops.a $(loopFails)
recursives: $(recFails)
	$(AR) -rcs libclassrec.a $(recFails)
loopd: $(loopFails)
	$(CC) -shared -o libclassloops.so $(loopFails) -lm 
recursived: $(recFails)
	$(CC) -shared -o libclassrec.so $(recFails) -lm
basicClassification.o: basicClassification.c NumClass.h 
	$(CC) $(FLAGS) -c basicClassification.c -lm
advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationLoop.c -lm
main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c main.c
clean:
	rm -f *.o *.a *.so maindloop maindrec mains