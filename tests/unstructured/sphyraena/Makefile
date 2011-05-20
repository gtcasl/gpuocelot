SQLITE_VER = 3.6.22
GSL_VER = 1.9

all: sqlite
	make -C sphyraena

clean:
	make -C sphyraena clean
	rm -rf sqlite*
	rm -rf gsl*

sqlite:
	rm -rf sqlite-$(SQLITE_VER) sqlite
	wget http://sqlite.org/sqlite-$(SQLITE_VER).tar.gz
	tar -xzzvf sqlite-$(SQLITE_VER).tar.gz
	rm sqlite-$(SQLITE_VER).tar.gz
	sed "s/SQLITE_VER = [0-9\.]*/SQLITE_VER = $(SQLITE_VER)/g" sphyraena/Makefile > sphyraena/Makefile.new
	mv sphyraena/Makefile.new sphyraena/Makefile
	mkdir sqlite
	cd sqlite && ../sqlite-$(SQLITE_VER)/configure
	cd sqlite && make

gsl:
	rm -rf gsl-$(GSL_VER) gsl
	wget ftp://ftp.gnu.org/gnu/gsl/gsl-$(GSL_VER).tar.gz
	tar -xzzvf gsl-$(GSL_VER).tar.gz
	rm gsl-$(GSL_VER).tar.gz
	mkdir gsl
	cd gsl && ../gsl-$(GSL_VER)/configure
	cd gsl && make


package:
	tar cvzf sphyraena.tar.gz ../sphyraena/README.txt ../sphyraena/api.txt ../sphyraena/Makefile ../sphyraena/sphyraena ../sphyraena/db/hundredthousand.db ../sphyraena/db/Makefile ../sphyraena/db/gendb.c
	zip -r sphyraena.zip ../sphyraena/README.txt ../sphyraena/api.txt ../sphyraena/Makefile ../sphyraena/sphyraena ../sphyraena/db/hundredthousand.db ../sphyraena/db/Makefile ../sphyraena/db/gendb.c


.PHONY: clean
.PHONY: all
.PHONY: gsl
.PHONY: sqlite

