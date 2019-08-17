all: primitives hline1 vline1 rectangle1 square2 squarerectangle1 line1
	echo "Finished"
	
primitives: primitives/hline.o primitives/vline.o primitives/xynormsquare.o primitives/xynormrectangle.o primitives/line.o
	gcc -o primitives/hline.o -c primitives/hline.c -I./primitives/
	gcc -o primitives/vline.o -c primitives/vline.c -I./primitives/
	gcc -o primitives/xynormsquare.o -c primitives/xynormsquare.c -I./primitives/
	gcc -o primitives/xynormrectangle.o -c primitives/xynormrectangle.c -I./primitives/
	gcc -o primitives/line.o -c primitives/line.c -I./primitives/

hline1: primitives
	gcc -o hline1/main.o -c hline1/main.c -I./primitives/
	gcc -o hline1/hline1 hline1/main.o primitives/hline.o -I./primitives/ `pkg-config --cflags --libs sdl2`

vline1: primitives
	gcc -o vline1/main.o -c vline1/main.c -I./primitives/
	gcc -o vline1/vline1 vline1/main.o primitives/vline.o -I./primitives/ `pkg-config --cflags --libs sdl2`

rectangle1: primitives
	gcc -o rectangle1/main.o -c rectangle1/main.c -I./primitives/
	gcc -o rectangle1/rectangle1 rectangle1/main.o primitives/xynormrectangle.o primitives/hline.o primitives/vline.o -I./primitives/ `pkg-config --cflags --libs sdl2`

square2: primitives
	gcc -o square2/main.o -c square2/main.c -I./primitives/
	gcc -o square2/square2 square2/main.o primitives/xynormsquare.o primitives/hline.o primitives/vline.o -I./primitives/ `pkg-config --cflags --libs sdl2`

squarerectangle1: primitives
	gcc -o squarerectangle1/main.o -c squarerectangle1/main.c -I./primitives/
	gcc -o squarerectangle1/squarerectangle1 squarerectangle1/main.o primitives/hline.o primitives/vline.o -I./primitives/ `pkg-config --cflags --libs sdl2`

line1: primitives
	gcc -o line1/main.o -c line1/main.c -I./primitives/
	gcc -o line1/line1 line1/main.o primitives/line.o -I./primitives/ `pkg-config --cflags --libs sdl2`


clean:
	rm -f primitives/hline.o primitives/vline.o primitives/xynormsquare.o primitives/xynormrectangle.o primitives/line.o hline1/hline1 hline1/main.o vline1/vline1 vline1/main.o rectangle1/rectangle1 rectangle1/main.o square2/square2 square2/main.o squarerectangle1/squarerectangle1 squarerectangle1/main.o line1/line1 line1/main.o
 
