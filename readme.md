# RSL Robot Specific Language

## 简介

RSL 是一种简单的脚本语言，提供了简单的语法描述在线客服机器人的自动应答逻辑。文法中内置了几种命令， 例如向用户发送消息，等待用户回复，查询本地数据库等。

## 脚本语法规则

### 脚本内置命令

- Step  [stepname]:

- Speak  [sentense]:在终端输出sentense

- Listen  [starttime  stoptime]:在startime到stoptime时间内等待用户的输入，并且转到相应的操作

  - Branch  [instruction]  [processname]:用于Listen的分支语句结构，instruction为指令名称，当用户输入正确的指令后，会转入processname的Step中
  - Silence  [processname]:用于Listen的分支语句结构，当用户沉默时，转入processname的Step中
  - Default  [processname]:用于Listen的分支语句结构，当用户未执行上述两种操作，其余情况的默认处理，转入processname的Step中

  > 注意：请在使用Listen语句时，保证Default默认处理流程，即在每个Listen语句的分句下面，使用Default  [processname]

- Assign  [var1]  [var2]  [var3]  ......:变量赋值语句，将用户输入赋值给var1，var2，var3

- Getdata  [keyvar]  [savevar]:数据库db文件查找语句，keyvar为键变量，通过keyvar中的值查找数据库中的匹配项，如果查找到将其保存在savevar变量中，未查找到会在savevar中保存-1

- Exit：用于Step语句块中退出，如果语句块中使用了该语句，则此Step块执行到Exit会退出程序

- Endstep:用于Step语句块中循环，使用Endstep后，程序会一直循环执行此Step。

  > 注意：编写的脚本中Step中必须使用Listen或Exit或Endstep保证程序正常运行

### 注释

以‘#’开头为注释

> #我是一行注释

### 变量

以'$'开头为变量

> $var

### 示例脚本

[repeat.ss](./script/repeat.ss)

[searchphone.ss](./script/searchphone.ss)

[user.ss](./script/user.ss)

[weather.ss](./script/weather.ss)

## 开发文档

[开发文档](develop.md)

## 用户使用文档

[用户使用文档](use.md)



