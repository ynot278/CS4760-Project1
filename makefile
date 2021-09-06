CC = g++

driver: main.cpp driver.h
	$(CC) -g main.cpp driver.h -o driver

clean:
	rm -f *.o driver