# C applications (each in c/<name>, with its own Makefile)
C_APPS := lin_reg

# C++ applications (each in cpp/app/<name>, with its own Makefile)
CPP_APPS := lin_reg dense_layer

# Target names, e.g. "c-lin_reg" and "cpp-dense_layer"
APPS := $(addprefix c-,$(C_APPS)) $(addprefix cpp-,$(CPP_APPS))

# Directory of each application
dir_of = $(if $(filter c-%,$(1)),c/$(1:c-%=%),cpp/app/$(1:cpp-%=%))

# Build all applications by default
default: build

# Build and run a single application, e.g. "make cpp-lin_reg"
$(APPS):
	@$(MAKE) --no-print-directory -C $(call dir_of,$@)

# Build all applications
build:
	@$(foreach app,$(APPS),$(MAKE) --no-print-directory -C $(call dir_of,$(app)) build || exit 1;)

# Clean all applications
clean:
	@$(foreach app,$(APPS),$(MAKE) --no-print-directory -C $(call dir_of,$(app)) clean;)

.PHONY: default build clean $(APPS)
