bulk_loading.out : am.o amfns.o amsearch.o aminsert.o amstack.o amglobals.o misc.o  ../pflayer/pflayer.o insert.o amscan.o amprint.o
	cc -w -o bulk_loading.out am.o amfns.o amsearch.o aminsert.o  amstack.o amglobals.o misc.o ../pflayer/pflayer.o insert.o amscan.o amprint.o

normal_insertion.out : am.o amfns.o amsearch.o aminsert.o amstack.o amglobals.o misc.o  ../pflayer/pflayer.o main.o amscan.o amprint.o
	cc -w -o normal_insertion.out am.o amfns.o amsearch.o aminsert.o  amstack.o amglobals.o misc.o  ../pflayer/pflayer.o main.o amscan.o amprint.o

amlayer.o : am.o amfns.o amsearch.o aminsert.o amstack.o amglobals.o amscan.o amprint.o
	ld -r am.o amfns.o amsearch.o aminsert.o  amstack.o amglobals.o amscan.o amprint.o  -o amlayer.o

am.o : am.c am.h pf.h
	cc -w -c am.c

amfns.o : amfns.c am.h pf.h
	cc -w -c amfns.c

amsearch.o : amsearch.c am.h pf.h
	cc -w -c amsearch.c

aminsert.o : aminsert.c am.h pf.h
	cc -w -c aminsert.c

amscan.o : amscan.c am.h pf.h
	cc -w -c amscan.c

amstack.o : amstack.c am.h pf.h
	cc -w -c amstack.c

amglobals.o : amglobals.c am.h
	cc -w -c amglobals.c


amprint.o : amprint.c am.h pf.h 
	cc -w -c amprint.c
	
main.o : main.cpp am.h pf.h
	cc -w -c main.cpp
misc.o : misc.c am.h pf.h
	cc -w -c misc.c


insert.o : insert.c am.h pf.h
	c99 -w -c insert.c

clean: 
	rm -f *.o
	rm -f *.out
