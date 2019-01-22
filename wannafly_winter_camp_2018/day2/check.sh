#########################################################################
# File Name: check.sh
# Author: sqwlly
# mail: 1476737838@qq.com
# Created Time: 2018年09月10日 星期一 17时26分30秒
#########################################################################
#!/bin/bash
while true; do
    ./makeData > data.in #出数据
    ./A <input.in> answer.out #被测程序
    ./A1 <input.in> answer01.out #正确（暴力）程序
    if diff answer.out answer01.out; then #比较两个输出文件
        printf "AC\n"  #结果相同显示AC
 
    elif diff -B -b answer.out answer01.out; then
        printf "PE\n"
 
    else
        printf "WA\n" #结果不同显示WA，并退出
        exit 0
    fi
done

