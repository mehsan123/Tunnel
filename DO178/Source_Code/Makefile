

SRCS = Cell.cpp Tunnel.cpp Systemdata.cpp Mountings.cpp Main.cpp Lamptype.cpp Lampmodel.cpp Lamp.cpp Datain.cpp Zone.cpp
OBJS = Cell.o Tunnel.o Systemdata.o Mountings.o Main.o Lamptype.o Lampmodel.o Lamp.o Datain.o Zone.o 

all: Cpp_tunnel_demo_Mingw.exe

Cpp_tunnel_demo_Mingw.exe: $(OBJS)
	@echo 'Building target: $@'
	g++ -o Cpp_tunnel_demo_Mingw.exe $(OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

clean:
	del $(OBJS) *.exh Cpp_tunnel_demo_Mingw.exe

%.o: %.cpp
	@echo 'Building file: $<'
	g++ -DCppOnly -c -o "$@" "$<"
