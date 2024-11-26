CC := g++ -std=c++23 -Wall -O2

all:  example gmp_adaptor.so

gmp_adaptor.so: gmp_adaptor.cc gmp_adaptor.hh
	 $(CC) -shared -fPIC -o $@ $<

cpoly.hh: cpoly_single.hh cpoly_multi.hh gmp_adaptor.cc gmp_adaptor.hh
	touch cpoly.hh

example: example.cc cpoly.hh gmp_adaptor.so
	$(CC) -o $@ $< gmp_adaptor.so -lmpfr -lgmp

clean:; rm -f *~
distclean:; rm -f  *~ example gmp_adaptor.so
