Step welcome
    Speak "您好，请输入用户ID:"
    Assign $id
    Getdata $id
    Speak "您好" + $id +"，请问有什么可以帮您?"
    Listen 5 20
        Branch complain complainProc
        Branch bill billProc
        Silence silenceProc
        Default defaultProc
Step complainProc
    Speak "您的意见是我们改进工作的动力，请问您还有什么补充?"
    Listen 5 50
        Default thanks
Step thanks
    Speak "感谢您的来电，再见"
    Exit
Step billProc
    Speak "您的本月账单是" + $amount + "元，感谢您的来电，再见"
    Exit
Step silenceProc
    Speak "听不清，请您大声一点可以吗"
    Listen 5 20
        Branch complain complainProc
        Branch bill billProc
        Silence silenceProc
        Default defaultProc
Step defaultProc
    Speak "请再次致电"
    Exit