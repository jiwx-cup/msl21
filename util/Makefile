.SUFFIXES: .C .o

C++ = g++

C++FLAGS = 

INC = -I/usr/local/lib/ -lm

OBJ = 

.C.o:
	$(C++) $(C++FLAGS) -c $< $(INC) 

all: torus cylinder sphere rectangle

torus: torus.C
	$(C++) $(C++FLAGS) torus.C -o torus $(INC) $(LIBS)

cylinder: cylinder.C
	$(C++) $(C++FLAGS) cylinder.C -o cylinder $(INC) $(LIBS)

sphere: sphere.C
	$(C++) $(C++FLAGS) sphere.C -o sphere $(INC) $(LIBS)

rectangle: rectangle.C
	$(C++) $(C++FLAGS) rectangle.C -o rectangle $(INC) $(LIBS)

clean:
	rm -f torus cylinder sphere rectangle
