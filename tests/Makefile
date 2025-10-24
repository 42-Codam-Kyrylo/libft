# **************************************************************************** #
#                             LIBFT TEST MAKEFILE                              #
# **************************************************************************** #

CC          = gcc
CFLAGS      = -Wall -Wextra -Werror

# Пути
ROOT_DIR    = ..

# Определение ОС и путей к Criterion
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
    # macOS (Homebrew)
    BREW_PREFIX = $(shell brew --prefix)
    CRIT_INC    = -I $(BREW_PREFIX)/include
    CRIT_LIB    = -L $(BREW_PREFIX)/lib -lcriterion
    LD_PATH     = DYLD_LIBRARY_PATH=$(BREW_PREFIX)/lib
else
    # Linux
    CRIT_DIR    = $(HOME)/criterion-2.4.3-linux-x86_64/criterion-2.4.3
    CRIT_INC    = -I $(CRIT_DIR)/include
    CRIT_LIB    = -L $(CRIT_DIR)/lib -lcriterion
    LD_PATH     = LD_LIBRARY_PATH=$(CRIT_DIR)/lib
endif

# Файлы
TEST_SRC    = $(wildcard *.c)
TEST_BIN    = test_libft
LIBFT_A     = $(ROOT_DIR)/libft.a

# Test options
VERBOSE     ?= 
FILE        ?= 

COMPILE_ALL  = $(CC) $(CFLAGS) $(TEST_SRC) $(LIBFT_A) -I $(ROOT_DIR) $(CRIT_INC) $(CRIT_LIB) -o $(TEST_BIN)
COMPILE_FILE = $(CC) $(CFLAGS) $(FILE) $(LIBFT_A) -I $(ROOT_DIR) $(CRIT_INC) $(CRIT_LIB) -o $(TEST_BIN)
RUN_TESTS    = $(LD_PATH) ./$(TEST_BIN) $(VERBOSE)

# **************************************************************************** #
#                                   TARGETS                                    #
# **************************************************************************** #

all: test

build-libft:
	@echo "📦 Building libft..."
	@$(MAKE) -C $(ROOT_DIR) all
	@$(MAKE) -C $(ROOT_DIR) bonus


test: build-libft
	@echo "🔧 Building and running tests..."
ifeq ($(FILE),)
	@$(COMPILE_ALL)
	@$(RUN_TESTS)
else
	@$(COMPILE_FILE)
	@$(RUN_TESTS)
endif

show: VERBOSE=--verbose
show: test

test-list: build-libft
	@echo "📋 Listing available tests..."
	@$(COMPILE_ALL)
	@$(LD_PATH) ./$(TEST_BIN) --list

clean:
	@rm -f $(TEST_BIN)
	@echo "🧹 Removed test binary."

fclean: clean
	@$(MAKE) -C $(ROOT_DIR) fclean
	@echo "🧹 Cleaned libft too."

.PHONY: all test clean fclean show test-list