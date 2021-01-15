all:
	+$(MAKE) -C tasks\ 1
	+$(MAKE) -C tasks\ 2
	+$(MAKE) -C tasks\ 3
	+$(MAKE) -C tasks\ 4

clean:
	make clean -C tasks\ 1
	make clean -C tasks\ 2
	make clean -C tasks\ 3
	make clean -C tasks\ 4