OBJS = uimain.o tokenizer.o history.o
CFLAGS = -g -O3

all: token
tokenizer.o: tokenizer.h
history.o: history.h tokenizer.h
uimain.o: tokenizer.h history.h

token: $(OBJS)
	cc -o token $(CFLAGS) $(OBJS)

$(OBJS): tokenizer.o history.o uimain.o

clean:
	rm -f *.o token

run:token
	./token
