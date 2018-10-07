--mian.lua   --符号是 这个是注释
print("测试此功能")
a=100			-- a相当于全局变量
local b=110;   --local 本地变量
print(a)
dofile("xx.lua");    --//相当于执行另外一个脚本

--type  判断lua数据类型  例子 
print(type(a));

--nil  空类型 

--boolean 类型  就是  bool类型  

--Numbers 类型 

--tonumber()  相当于字符串转为number类型

local v=tonumber("123")   --但是只能把数字的字符串转换为 number类型  字符串比如 abc 或者文字都不支持

print(v)

-- ..符号是拼接字符串  但是不能拼接nil类型
txtr="tsdkf1".."opnens"..a
print(txtr)
print("string len="..string.len(txtr))

--条件判断语句  
-- if(1==1) then       || 是用的or 代替   && 用的是and代替     ~=是不等于 其他都是一致的
--    print（"1==1"）
-- elseif(2==2) then
--    print("nioidf")
-- else
--    print("djkf")
-- end








--while 循环    先判断再执行
-- while   do
-- end
-- break 退出循环
-- local i=100
-- while(not(i<0)) do   --i不等于0的时候就执行   not 就不的意思
--  print(i)
--  i=i-1
--  if（i==90） then
--     print("break")
--    break
--  end 
--end 
--
--repeat 循环 相当于do    while   先执行再判断
--
--repeat    
--   i=i+1
--   print(i)
--   
--
--
--
--
--
--until   i>110
--
--
--

-- for 循环    数值循环
--
-- for var=1,5,1 do    //第一个是变量1   第二个最大是几次循环5    最后一个参数是步数 一般是1 可以为2  也就是每次循环+2  也可以省略这个参数
--    print(ver)
-- end
--
--for 泛型循环    pairs 遍历全部  ipairs 遍历一个表
--
-- local dayes={"sun","mos","tuos"}
--
-- for i,v in iparirs(dayes) do    //i就是编号   v 就是遍历出来的值
--  print(i.. v)
-- end
--
--local tab={[1]=="a",[2]=="b",[4]=="d"}
--
--for i,v in parirs(dayes) do    //i就是编号   v 就是遍历出来的值 parirs 这样能全部遍历出来
-- print(i.. v)
--end
--
--
--for i,v in iparirs(dayes) do    //i就是编号   v 就是遍历出来的值  iparirs 如果中途截断的话就遍历不完全
-- print(i.. v)
--end
--
--
--
--
--

--[[ctest();

ctest2("你大爷");

ctest2("你大爷",8895);

ctest2("你大爷",8895,true);

ctest2("你大爷",8895,false);
]]

ctest2("你大爷sadfasdfawertavw4etfaedfvaertafrcg4tafgdfg3e4rgfegsdfysegh",8895,false);



local arr={"ad01f","asd02","asdf","sdfaig"}
ctest3(arr)


local tab={name="xiaoming",age="22",id="009"}
text(tab)


local reo=texs()
print(reo)
 


local Count,TaskTable = ret() 
	for i = 0 , Count - 1 , 1 do
		print("Name:%s",TaskTable[i].Name) 
		print("ID:%d",TaskTable[i].ID) 
		print("Content:%s",TaskTable[i].Content) 
		print("dwState1:%d",TaskTable[i].dwState1) 
		print("dwState2:%d",TaskTable[i].dwState2) 
		print("\n")
	end


lsbl_s=10000

print(openc)


conf={
name="luas",
id=5006 
}


print(opena["names"])

print(opena.age)

function funopen()
	print("c++调用lua的函数哟")
	 
end

function funopen1(cs,opd)
	print("c++调用lua的函数哟")
	 print(cs)
	 print(opd)
end

function funopen2(cs,opd)
	print("c++调用lua的函数哟")
	 print(cs)
	 print(opd)
	 return "我是lua函数的返回值哟"
end


function funopen3(cs,opd,tabp)
	 print("c++调用lua的函数哟")
	 print(cs)
	 print(opd)

	 print("age:%d",tabp.age) 
	 print("name:%s",tabp.names) 

	 local tops={id=1234,pass="我是表",op=9871}
	 return tops;
end