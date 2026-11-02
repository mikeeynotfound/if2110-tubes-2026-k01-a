# Contoh Makefile. Silakan sesuaikan dengan struktur program kalian.
# Semua file .c di src/ dikompilasi; driver memiliki entry point terpisah.

.DEFAULT_GOAL := all
.DELETE_ON_ERROR:

CC ?= cc
CPPFLAGS += -Isrc -Isrc/adt -Isrc/fitur -Isrc/io
CFLAGS ?= -std=c11 -Wall -Wextra -Wpedantic -g
LDLIBS += -lm

TARGET := bin/nangornotes
SOURCES := $(shell find src -type f -name '*.c' | LC_ALL=C sort)
OBJECTS := $(patsubst src/%.c,build/%.o,$(SOURCES))
MODULE_OBJECTS := $(filter-out build/main.o,$(OBJECTS))
DEPENDENCIES := $(OBJECTS:.o=.d)

.PHONY: all run clean help driver run-driver

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p "$(@D)"
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o "$@"

build/%.o: src/%.c Makefile
	@mkdir -p "$(@D)"
	$(CC) $(CPPFLAGS) $(CFLAGS) -MMD -MP -c "$<" -o "$@"

run: $(TARGET)
	./$(TARGET)

# Contoh: make run-driver DRIVER=drivers/list_driver.c
# Hanya src/main.c yang dikecualikan saat membangun driver.
DRIVER ?=

ifeq ($(strip $(DRIVER)),)
driver run-driver:
	@printf '%s\n' 'Tentukan file driver, misalnya: make driver DRIVER=drivers/list_driver.c'
	@exit 2
else ifeq ($(filter drivers/%.c,$(DRIVER)),)
driver run-driver:
	@printf '%s\n' 'DRIVER harus berupa file .c di dalam folder drivers/.'
	@exit 2
else
DRIVER_OBJECT := build/$(DRIVER:.c=.o)
DRIVER_TARGET := bin/$(DRIVER:.c=)
DEPENDENCIES += $(DRIVER_OBJECT:.o=.d)

driver: $(DRIVER_TARGET)

run-driver: $(DRIVER_TARGET)
	./$(DRIVER_TARGET)

$(DRIVER_TARGET): $(DRIVER_OBJECT) $(MODULE_OBJECTS)
	@mkdir -p "$(@D)"
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o "$@"

build/drivers/%.o: drivers/%.c Makefile
	@mkdir -p "$(@D)"
	$(CC) $(CPPFLAGS) $(CFLAGS) -MMD -MP -c "$<" -o "$@"
endif

clean:
	rm -rf -- build bin

help:
	@printf '%s\n' \
	  'make                                       Kompilasi program' \
	  'make run                                   Kompilasi dan jalankan program' \
	  'make driver DRIVER=drivers/list_driver.c    Kompilasi driver yang sudah dibuat' \
	  'make run-driver DRIVER=drivers/list_driver.c Kompilasi dan jalankan driver' \
	  'make clean                                 Hapus hasil kompilasi'

-include $(DEPENDENCIES)
