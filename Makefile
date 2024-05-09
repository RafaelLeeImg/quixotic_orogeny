CCACHE := ccache
PREFIX := arm-none-eabi-

CC := $(CCACHE) $(PREFIX)gcc
CXX := $(CCACHE) $(PREFIX)g++
LD := $(CCACHE) $(PREFIX)g++
AS := $(CCACHE) $(PREFIX)gcc -x assembler-with-cpp
CP := $(CCACHE) $(PREFIX)objcopy
AR := $(CCACHE) $(PREFIX)ar
SZ := $(CCACHE) $(PREFIX)size

DEBUG := 1

ifndef V
.SILENT:
endif

# https://www.gnu.org/software/make/manual/html_node/Implicit-Variables.html
SANITIZER := #-fsanitize=address -fsanitize=undefined
COVERAGE := # -fprofile-arcs -ftest-coverage
PROFILING := # -pg
OPTIMIZE := -O0 -Og # -Os
SHORTER_ERROR := -Wfatal-errors

OVERALL_FLAGS := -fdiagnostics-color=always -fdata-sections -ffunction-sections $(SANITIZER) $(COVERAGE) $(PROFILING) $(OPTIMIZE) $(SHORTER_ERROR)

# assembly flags
ASFLAGS :=

MCU := -mthumb -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16

# C flags
# with all warnings, with extra warnings
CFLAGS := \
	-std=c99 \
	--specs=rdimon.specs \
	-Wall -Wextra -Wundef -Wshadow -Wimplicit-function-declaration -Wredundant-decls -Wmissing-prototypes -Wstrict-prototypes \
	-fno-common -ffunction-sections -fdata-sections \
	-WNSObject-attribute -Wabsolute-value -Waddress -Waddress-of-packed-member -Waggregate-return -Waggressive-loop-optimizations -Walloc-zero -Walloca -Wanalyzer-double-fclose -Wanalyzer-double-free -Wanalyzer-exposure-through-output-file -Wanalyzer-file-leak -Wanalyzer-free-of-non-heap -Wanalyzer-malloc-leak -Wanalyzer-mismatching-deallocation -Wanalyzer-null-argument -Wanalyzer-null-dereference -Wanalyzer-possible-null-argument -Wanalyzer-possible-null-dereference -Wanalyzer-shift-count-negative -Wanalyzer-shift-count-overflow -Wanalyzer-stale-setjmp-buffer -Wanalyzer-tainted-allocation-size -Wanalyzer-tainted-array-index -Wanalyzer-tainted-divisor -Wanalyzer-tainted-offset -Wanalyzer-tainted-size -Wanalyzer-too-complex -Wanalyzer-unsafe-call-within-signal-handler -Wanalyzer-use-after-free -Wanalyzer-use-of-pointer-in-stale-stack-frame -Wanalyzer-use-of-uninitialized-value -Wanalyzer-write-to-const -Wanalyzer-write-to-string-literal -Warith-conversion -Warray-bounds -Warray-compare -Wattribute-warning -Wattributes -Wbad-function-cast -Wbool-compare -Wbool-operation -Wbuiltin-declaration-mismatch -Wbuiltin-macro-redefined -Wc++-compat -Wcannot-profile -Wcast-align -Wcast-align=strict -Wcast-function-type -Wcast-qual -Wchar-subscripts -Wclobbered -Wcomment -Wconversion -Wcoverage-invalid-line-number -Wcoverage-mismatch -Wcpp -Wdangling-else -Wdate-time -Wdeprecated -Wdeprecated-declarations -Wdesignated-init -Wdisabled-optimization -Wdiscarded-array-qualifiers -Wdiscarded-qualifiers -Wdiv-by-zero -Wdouble-promotion -Wduplicate-decl-specifier -Wduplicated-branches -Wduplicated-cond -Wempty-body -Wendif-labels -Wenum-conversion -Wexpansion-to-defined -Wextra -Wfloat-conversion -Wfloat-equal -Wformat-contains-nul -Wformat-diag -Wformat-extra-args -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat-y2k -Wformat-zero-length -Wframe-address -Wfree-nonheap-object -Whsa -Wif-not-aligned -Wignored-attributes -Wignored-qualifiers -Wimplicit -Wincompatible-pointer-types -Winfinite-recursion -Winit-self -Winline -Wint-conversion -Wint-in-bool-context -Wint-to-pointer-cast -Winvalid-memory-model -Winvalid-pch -Wjump-misses-init -Wlogical-not-parentheses -Wlogical-op -Wlto-type-mismatch -Wmaybe-uninitialized -Wmemset-elt-size -Wmemset-transposed-args -Wmisleading-indentation -Wmismatched-dealloc -Wmissing-attributes -Wmissing-braces -Wmissing-declarations -Wmissing-field-initializers -Wmissing-include-dirs -Wmissing-parameter-type -Wmissing-profile -Wmissing-prototypes -Wmultichar -Wmultistatement-macros -Wnested-externs -Wnonnull -Wnonnull-compare -Wnull-dereference -Wodr -Wold-style-declaration -Wopenacc-parallelism -Wopenmp-simd -Woverflow -Woverlength-strings -Woverride-init -Woverride-init-side-effects -Wpacked -Wpacked-not-aligned -Wpadded -Wparentheses -Wpedantic -Wpointer-arith -Wpointer-compare -Wpointer-sign -Wpointer-to-int-cast -Wpragmas -Wprio-ctor-dtor -Wpsabi -Wredundant-decls -Wrestrict -Wreturn-local-addr -Wscalar-storage-order -Wsequence-point -Wshadow -Wshadow=compatible-local -Wshadow=local -Wshift-count-negative -Wshift-count-overflow -Wsign-compare -Wsign-conversion -Wsizeof-array-argument -Wsizeof-array-div -Wsizeof-pointer-div -Wsizeof-pointer-memaccess -Wstack-protector -Wstrict-prototypes -Wstring-compare -Wstringop-overread -Wstringop-truncation -Wsuggest-attribute=cold -Wsuggest-attribute=const -Wsuggest-attribute=format -Wsuggest-attribute=malloc -Wsuggest-attribute=noreturn -Wsuggest-attribute=pure -Wsuggest-final-methods -Wsuggest-final-types -Wswitch -Wswitch-bool -Wswitch-default -Wswitch-enum -Wswitch-outside-range -Wswitch-unreachable -Wsync-nand -Wsystem-headers -Wtautological-compare -Wtrampolines -Wtrigraphs -Wtrivial-auto-var-init -Wtsan -Wtype-limits -Wundef -Wuninitialized -Wunknown-pragmas -Wunreachable-code -Wunsafe-loop-optimizations -Wunsuffixed-float-constants -Wunused -Wunused-but-set-parameter -Wunused-but-set-variable -Wunused-function -Wunused-label -Wunused-local-typedefs -Wno-unused-macros -Wno-unused-parameter -Wunused-result -Wunused-value -Wno-unused-variable -Wuse-after-free -Wvarargs -Wvariadic-macros -Wvector-operation-performance -Wvla-parameter -Wvolatile-register-var -Wwrite-strings -Wzero-length-bounds \
	# -Wtraditional -Wtraditional-conversion


# -MD \
# -MM -MD


# C preprocess flags
# CPPFLAGS := -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)"
CPPFLAGS :=

# Extra flags to give to the C++ compiler.
CXXFLAGS := -Wall -Wextra -std=c++14

# ******************************************************************************
TARGET := main

# gnu make does not expand "~"
TOP := $(shell pwd)/
SRC := .
INC := -I$(TOP) \
	-Iinclude
OBJ := build
COVERAGE_DIR := coverage

# libraries
LIB := #-lc -lm

# ********** LDFLAGS **********
# link script
LDSCRIPT := -TSTM32F405RET6.ld

# # compile, libopencm3
# arm-none-eabi-gcc -Os -std=c99 -ggdb3 -mthumb -mcpu=cortex-m4 --specs=rdimon.specs -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Wextra -Wshadow -Wimplicit-function-declaration -Wredundant-decls -Wmissing-prototypes -Wstrict-prototypes -fno-common -ffunction-sections -fdata-sections -g -Og  -MD -Wall -Wundef -DSTM32F4 -I../../../../../libopencm3//include  -o usart.o -c usart.c
# # link, libopencm3
# arm-none-eabi-gcc --static -nostartfiles -T../stm32f4-discovery.ld -mthumb -mcpu=cortex-m4 --specs=rdimon.specs -mfloat-abi=hard -mfpu=fpv4-sp-d16 -ggdb3 -Wl,-Map=usart.map -Wl,--cref -Wl,--gc-sections -g -Og -L../../../../../libopencm3//lib usart.o -lopencm3_stm32f4 -Wl,--start-group -lc -lgcc -lnosys -Wl,--end-group -o usart.elf

# # current linking command of this makefile
# ccache arm-none-eabi-gcc build/vector.c.o build/vector_nvic.c.o build/main.c.o build/reset_handler.c.o -mthumb -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -TSTM32F405RET6.ld -I/dev/shm/d/proj/quixotic_orogeny/ -Iinclude   -fdata-sections -ffunction-sections    -Og  -Wfatal-errors -std=c99 --static --specs=rdimon.specs -Wl,-Map=usart.map -Wl,--cref -Wl,--gc-sections -Wl,--start-group -lc -lgcc -lnosys -Wl,--end-group -Wl,-Map=build/main.map,--cref,--gc-sections,--print-memory-usage -g -gdwarf-2 -o build/main.elf

# # current hand writing:
# arm-none-eabi-gcc --static -nostartfiles -TSTM32F405RET6.ld -mthumb -mcpu=cortex-m4 --specs=rdimon.specs -mfloat-abi=hard -mfpu=fpv4-sp-d16 -ggdb3 -Wl,-Map=main.map -Wl,--cref -Wl,--gc-sections -g -Og -Wl,--start-group -lc -lgcc -lnosys -Wl,--end-group build/vector.c.o build/vector_nvic.c.o build/main.c.o build/reset_handler.c.o -o build/main.elf


# -Wl,(XX) means send xx to linker
# -Wl,--gc-sections means send --gc-sections to linker
# -fdata-sections -ffunction-sections
# LDFLAGS := -Wl,--gc-sections -g -Wall --specs=nosys.specs # -specs=nano.specs
# --cref create reference table
LDFLAGS := $(MCU) $(LDSCRIPT) $(INC) $(LIB) $(STARTUP_DEFS) $(OVERALL_FLAGS) \
	-std=c99 \
	--static \
	-nostartfiles \
	--specs=rdimon.specs \
	-Wl,-Map=usart.map -Wl,--cref -Wl,--gc-sections \
	-Wl,--start-group -lc -lgcc -lnosys -Wl,--end-group \
	-Wl,-Map=$(OBJ)/$(TARGET).map,--cref,--gc-sections,--print-memory-usage

# -specs=nano.specs -fdata-sections -ffunction-sections
# compile gcc flags
ASFLAGS := $(ASFLAGS) $(MCU) $(AS_DEFS) $(AS_INCLUDES) $(OPT) $(STARTUP_DEFS) $(OVERALL_FLAGS)

CFLAGS := $(CFLAGS) $(MCU) $(C_DEFS) $(C_INCLUDES) $(OPT) $(STARTUP_DEFS) $(OVERALL_FLAGS)

CXXFLAGS := $(CXXFLAGS) $(MCU) $(CXX_DEFS) $(CXX_INCLUDES) $(OPT) $(STARTUP_DEFS) $(OVERALL_FLAGS)

DEBUG := 1
ifeq ($(DEBUG), 1)
ASFLAGS += -g -gdwarf-2
CPPFLAGS += -g -gdwarf-2
CFLAGS += -g -gdwarf-2
CXXFLAGS += -g -gdwarf-2
LDFLAGS += -g -gdwarf-2
endif

# the first target in makefile is the default target
# which means
# `make` is the same with `make all`

# target: dependencies
# the next line of target starts with tab

# define your source files with full path manually and ignore auto detected
# all_c_files :=
# all_cc_files :=
# all_asm_files :=


# all_c_files is a collection of full path of source files, like src/main.c
all_c_files ?= $(sort $(shell find $(SRC) -name "*.c"))
all_cc_files ?= $(sort $(shell find $(SRC) -name "*.cc"))
all_asm_files ?= $(sort $(shell find $(SRC) -name "*.s"))

vpath %.c $(sort $(dir $(all_c_files)))
vpath %.cc $(sort $(dir $(all_cc_files)))
vpath %.s $(sort $(dir $(all_asm_files)))

# all_o_files is a collection of file names with out path, like main.c.o
all_o_files := $(addprefix $(OBJ)/,$(addsuffix .o,$(notdir $(all_c_files))))
all_o_files += $(addprefix $(OBJ)/,$(addsuffix .o,$(notdir $(all_cc_files))))
all_o_files += $(addprefix $(OBJ)/,$(addsuffix .o,$(notdir $(all_asm_files))))

all_d_files := $(all_o_files:.o=.d)

# ******************************************************************************
.PHONY: clean all $(OBJ)

# https://stackoverflow.com/questions/47447369/gnu-make-removing-intermediate-files
# .PRECIOUS: $(OBJ)/%.o # does not work
.PRECIOUS: $(all_o_files) $(all_d_files)


# default target: all
# no recipe for target all
all: $(TARGET)

# .PHONY: $(TARGET)
.IGNORE: $(TARGET)
$(TARGET): $(OBJ)/$(TARGET).elf
	if [ -L $(TARGET) ]; then /bin/true; else ln -s $(OBJ)/$(TARGET).elf $(TARGET); fi

# LD is not using implicit rule
$(OBJ)/%.elf: $(all_o_files) | $(OBJ)
	$(LD) $(all_o_files) $(LDFLAGS) -o $@

$(OBJ)/%.hex: $(OBJ)/%.elf
	$(CP) -O ihex $< $@

$(OBJ)/%.bin: $(OBJ)/%.elf
	$(CP) -O binary $< $@


# $@ target
# $< first prerequisite
# $(@D) the directory part of $@
# $^ The names of all the prerequisites, with spaces between them
# https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html

# http://make.mad-scientist.net/papers/advanced-auto-dependency-generation/
# https://www.gnu.org/software/make/manual/html_node/Automatic-Prerequisites.html
include $(all_d_files)

# where to put OBJ is a question, sometimes compile will fail due to sequence error
$(OBJ):
	mkdir -p $(OBJ)

$(COVERAGE_DIR):
	mkdir -p $(COVERAGE_DIR)

# TODO: fix asm .d generation
# The '-e' flag to the shell causes it to exit immediately if the $(CC) command (or any other command) fails
# The purpose of the sed command is to translate (for example):
# content of main.d:
#     $(OBJ)/main.cc.o : main.cc include/main.hh
# into content of main.d:
#     $(OBJ)/main.cc.o $(OBJ)/main.cc.d : main.cc include/main.hh

$(OBJ)/%.cc.d: %.cc | $(OBJ)
	set -e; rm -f $@; \
	$(CXX) -MM $(CXXFLAGS) $(INC) $< > $@.$$$$; \
	sed 's|\($*\)\.o[ :]*|\1.o $@ : |g' < $@.$$$$ > $@; \
	rm -f $@.$$$$


$(OBJ)/%.c.d: %.c | $(OBJ)
	set -e; rm -f $@; \
	$(CC) -MM $(CFLAGS) $(INC) $< > $@.$$$$; \
	sed 's|\($*\)\.o[ :]*|\1.o $@ : |g' < $@.$$$$ > $@; \
	rm -f $@.$$$$


$(OBJ)/%.s.d: %.s | $(OBJ)
	set -e; rm -f $@; \
	$(AS) -MM $(ASFLAGS) $(INC) $< > $@.$$$$; \
	sed 's|\($*\)\.o[ :]*|\1.o $@ : |g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

$(OBJ)/%.cc.o: %.cc $(OBJ)/%.cc.d | $(OBJ)
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

$(OBJ)/%.c.o: %.c $(OBJ)/%.c.d | $(OBJ)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ)/%.s.o: %.s $(OBJ)/%.s.d | $(OBJ)
	$(AS) -c $(ASFLAGS) $< -o $@

%.o:
	echo "Make target $@ not found"
	exit 1

%.d:
	echo "Make target $@ not found"
	exit 1


# A phony target is one that is not really the name of a file
clean:
	rm -rf ./$(TARGET)
	rm -rf ./$(OBJ)/*
	rm -rf ./$(COVERAGE_DIR)/*
	rm -rf ./gmon.out



# gcov -t build/*.gcda > ./coverage/main.gcov
# lcov -c --follow --directory build --output-file build/main.elf.info
# Can't locate DateTime.pm in @INC (you may need to install the DateTime module) (@INC contains: /usr/lib/lcov /etc/perl /usr/local/lib/x86_64-linux-gnu/perl/5.36.0 /usr/local/share/perl/5.36.0 /usr/lib/x86_64-linux-gnu/perl5/5.36 /usr/share/perl5 /usr/lib/x86_64-linux-gnu/perl-base /usr/lib/x86_64-linux-gnu/perl/5.36 /usr/share/perl/5.36 /usr/local/lib/site_perl) at /usr/lib/lcov/lcovutil.pm line 19.
# BEGIN failed--compilation aborted at /usr/lib/lcov/lcovutil.pm line 19.
# Compilation failed in require at /usr/bin/lcov line 102.
# BEGIN failed--compilation aborted at /usr/bin/lcov line 102.
# make: *** [Makefile:213: gcov] error 2
# ***** solve ******:
# sudo apt-get install libdatetime-perl

.PHONY: gcov
gcov: $(OBJ)/$(TARGET).elf | $(COVERAGE_DIR)
	$(OBJ)/$(TARGET).elf
	gcov -t $(OBJ)/*.gcda > ./$(COVERAGE_DIR)/$(TARGET).gcov
	lcov -c --follow --directory $(OBJ) --output-file $(OBJ)/$(TARGET).elf.info
	genhtml $(OBJ)/$(TARGET).elf.info --output-directory $(COVERAGE_DIR)
