--mian.lua   --������ �����ע��
print("���Դ˹���")
a=100			-- a�൱��ȫ�ֱ���
local b=110;   --local ���ر���
print(a)
dofile("xx.lua");    --//�൱��ִ������һ���ű�

--type  �ж�lua��������  ���� 
print(type(a));

--nil  ������ 

--boolean ����  ����  bool����  

--Numbers ���� 

--tonumber()  �൱���ַ���תΪnumber����

local v=tonumber("123")   --����ֻ�ܰ����ֵ��ַ���ת��Ϊ number����  �ַ������� abc �������ֶ���֧��

print(v)

-- ..������ƴ���ַ���  ���ǲ���ƴ��nil����
txtr="tsdkf1".."opnens"..a
print(txtr)
print("string len="..string.len(txtr))

--�����ж����  
-- if(1==1) then       || ���õ�or ����   && �õ���and����     ~=�ǲ����� ��������һ�µ�
--    print��"1==1"��
-- elseif(2==2) then
--    print("nioidf")
-- else
--    print("djkf")
-- end








--while ѭ��    ���ж���ִ��
-- while   do
-- end
-- break �˳�ѭ��
-- local i=100
-- while(not(i<0)) do   --i������0��ʱ���ִ��   not �Ͳ�����˼
--  print(i)
--  i=i-1
--  if��i==90�� then
--     print("break")
--    break
--  end 
--end 
--
--repeat ѭ�� �൱��do    while   ��ִ�����ж�
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

-- for ѭ��    ��ֵѭ��
--
-- for var=1,5,1 do    //��һ���Ǳ���1   �ڶ�������Ǽ���ѭ��5    ���һ�������ǲ��� һ����1 ����Ϊ2  Ҳ����ÿ��ѭ��+2  Ҳ����ʡ���������
--    print(ver)
-- end
--
--for ����ѭ��    pairs ����ȫ��  ipairs ����һ����
--
-- local dayes={"sun","mos","tuos"}
--
-- for i,v in iparirs(dayes) do    //i���Ǳ��   v ���Ǳ���������ֵ
--  print(i.. v)
-- end
--
--local tab={[1]=="a",[2]=="b",[4]=="d"}
--
--for i,v in parirs(dayes) do    //i���Ǳ��   v ���Ǳ���������ֵ parirs ������ȫ����������
-- print(i.. v)
--end
--
--
--for i,v in iparirs(dayes) do    //i���Ǳ��   v ���Ǳ���������ֵ  iparirs �����;�ضϵĻ��ͱ�������ȫ
-- print(i.. v)
--end
--
--
--
--
--

--[[ctest();

ctest2("���ү");

ctest2("���ү",8895);

ctest2("���ү",8895,true);

ctest2("���ү",8895,false);
]]

ctest2("���үsadfasdfawertavw4etfaedfvaertafrcg4tafgdfg3e4rgfegsdfysegh",8895,false);



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
	print("c++����lua�ĺ���Ӵ")
	 
end

function funopen1(cs,opd)
	print("c++����lua�ĺ���Ӵ")
	 print(cs)
	 print(opd)
end

function funopen2(cs,opd)
	print("c++����lua�ĺ���Ӵ")
	 print(cs)
	 print(opd)
	 return "����lua�����ķ���ֵӴ"
end


function funopen3(cs,opd,tabp)
	 print("c++����lua�ĺ���Ӵ")
	 print(cs)
	 print(opd)

	 print("age:%d",tabp.age) 
	 print("name:%s",tabp.names) 

	 local tops={id=1234,pass="���Ǳ�",op=9871}
	 return tops;
end