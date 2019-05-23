all: datos.dat SanchezMiguel_final_15.pdf

%.pdf: %.dat GFinal.py
	python3 GFinal.py

%.dat: a.out
	./a.out

a.out: Final.cpp
	g++ Final.cpp -o a.out

clean:
	rm -rf *.out *.dat *.pdf
