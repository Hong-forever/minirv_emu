# 编译器设置
CC = gcc
CFLAGS = -g -O2 -Wall -Wextra -Isrc -rdynamic
LDFLAGS = 

# 目标可执行文件名
TARGET = soc 

# 源文件目录
SRC_DIR = .

# 源文件列表（自动查找所有.c文件）
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS: .c=.o)

# 默认目标
all: $(TARGET)

# 链接目标文件生成可执行文件
$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

# 编译每个.c文件为.o文件
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 清理生成的文件
clean:
	rm -f $(OBJS) $(TARGET)

# 声明伪目标
.PHONY: all clean 
