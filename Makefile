# TARGETSO = fjobs.o redirection.o execvp.o nightswatch.o ls.o pinfo.c echo.o change_dir.o pwd.o execute.o shell.o current_dir.o pipe.h
# TARGETS = fjobs.c redirection.c execvp.c nightswatch.c ls.c pinfo.c echo.c change_dir.c pwd.c execute.c shell.c current_dir.c pipe.c
#
#
#
# makeo: 	$(TARGETSO)
# 	gcc -o coolShell $(TARGETSO)
#
# compile: $(TARGETS)
# 	gcc -c $(TARGETS)
#
# debug: $(TARGETS)
# 	gcc -c -g -Wall $(TARGETS)
#
# clean: $(TARGETSO)
# 	rm *.o

main: *.c
	gcc -o coolShell *.c
