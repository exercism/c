# This makefile creates a target to build and test each exercise using the provided example
# implementation. The exercise target depends on a list of other targets that
#   1) Copy the main test file and adjust it to include all tests,
#   2) Copy the example implementation so that it is used,
#   3) Copy the makefile and unittest framework,
#   4) Build and test the exercise.
#
# Use `make <slug>` to build and test a specific exercise. Simply running `make` builds and
# tests all available exercises.


# Macro to create the rules for one exercise.
# Arguments:
#   $(1) - slug
#   $(2) - slug with dashes replaced by underscores
#   $(3) - type of exercise: 'practice' or 'concept'
#   $(4) - name of test implementation: 'example' or 'exemplar'
define setup_exercise

# Copy the test file and removes TEST_IGNORE
build/exercises/$(3)/$(1)/test_$(2).c: exercises/$(3)/$(1)/test_$(2).c
	@mkdir -p $$(dir $$@)
	@sed 's#TEST_IGNORE();#// &#' $$< > $$@

# Copy example/exemplar implementation
build/exercises/$(3)/$(1)/$(2).c: exercises/$(3)/$(1)/.meta/$(4).c
	@mkdir -p $$(dir $$@)
	@cp $$< $$@

build/exercises/$(3)/$(1)/$(2).h: $$(wildcard exercises/$(3)/$(1)/.meta/$(4).h exercises/$(3)/$(1)/*.h)
	@# Copy all .h files in the exercises directory
	@cp exercises/$(3)/$(1)/*.h build/exercises/$(3)/$(1) || true
	@# If an example.h/exemplar.h file exists in .meta, replace slug.h with that one
	@if [ -e exercises/$(3)/$(1)/.meta/$(4).h ]; then \
		cp exercises/$(3)/$(1)/.meta/$(4).h build/exercises/$(3)/$(1)/$(2).h; \
	fi

# Copy Makefile
build/exercises/$(3)/$(1)/makefile: exercises/$(3)/$(1)/makefile
	@mkdir -p $$(dir $$@)
	@cp $$< $$@

# Copy the test framework
build/exercises/$(3)/$(1)/test-framework: $$(wildcard exercises/$(3)/$(1)/test-framework/*)
	@mkdir -p $$@
	@cp exercises/$(3)/$(1)/test-framework/* build/exercises/$(3)/$(1)/test-framework/

INPUT_FILE_TARGETS = \
	build/exercises/$(3)/$(1)/test_$(2).c \
	build/exercises/$(3)/$(1)/$(2).c \
	build/exercises/$(3)/$(1)/$(2).h \
	build/exercises/$(3)/$(1)/makefile \
	build/exercises/$(3)/$(1)/test-framework

# Build the exercise.
build/exercises/$(3)/$(1)/tests.out: $$(INPUT_FILE_TARGETS)
	$$(MAKE) -C build/exercises/$(3)/$(1) tests.out

# Run the exercise's test binary and create a stamp file if all tests pass
build/exercises/$(3)/$(1)/tests-passed.stamp: build/exercises/$(3)/$(1)/tests.out
	@rm -f build/exercises/$(3)/$(1)/tests-passed.stamp
	@build/exercises/$(3)/$(1)/tests.out && touch build/exercises/$(3)/$(1)/tests-passed.stamp

# Build and run the memcheck variant
# This is only a single target, since an exercise's makefile builds and runs memcheck as a single target
build/exercises/$(3)/$(1)/memcheck-passed.stamp: $$(INPUT_FILE_TARGETS)
	@rm -f build/exercises/$(3)/$(1)/memcheck-passed.stamp
	$$(MAKE) -C build/exercises/$(3)/$(1) memcheck && touch build/exercises/$(3)/$(1)/memcheck-passed.stamp

# Top-level target for an exercise. It depends on the stamp files for the actual tests and the memcheck
# run. Only when both stamp files are present will this target be considered "done", so as long as there
# are some errors, building that target will trigger a re-run of the tests or memcheck binary.
.PHONY: $(1)
$(1): build/exercises/$(3)/$(1)/tests-passed.stamp build/exercises/$(3)/$(1)/memcheck-passed.stamp

# Remove all artifacts of the exercise
.PHONY: $(1).clean
$(1).clean: $$(INPUT_FILE_TARGETS)
	rm -rf build/exercises/$(3)/$(1)

endef

PRACTICE_EXERCISES := $(notdir $(wildcard exercises/practice/*))
CONCEPT_EXERCISES := $(notdir $(wildcard exercises/concept/*))

all: practice concept

.PHONY: practice
practice: $(PRACTICE_EXERCISES)
	@if [ -z "$(PRACTICE_EXERCISES)" ]; then \
		echo "No practice exercises found."; \
	fi

.PHONY: concept
concept: $(CONCEPT_EXERCISES)
	@if [ -z "$(CONCEPT_EXERCISES)" ]; then \
		echo "No concept exercises found."; \
	fi

# Instantiate the macro for each practice exercise to create targets for each exercise.
$(foreach exercise,$(PRACTICE_EXERCISES),$(eval $(call setup_exercise,$(exercise),$(subst -,_,$(exercise)),practice,example)))
$(foreach exercise,$(CONCEPT_EXERCISES),$(eval $(call setup_exercise,$(exercise),$(subst -,_,$(exercise)),concept,exemplar)))

.PHONY: list-practice
list-practice:
	@for exercise in $(PRACTICE_EXERCISES); do \
		echo "$$exercise"; \
	done

.PHONY: list-concept
list-concept:
	@for exercise in $(CONCEPT_EXERCISES); do \
		echo "$$exercise"; \
	done

.PHONY: clean
clean:
	rm -rf build

.PHONY: help
help:
	@echo "Available targets:"
	@echo "  all            - Build and test all practice exercises (default)"
	@echo "  <slug>         - Build and test a specific exercise given by its slug"
	@echo "  clean          - Remove all build artifacts"
	@echo "  <slug>.clean   - Remove build artifacts of a specific exercise given by its slug"
	@echo "  list-practice  - List all practice exercises"
	@echo "  list-concept   - List all concept exercises"
	@echo "  help           - Show this help message"
