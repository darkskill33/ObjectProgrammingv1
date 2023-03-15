main: v04VECfunc.o
	g++ -o3 -o main v04VECmain.cpp v04VECfunc.o
v03VECfunc: 
	g++ -o3 -c v04VECfunc.cpp
clean:
	del *.o main