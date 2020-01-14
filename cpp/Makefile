all: maptest_write maptest_read

maptest_write: maptest_write.cc maptest.capn.c++
	c++ -o $@ $< -O3 -std=c++14 -lcapnp -lkj

maptest.capn.c++: maptest.capn
	capnp compile -oc++ $<

maptest_read: maptest_read.cc maptest.capn.c++
	c++ -o $@ $< -O3 -std=c++14 -lcapnp -lkj

clean:
	rm maptest_read maptest_write 
