ALLEXAMPLES=$(filter-out Makefile,$(wildcard *))
TARGETS=$(foreach dir,$(ALLEXAMPLES),$(dir)/$(dir))

# A recipe for making an example inside folder with the same name
define EXAMPLE_rule
$(1)/$(1): $(wildcard $(1)/*.cpp) -lcprocessing -lglut -lGLU -lGL 
	$(MAKE) -C $(1)
endef

# A recipe for cleaning an example
define CLEAN_rule
$(MAKE) -C $(1) clean;
endef
	
all: $(TARGETS)

clean:
	$(foreach folder,$(ALLEXAMPLES),$(call CLEAN_rule,$(folder)))
		
$(foreach folder,$(ALLEXAMPLES),$(eval $(call EXAMPLE_rule,$(folder))))
		

