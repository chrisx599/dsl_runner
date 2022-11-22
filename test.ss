Step welcome
    Speak "Hello,please input your user ID:"
    Assign $id
    Getdata $id $amount
    Speak "Hello + $id + ,What can i help you?"
    Listen 5 20
        Branch complain complainProc
        Branch bill billProc
        Silence silenceProc
        Default defaultProc
Step complainProc
    Speak "Your ideas help our work improvement,please input your suggestion?"
    Listen 5 50
        Default thanks
Step thanks
    Speak "Thank you for your telegram"
    Exit
Step billProc
    Speak "Your bill is + $amount + ,thank you for your telegram"
    Exit
Step silenceProc
    Speak "Sorry,please say that again"
    Listen 5 20
        Branch complain complainProc
        Branch bill billProc
        Silence silenceProc
        Default defaultProc
Step defaultProc
    Speak "Welcome to call us again"
    Exit