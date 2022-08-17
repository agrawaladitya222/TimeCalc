
TimeCalc : TimeCalc.c
	gcc -std=c17 -Wextra -Wall -Wpedantic -o TimeCalc TimeCalc.c

test : tester.c
	gcc -std=c17 -Wextra -Wall -Wpedantic -o test tester.c

clean:
	rm -rf TimeCalc test *.o