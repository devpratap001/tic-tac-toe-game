CC = gcc
SRC_DIR = src
BUILD_DIR = build
CFLAGS := -Wall -g -std=c99 -MMD -MP -I$(SRC_DIR)
TARGET := $(BUILD_DIR)/index
SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))
DEPS := $(OBJS:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJS): $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $@

-include $(DEPS)

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJS) $(DEPS)