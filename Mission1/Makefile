####################################################################
#
#  Makefile for Missions
#  OB, Sept 2013
# 
####################################################################

MISSION=1

EXNAME=Mission$(MISSION)

RST_FILES=qcm-$(MISSION).rst

RST_FORM=../rst-form/js/jquery-1.7.2.min.js ../rst-form/js/jquery-shuffle.js ../rst-form/js/rst-form.js

IMAGES=../rst-form/images/correct.png ../rst-form/images/false.png

CSS=../rst-form/css/html4css1.css,../rst-form/css/rst-form.css,../rst-form/css/pygments.css


.PHONY : qcm all

qcm: 	$(RST_FILES)
	echo "Preparing QCM files"
	test -d FSAB1401 || mkdir FSAB1401
	test -d FSAB1401/js || mkdir FSAB1401/js
	test -d FSAB1401/images || mkdir FSAB1401/images
	test -d SINF1101 || mkdir SINF1101
	test -d SINF1101/js || mkdir SINF1101/js
	test -d SINF1101/images || mkdir SINF1101/images
	@for i in $(RST_FILES); do\
	( rst2html.py --stylesheet-path=$(CSS)  $$i > SINF1101/$(EXNAME)-qcm.html ;\
	rst2html.py --stylesheet-path=$(CSS)  $$i > FSAB1401/$(EXNAME)-qcm.html  ;)  ; done

	@for i in $(RST_FORM); do \
	( cp $$i FSAB1401/js ; cp $$i SINF1101/js ;) ; done
	@for i in $(IMAGES); do \
	( cp $$i FSAB1401/images ; cp $$i SINF1101/images ;) ; done

all: qcm
	cd FSAB1401 && zip -9rp FSAB1401-$(MISSION).zip *pdf js/* images/* *.html $(EXNAME).zip
	cd SINF1101 && zip -9rp SINF1101-$(MISSION).zip *pdf js/* images/* *.html $(EXNAME).zip


clean:
	-rm -r FSAB1401/*
	-rm -r SINF1101/* 
	-rm -r Tuteurs/*
