UNAME_S := $(shell uname -s)
Darwin : main.cpp
	rm -f *.out
	@echo "Compiling for $(UNAME_S)"
	g++ -o monkey.out -w main.cpp -framework GLUT -framework OpenGL
	@echo "monkey.out created"
Linux : main.cpp
	rm -f *.out
	@echo "Compiling for $(UNAME_S)"
	g++ -o monkey.out -w main.cpp -lGL -lGLU -lglut -lm
	@echo "monkey.out created"
clean:
	@echo "There is an error in the program"
