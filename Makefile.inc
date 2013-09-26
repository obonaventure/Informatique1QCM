EXNAME=Mission$(MISSION)

RST_FILES=qcm-$(MISSION).rst

RST_FORM=../rst-form/js/jquery-1.7.2.min.js ../rst-form/js/jquery-shuffle.js ../rst-form/js/rst-form.js

IMAGES=../rst-form/images/correct.png ../rst-form/images/false.png

CSS=../rst-form/css/html4css1.css,../rst-form/css/rst-form.css,../rst-form/css/pygments.css



.PHONY : qcm all

qcm: 	$(RST_FILES)
	echo "Preparing QCM files"
	test -d $(EXNAME) || mkdir $(EXNAME)
	test -d $(EXNAME)/js || mkdir $(EXNAME)/js
	test -d $(EXNAME)/images || mkdir $(EXNAME)/images
	@for i in $(RST_FILES); do\
	( rst2html --stylesheet-path=$(CSS)  $$i > $(EXNAME)/$(EXNAME)-qcm.html ;)  ; done

	@for i in $(RST_FORM); do \
	( cp $$i $(EXNAME)/js ;) ; done
	@for i in $(IMAGES); do \
	( cp $$i $(EXNAME)/images ;) ; done

all: qcm
	cd $(EXNAME) && zip -9rp $(EXNAME).zip *pdf js/* images/* *.html $(EXNAME).zip

clean:
	-rm -rf $(EXNAME)
