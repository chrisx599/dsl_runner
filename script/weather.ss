Step welcome
    Speak "Hello,welcome use weather today"
    Listen 5 10
        Branch search searchProc
        Silence silenceProc
        Default defaultProc

Step searchProc
    Speak "Please input city name:"
    Assign $city
    Getdata $city $weather
    Speak " +  $city + is + $weather + today"
    Exit

Step silenceProc
    Speak "Sorry,please say that again"
    Listen 5 20
        Branch search searchProc
        Silence silenceProc
        Default defaultProc

Step defaultProc
    Speak "We cant understand your words"
    Speak "Welcome to use again"
    Exit