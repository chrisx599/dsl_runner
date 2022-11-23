cd ..
runner.exe ./script/repeat.ss < ./testbat/in/repeat.in > ./testbat/out/repeat.out
runner.exe ./script/user.ss ./data/userdata.db < ./testbat/in/user.in > ./testbat/out/user.out
runner.exe ./script/weather.ss ./data/weatherdata.db < ./testbat/in/weather.in > ./testbat/out/weather.out
runner.exe ./script/searchphone.ss ./data/searchphonedata.db < ./testbat/in/searchphone.in > ./testbat/out/searchphone.out