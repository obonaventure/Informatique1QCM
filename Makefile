define MAKEQCM

qcm$(1): Mission$(1)/qcm-$(1).rst
	@(cd Mission$(1) && $(MAKE))

endef

QCM=1 2 3 4 5 6 7 8 9 10

$(foreach i,$(QCM),$(eval $(call MAKEQCM,$(i))))

clean:
	@for i in $(QCM); do\
	( cd Mission$$i && $(MAKE) clean;)  ; done

all:
	@for i in $(QCM); do\
	( cd Mission$$i && $(MAKE) all;)  ; done
