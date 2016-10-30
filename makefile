stats: stats.c
	gcc stats.c -o stats

run: stats
	./stats

clean:
	rm *~
	rm *.out
