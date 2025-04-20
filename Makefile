#My Name: Jordan Sowell
#My Class: CPSC 1020
#Date: 4/5/2025
#Time: 1 minute
#Description: Make a file

COMPILER = g++ -std=c++20
OPTIONS = -Wall
PROGRAM = main.out



all: $(PROGRAM)
	

run: $(PROGRAM)
	./$(PROGRAM)

$(PROGRAM): main.cpp course.cpp Student.cpp RecommendationSystem.cpp
	$(COMPILER) $(OPTIONS) main.cpp course.cpp Student.cpp RecommendationSystem.cpp -o $(PROGRAM)

clean:
	rm *.out