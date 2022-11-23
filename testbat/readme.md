# testbat测试文件夹说明

## in文件夹

.in文件用于.exe文件在cmd终端测试时输入

> ./runner.exe	repeat.ss	<	repeat.in

上述只是做指令用法的实例，实际测试时请注意文件路径

## out文件夹

.out文件用于.exe文件在cmd终端测试时保存输出

> ./runner.exe	repeat.ss	>	repeat.out

上述只是做指令用法的实例，实际测试时请注意文件路径

## testbat文件夹其他文件说明

- anatest.cpp    用于测试analysis.cpp模块的c++代码文件

- anatest.exe    用于测试analysis.cpp模块的c++代码程序

  > ./anatest.exe	repeat.ss

  上述只是做指令用法的实例，实际测试时请注意文件路径

- testana.bat    自动化测试批处理程序，用于测试analysis.cpp模块的正确性，测试结果保存在out文件夹中

- testss.bat     自动化测试批处理程序，用于测试整个程序，即runner.exe的正确性，测试结果保存在out文件夹中

