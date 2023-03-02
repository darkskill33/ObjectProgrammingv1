main: v03VECfunc.o
	g++ -o v03VECmain v03VECmain.cpp v03VECfunc.o
v03VECfunc: 
	g++ -c v03VECfunc.cpp
clean:
	del *.o v03VECmain