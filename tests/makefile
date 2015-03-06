OBJS = testMain.o Tournament.o TournamentTester.o
SRCS = main.cpp  TournamentTester.cc
CC = g++11
CFLAGS = -Wall -g -std=c++11 -lcppunit -ldl


testMain: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ -lcppunit -ldl

Tournament.o: ../source/Tournament.cc
	$(CC) $(CFLAGS) -c $<

%.o: %.cc
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o *~ *% *# .#* *.gcov *.gcno *.gcda


clean-all:
	rm -f *.o *~ *% *# .#* *.gcov *.gcno *.gcda
	rm testMain