CFLAGS=-Wall -ggdb

local_history: localHistory.o stats.o smithCounter.o branchHistoryRegister.o
	g++ -o global_history $(CFLAGS) localHistory.o stats.o smithCounter.o branchHistoryRegister.o

branchHistoryRegister.o: branchHistoryRegister.cpp branchHistoryRegister.h
	g++ $(CFLAGS) -c branchHistoryRegister.cpp -o branchHistoryRegister.o

smithCounter.o: smithCounter.cpp smithCounter.h
	g++ $(CFLAGS) -c smithCounter.cpp -o smithCounter.o

stats.o: stats.cpp stats.h
	g++ $(CFLAGS) -c stats.cpp -o stats.o

localHistory.o: localHistory.cpp branchHistoryRegister.h stats.h smithCounter.h
	g++ $(CFLAGS) -c localHistory.cpp -o localHistory.o

clean:
	rm -f local_history *.o
