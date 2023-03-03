main: v03VECfunc.o
	g++ -o3 -o main v03VECmain.cpp v03VECfunc.o
v03VECfunc: 
	g++ -o3 -c v03VECfunc.cpp
clean:
	del *.o main