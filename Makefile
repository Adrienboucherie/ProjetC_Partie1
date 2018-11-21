# règle implicite
%: %.c
	gcc -Wall -o $@ $@.c

# règles spécifiques
treetest: treetest.c
	gcc -Wall -o $@ $@.c -L./mylib -lmylib