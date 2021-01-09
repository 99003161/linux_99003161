all: shm-read.c shm-write.c

read: shm_read.c shm.h
	gcc -o shm_read.out shm_read.c -lrt
	
write: shm_write.c shm.h
	gcc -o shm_write.out shm_write.c -lrt
	
runread:
	./shm_read.out

runwrite:
	./shm_write.out

clean:
	rm -rf *.out *.o
