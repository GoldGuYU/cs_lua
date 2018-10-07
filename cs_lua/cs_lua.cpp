// cs_lua.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
extern "C" 
{ 
#include "src/lua.hpp"
#include "src/lua.h"
#include "src/lauxlib.h"
#include "src/lualib.h"
}

int ctest(lua_State * l)  //定义的一个函数
{
	printf("调用了这个函数\n");




	return 0 ;  //表示返回的没有参数   1的话表示返回1个参数
}
int ctest2(lua_State * l)  //定义的一个函数
{
	
	size_t LEN;
	 char* name = (char*)lua_tostring(l, 1,&LEN); //取字符串参数
	printf("%s\n",name);

	int oi = lua_tonumber(l, 2);    //取整数型参数

	printf("%s  %d\n", name,oi);
	 
	bool us = lua_toboolean(l, 3);   //取bool型参数

	printf("%s  %d   %d\n", name, oi,us); 
	return 0;  //表示返回的没有参数   1的话表示返回1个参数
}

/*local arr={"ad01f","asd02","asdf","sdfaig"}

ctest3(arr)
*/
//传递数组给c++函数
int ctest3(lua_State *l)
{
	//既然是传递的数组  那得先获取数组的长度
	int b = luaL_len(l, 1);
	for (size_t i = 1; i < b+1; i++)
	{
		lua_pushnumber(l, i);
		lua_gettable(l, 1);//pop index
		size_t size;
		printf("%s\n", lua_tolstring(l, -1, &size));
		lua_pop(l, 1);
	}
	printf("%d\n",b);
	return 0;
}

int text(lua_State* l)
{
	
	//只取某一个值
	lua_getfield(l, 1, "age"); //1表示第一个参数表  2 的话 就是2的参数表  “age”表示取对应的key

	printf("%s\n", lua_tostring(l, -1));


	//遍历tab表
	lua_pushnil(l);
	while (lua_next(l, 1)!=0)
	{
		printf("key %s\n", lua_tostring(l, -2));

		printf("value %s\n", lua_tostring(l, -1));

		lua_pop(l, 1);

	}

// #define LUA_TNIL		0            检查是否为nil类型
// #define LUA_TBOOLEAN		1        检查bool类型
// #define LUA_TLIGHTUSERDATA	2	 检查
// #define LUA_TNUMBER		3		 检查是否是数字类型
// #define LUA_TSTRING		4		 检查是否是字符串类型
// #define LUA_TTABLE		5		 检查是否为表类型
// #define LUA_TFUNCTION		6    检查是否是函数
// #define LUA_TUSERDATA		7
// #define LUA_TTHREAD		8
	//检查类型
	luaL_checktype(l, 1, LUA_TTABLE);  //这个是检查到参数错误就不往下执行

	if (lua_type(l,1)!=LUA_TTABLE)   //这个检查到参数错误是继续往下执行的
	{
		printf("参数错误"); 
	}


	return 0;
}

//返回值
int texs(lua_State* l)
{


	lua_pushstring(l, "返回值哟");
	return 1; //表示返回1个参数
	lua_pushnumber(l, 10);  //第一个返回值

	return 2; //表示返回2个参数
}
//返回表
int ret(lua_State* L)
{
	int ips = 2;
	lua_pushnumber(L, ips);  //第一个返回值


	lua_newtable(L); //创建一个表格,放在栈顶
	for (size_t i = 0; i < ips; i++)
	{
		lua_pushnumber(L, i);
		lua_newtable(L);//压入value,也是一个table


		lua_pushstring(L, "ID");//压入subtable的key
		lua_pushnumber(L, 10);//value
		lua_settable(L, -3);//弹出key,value,并设置到subtable


		lua_pushstring(L, "Name");//压入subtable的key
		lua_pushstring(L, "你大爷的");//value
		lua_settable(L, -3);//弹出key,value,并设置到subtable

		lua_pushstring(L, "Content");//压入subtable的key
		lua_pushstring(L, "oi");//value
		lua_settable(L, -3);//弹出key,value,并设置到subtable

		lua_pushstring(L, "dwState1");//压入subtable的key
		lua_pushnumber(L, 5);//value
		lua_settable(L, -3);//弹出key,value,并设置到subtable

		lua_pushstring(L, "dwState2");//压入subtable的key
		lua_pushnumber(L,8);//value
		lua_settable(L, -3);//弹出key,value,并设置到subtable


		lua_settable(L, -3);//这时候父table的位置还是-3,弹出key,value(subtable),并设置到table里去
	}
	return 2;
}

int main()
{
	lua_State *l = luaL_newstate();
	luaL_openlibs(l);

	//注册ctest函数到lua中
	lua_register(l, "ctest", ctest);//"ctest" 这个名称可以与函数不一样的
	lua_register(l, "ctest2", ctest2);//"ctest2" 这个名称可以与函数不一样的
	lua_register(l, "ctest3", ctest3);//"ctest3" 这个名称可以与函数不一样的

	lua_register(l, "text", text);//"text" 这个名称可以与函数不一样的

	lua_register(l, "texs", texs);//"texs" 这个名称可以与函数不一样的

	lua_register(l, "ret", ret);

	{ 
		//c++给lua传递全局变量   
		lua_pushstring(l, "c++给lua的全局变量哟");
		lua_setglobal(l, "openc");// openc就是给lua的全局变量名称
	}

	{ 
		//c++给lua传递全局变量（表）
		lua_newtable(l); //创建一个表格,放在栈顶
		lua_pushstring(l, "names");
		lua_pushstring(l, "c++给lua的全局变量表哟");
		lua_settable(l, -3);

		lua_pushstring(l, "age");
		lua_pushnumber(l, 500);
		lua_settable(l, -3);

		lua_setglobal(l, "opena"); // opena就是给lua的全局变量名称
	}



	if (luaL_dofile(l, "lua.lua"))
	{
		const char * err = lua_tostring(l, -1);
		printf("lua 加载失败  %s", err);

	}
	if (lua_pcall(l,0,0,0)!=0)
	{
		printf("错误\n");
	}




	{ 
		//c++调用lua全局变量（表）
		lua_getglobal(l, "conf");  //conf  是lua中定义的全局变量(表)

		lua_getfield(l, -1, "name");
		printf("lua中的表name项 %s \n", lua_tostring(l, -1));
		lua_pop(l, 1);  //1个元素

		lua_getfield(l, -1, "id");
		printf("lua中的表id项 %d\n", (int)lua_tonumber(l, -1));  //记得取值的时候number的时候记得强转int
		lua_pop(l, 1);  // 1个元素

		lua_pop(l, 1);  // 1个元素
	}


	{
		//c++调用lua全局变量     一般来说用来做初始化参数配置
		lua_getglobal(l, "lsbl_s");  //lsbl_s  是lua中定义的全局变量
		int lsbl = lua_tonumber(l, -1);   //取出需要的变量值  堆栈-1
		lua_pop(l, 1); //这个1不是位置 而是弹出几个
		printf("取出lua中的全局变量 ==%d\n", lsbl);
	}


	//查看堆栈的大小
	printf("当前堆栈 %d\n", lua_gettop(l));


	//c++调用lua中的函数
	lua_getglobal(l, "funopen");  //funopen  是lua中定义的函数
	if (lua_pcall(l, 0, 0, 0)!=0)   //第二个参数是 参数数量   第三个参数是返回值  第四个参数是错误输出函数
	{
		//==0是调用成功的   ！=0就是错误的
		printf("错误 =%s\n",lua_tostring(l,-1));
		//为什么要luapop？ 因为堆栈发生了变化
		lua_pop(l, 1);
	}
	printf("当前堆栈 %d\n", lua_gettop(l));



	//c++调用lua中的函数 并且传递参数  以2个参数作为示例
	lua_getglobal(l, "funopen1");  //funopen  是lua中定义的函数
	lua_pushstring(l,"我是第一个参数哟");
	lua_pushnumber(l, 666);
	if (lua_pcall(l, 2, 0, 0) != 0)   //第二个参数是 参数数量 因为上面传2个参数所以改写2   第三个参数是返回值  第四个参数是错误输出函数
	{
		//==0是调用成功的   ！=0就是错误的
		printf("错误 =%s\n", lua_tostring(l, -1));
		//为什么要luapop？ 因为堆栈发生了变化
		lua_pop(l, 1);
	}
	printf("当前堆栈 %d\n", (int)lua_gettop(l));




	//c++调用lua中的函数 并且传递参数  以2个参数作为示例  并且获取返回值
	lua_getglobal(l, "funopen2");  //funopen  是lua中定义的函数
	lua_pushstring(l, "我是第一个参数哟");
	lua_pushnumber(l, 666);
	if (lua_pcall(l, 2, 1, 0) != 0)   //第二个参数是 参数数量 因为上面传2个参数所以改写2   第三个参数是返回值 改为1 就是1个返回值  第四个参数是错误输出函数
	{
		//==0是调用成功的   ！=0就是错误的
		printf("错误 =%s\n", lua_tostring(l, -1));
		//为什么要luapop？ 因为堆栈发生了变化
		lua_pop(l, 1);
	}
	else
	{
		printf("funopen2返回值   %s\n", lua_tostring(l, -1));
		//为什么要luapop？ 因为取出返回值  所以需要平衡堆栈
		lua_pop(l, 1); 
	}
	printf("当前堆栈 %d\n", (int)lua_gettop(l));



	//c++调用lua函数 传递表和返回表

	lua_getglobal(l, "funopen3");  //funopen  是lua中定义的函数
	lua_pushstring(l, "我是第一个参数哟");
	lua_pushnumber(l, 666);

	lua_newtable(l); //创建一个表格,放在栈顶
	lua_pushstring(l, "names");
	lua_pushstring(l, "c++给lua的全局变量表哟");
	lua_settable(l, -3);

	lua_pushstring(l, "age");
	lua_pushnumber(l, 500);
	lua_settable(l, -3);

	if (lua_pcall(l, 3, 1, 0) != 0)   //第二个参数是 参数数量 因为上面传3个参数所以改写3   第三个参数是返回值 改为2就是2个返回值  第四个参数是错误输出函数
	{
		//==0是调用成功的   ！=0就是错误的
		printf("错误 =%s\n", lua_tostring(l, -1));
		//为什么要luapop？ 因为堆栈发生了变化
		lua_pop(l, 1);
	}
	else
	{ 
		lua_getfield(l, -1, "pass");
		printf("lua中的表name项 %s \n", lua_tostring(l, -1));
		lua_pop(l, 1);  //1个元素

		lua_getfield(l, -1, "id");
		printf("lua中的表id项 %d \n", (int)lua_tonumber(l, -1));
		lua_pop(l, 1);  //1个元素

		lua_getfield(l, -1, "op");
		printf("lua中的表op项 %d \n", (int)lua_tonumber(l, -1));
		lua_pop(l, 1);  //1个元素


		lua_pop(l, 1);  //1个元素
	}
	printf("当前堆栈 %d\n", (int)lua_gettop(l));










	lua_close(l);
	system("pause");
	
	





    return 0;
}

