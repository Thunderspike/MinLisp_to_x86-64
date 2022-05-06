NAME	=	minlisp

$(NAME):	$(NAME).tab.c lex.yy.c stateManagement.c generatorUtils.c
	gcc -o $(NAME) $(NAME).tab.c lex.yy.c stateManagement.c generatorUtils.c $(NAME).h -ll

$(NAME).tab.c: $(NAME).y
	bison -vd $(NAME).y 

lex.yy.c:	$(NAME).l
	flex $(NAME).l 