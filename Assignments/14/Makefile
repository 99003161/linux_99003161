all: assignment15serv.c assignment15client.c

Server: assignment15serv.c clientserver.h
	gcc -o assignment15serv.out assignment15serv.c -lrt
	
Client: assignment15client.c clientserver.h
	gcc -o assignment15client.out assignment15client.c -lrt
	
runClient:
	./assignment15client.out

runServer:
	./assignment15serv.out

clean:
	rm -rf *.out *.o
