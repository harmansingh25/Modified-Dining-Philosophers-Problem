compile1:
	gcc ph1_2019042.c -o ph1_2019042 -lpthread
compile2:
	gcc ph2_2019042.c -o ph2_2019042 -lpthread
run1: compile1
	./ph1_2019042
run2: compile2
	./ph2_2019042	
