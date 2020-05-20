all: primitives hline1 vline1 rectangle1 rectanglecollision1 square2 squarerectangle1 line1 circle1 circlefill1
	echo "Finished"
	
primitives: primitives/hline.o primitives/vline.o primitives/xynormsquare.o primitives/xynormrectangle.o primitives/line.o primitives/rectanglecollision.o primitives/circle.o primitives/circlefill.o
	gcc -o primitives/hline.o -c primitives/hline.c -I./primitives/
	gcc -o primitives/vline.o -c primitives/vline.c -I./primitives/
	gcc -o primitives/xynormsquare.o -c primitives/xynormsquare.c -I./primitives/
	gcc -o primitives/xynormrectangle.o -c primitives/xynormrectangle.c -I./primitives/
	gcc -o primitives/line.o -c primitives/line.c -I./primitives/
	gcc -o primitives/rectanglecollision.o -c primitives/rectanglecollision.c -I./primitives/ `pkg-config --cflags sdl2`
	gcc -o primitives/circle.o -c primitives/circle.c -I./primitives/ -lm
	gcc -o primitives/circlefill.o -c primitives/circlefill.c -I./primitives/ -lm

hline1: primitives
	gcc -o hline1/main.o -c hline1/main.c -I./primitives/
	gcc -o hline1/hline1 hline1/main.o primitives/hline.o -I./primitives/ `pkg-config --cflags --libs sdl2`

vline1: primitives
	gcc -o vline1/main.o -c vline1/main.c -I./primitives/
	gcc -o vline1/vline1 vline1/main.o primitives/vline.o -I./primitives/ `pkg-config --cflags --libs sdl2`

rectangle1: primitives
	gcc -o rectangle1/main.o -c rectangle1/main.c -I./primitives/
	gcc -o rectangle1/rectangle1 rectangle1/main.o primitives/xynormrectangle.o primitives/hline.o primitives/vline.o primitives/rectanglecollision.o -I./primitives/ `pkg-config --cflags --libs sdl2`
	
rectanglecollision1: primitives
	gcc -o rectanglecollision1/main.o -c rectanglecollision1/main.c -I./primitives/
	gcc -o rectanglecollision1/rectanglecollision1 rectanglecollision1/main.o primitives/xynormrectangle.o primitives/hline.o primitives/vline.o primitives/rectanglecollision.o -I./primitives/ `pkg-config --cflags --libs sdl2`

square2: primitives
	gcc -o square2/main.o -c square2/main.c -I./primitives/
	gcc -o square2/square2 square2/main.o primitives/xynormsquare.o primitives/hline.o primitives/vline.o -I./primitives/ `pkg-config --cflags --libs sdl2`

squarerectangle1: primitives
	gcc -o squarerectangle1/main.o -c squarerectangle1/main.c -I./primitives/
	gcc -o squarerectangle1/squarerectangle1 squarerectangle1/main.o primitives/vline.o primitives/hline.o primitives/xynormrectangle.o -I./primitives/ `pkg-config --cflags --libs sdl2`

line1: primitives
	gcc -o line1/main.o -c line1/main.c -I./primitives/
	gcc -o line1/line1 line1/main.o primitives/line.o -I./primitives/ `pkg-config --cflags --libs sdl2`

circle1: primitives
	gcc -o circle1/main.o -c circle1/main.c -I./primitives/
	gcc -o circle1/circle1 circle1/main.o primitives/circle.o -I./primitives/ `pkg-config --cflags --libs sdl2` -lm

circlefill1: primitives
	gcc -o circlefill1/main.o -c circlefill1/main.c -I./primitives/
	gcc -o circlefill1/circlefill1 circlefill1/main.o primitives/circlefill.o -I./primitives/ `pkg-config --cflags --libs sdl2` -lm

clean:
	rm -f primitives/hline.o primitives/vline.o primitives/xynormsquare.o primitives/xynormrectangle.o primitives/line.o primitives/rectanglecollision.o primitives/circle.o primitives/circlefill.o hline1/hline1 hline1/main.o vline1/vline1 vline1/main.o rectangle1/rectangle1 rectangle1/main.o square2/square2 square2/main.o squarerectangle1/squarerectangle1 squarerectangle1/main.o line1/line1 line1/main.o rectanglecollision1/rectanglecollision1 rectanglecollision1/main.o circle1/circle1 circle1/main.o circlefill1/circlefill1 circlefill1/main.o
