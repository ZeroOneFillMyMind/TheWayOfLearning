# 黑客之道

## 1 what

黑客攻击的本质：寻找法律未涵盖的范围或者遗漏之处，在给定的条件下以创造性的、有新意的方式解决各种问题。

遵循系统的规则来解决问题。

Hacker Ethic：将逻辑作为一门艺术加以欣赏，促进信息的自由流动，打破常规的束缚，不设条条框框，只追求一个目标：更好的了解客观世界。

与之相对：Cracker

Hacker: 编写代码的人 + 发掘代码漏洞的人

## 2 practice

GNU Compiler Collection

汇编语言:机器语言 = 1:1
每个处理器体系都有自己的机器语言指令，因此有不同形式的汇编语言。

主要的汇编语言语法：AT&T / Intel

对应objdump参数： AT&T(default) Intel(-M Intel)

objdump -D a.out | grep -A20 main.:
注解：D --disassemble-all

EAX 累加
ECX 计数
EDX 数据
EBX 基址

ESP 堆栈指针
EBP 基址指针
ESI 源变址
EDI 目的变址

EIP 指令指针

```
set disassembly intel
.gdbinit
echo "set dis intel" > .gdbinit

intel style: operation <destination>, <source>
```

gcc -g 额外的调试信息

examine x
o
x
u
t

b 1B
h 2B
w 4B
g 8B

s 指针/字符串

x86 little-endian

bc: 任意精度计算器

x/i $rip // 需要带$

i r rip

nexti

c 自动转换为ascii x/6cb

lea Load Effective Address

格式化输出：
%p (自带0x)
%u %d %x

```
当int*指针指向char*数据后，如果int*指针+1，地址会加4
```

如果使用类型强制转换，编译器可能不会告警，相反，不适用强制类型转换，编译器一定会告警

void指针
* 作用：仅保留内存地址
* 特点：除非指针具有类型，否则无法解除引用；为访问指针在内存中存储的值，编译器首先需要知道其类型；执行指针型运算前，必须强制转换void指针

unsigned int与指针的转换
*C++中有uintptr_t/intptr_t

atoi() ascii to int

bt显示stack frame信息
bt full 显示局部变量
 
已编译程序内存：
text 代码段，汇编后的机器语言指令。程序执行时，eip被设置为text段的第一条指令。禁用写权限。
data 已初始化的全局变量和静态变量
bss 未初始化的全局变量和静态变量
heap 程序员可直接控制的段。
stack 中间结果暂存器，存储本地函数变量和上下文。（所有被传递的变量、函数结束后EIP应返回的位置、函数使用的所有局部变量）

esp寄存器跟踪栈顶地址
ebp寄存器指向当前栈帧位置

堆栈的大小变化时，以一种形象化的内存列表形式由存储空间的高地址向低地址增长，与heap动态增长方向相反

栈帧中内容：函数参数、函数局部变量、保存的栈指针（Saved Frame Pointer,SFP,用于恢复EBP的值）、返回地址（将eip恢复为函数调用后的下一条指令的地址）

文件操作
O_RDONLY
O_WRONLY
O_RDWR

O_APPEND
O_TRUNC
O_CREAT

id命令

