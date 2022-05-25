CSOURCES := $(shell find . -name "*.c")
CPPSOURCES := $(shell find . -name "*.cpp")
CFLAGS := -Wall -Wextra -Wfloat-equal -O  -MMD -Wstrict-prototypes

debug: CFLAGS := $(CFLAGS) -g
all: CFLAGS := $(CFLAGS) -g -fsanitize=address -fsanitize=leak -fsanitize=undefined -fsanitize=null -fsanitize=bounds-strict -fstack-protector-all
coverage: CFLAGS := $(CFLAGS) -g -fsanitize=address -fsanitize=leak -fsanitize=undefined -fsanitize=null -fsanitize=bounds-strict -fstack-protector-all -fprofile-arcs -ftest-coverage
werror: CFLAGS := $(CFLAGS) -Werror -g -fsanitize=address -fsanitize=leak -fsanitize=undefined -fsanitize=null -fsanitize=bounds-strict -fstack-protector-all

debug: CXXFLAGS := $(CFLAGS) -std=c++17
all: CXXFLAGS := $(CFLAGS) -std=c++17
coverage: CXXFLAGS := $(CFLAGS) -std=c++17
werror: CXXFLAGS := $(CFLAGS) -std=c++17


LDLIBS := -lm -lpthread -lstdc++
all: LDFLAGS := -fsanitize=address -fsanitize=leak -fsanitize=undefined -fsanitize=null -fsanitize=bounds-strict -fstack-protector-all
coverage: LDFLAGS := -fsanitize=address -fsanitize=leak -fsanitize=undefined -fsanitize=null -fsanitize=bounds-strict -fstack-protector-all -fprofile-arcs -ftest-coverage
werror: LDFLAGS := -fsanitize=address -fsanitize=leak -fsanitize=undefined -fsanitize=null -fsanitize=bounds-strict -fstack-protector-all

all: main
debug: main
werror: main
coverage: main

main: $(CSOURCES:%.c=%.o) $(CPPSOURCES:%.cpp=%.o)

DEPS := $(shell find -name "*.d")
-include $(DEPS)

clean:
	rm -f main
	rm -f *.o
	rm -f *.d
