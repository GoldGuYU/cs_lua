// cs_lua.cpp : �������̨Ӧ�ó������ڵ㡣
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

int ctest(lua_State * l)  //�����һ������
{
	printf("�������������\n");




	return 0 ;  //��ʾ���ص�û�в���   1�Ļ���ʾ����1������
}
int ctest2(lua_State * l)  //�����һ������
{
	
	size_t LEN;
	 char* name = (char*)lua_tostring(l, 1,&LEN); //ȡ�ַ�������
	printf("%s\n",name);

	int oi = lua_tonumber(l, 2);    //ȡ�����Ͳ���

	printf("%s  %d\n", name,oi);
	 
	bool us = lua_toboolean(l, 3);   //ȡbool�Ͳ���

	printf("%s  %d   %d\n", name, oi,us); 
	return 0;  //��ʾ���ص�û�в���   1�Ļ���ʾ����1������
}

/*local arr={"ad01f","asd02","asdf","sdfaig"}

ctest3(arr)
*/
//���������c++����
int ctest3(lua_State *l)
{
	//��Ȼ�Ǵ��ݵ�����  �ǵ��Ȼ�ȡ����ĳ���
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
	
	//ֻȡĳһ��ֵ
	lua_getfield(l, 1, "age"); //1��ʾ��һ��������  2 �Ļ� ����2�Ĳ�����  ��age����ʾȡ��Ӧ��key

	printf("%s\n", lua_tostring(l, -1));


	//����tab��
	lua_pushnil(l);
	while (lua_next(l, 1)!=0)
	{
		printf("key %s\n", lua_tostring(l, -2));

		printf("value %s\n", lua_tostring(l, -1));

		lua_pop(l, 1);

	}

// #define LUA_TNIL		0            ����Ƿ�Ϊnil����
// #define LUA_TBOOLEAN		1        ���bool����
// #define LUA_TLIGHTUSERDATA	2	 ���
// #define LUA_TNUMBER		3		 ����Ƿ�����������
// #define LUA_TSTRING		4		 ����Ƿ����ַ�������
// #define LUA_TTABLE		5		 ����Ƿ�Ϊ������
// #define LUA_TFUNCTION		6    ����Ƿ��Ǻ���
// #define LUA_TUSERDATA		7
// #define LUA_TTHREAD		8
	//�������
	luaL_checktype(l, 1, LUA_TTABLE);  //����Ǽ�鵽��������Ͳ�����ִ��

	if (lua_type(l,1)!=LUA_TTABLE)   //�����鵽���������Ǽ�������ִ�е�
	{
		printf("��������"); 
	}


	return 0;
}

//����ֵ
int texs(lua_State* l)
{


	lua_pushstring(l, "����ֵӴ");
	return 1; //��ʾ����1������
	lua_pushnumber(l, 10);  //��һ������ֵ

	return 2; //��ʾ����2������
}
//���ر�
int ret(lua_State* L)
{
	int ips = 2;
	lua_pushnumber(L, ips);  //��һ������ֵ


	lua_newtable(L); //����һ�����,����ջ��
	for (size_t i = 0; i < ips; i++)
	{
		lua_pushnumber(L, i);
		lua_newtable(L);//ѹ��value,Ҳ��һ��table


		lua_pushstring(L, "ID");//ѹ��subtable��key
		lua_pushnumber(L, 10);//value
		lua_settable(L, -3);//����key,value,�����õ�subtable


		lua_pushstring(L, "Name");//ѹ��subtable��key
		lua_pushstring(L, "���ү��");//value
		lua_settable(L, -3);//����key,value,�����õ�subtable

		lua_pushstring(L, "Content");//ѹ��subtable��key
		lua_pushstring(L, "oi");//value
		lua_settable(L, -3);//����key,value,�����õ�subtable

		lua_pushstring(L, "dwState1");//ѹ��subtable��key
		lua_pushnumber(L, 5);//value
		lua_settable(L, -3);//����key,value,�����õ�subtable

		lua_pushstring(L, "dwState2");//ѹ��subtable��key
		lua_pushnumber(L,8);//value
		lua_settable(L, -3);//����key,value,�����õ�subtable


		lua_settable(L, -3);//��ʱ��table��λ�û���-3,����key,value(subtable),�����õ�table��ȥ
	}
	return 2;
}

int main()
{
	lua_State *l = luaL_newstate();
	luaL_openlibs(l);

	//ע��ctest������lua��
	lua_register(l, "ctest", ctest);//"ctest" ������ƿ����뺯����һ����
	lua_register(l, "ctest2", ctest2);//"ctest2" ������ƿ����뺯����һ����
	lua_register(l, "ctest3", ctest3);//"ctest3" ������ƿ����뺯����һ����

	lua_register(l, "text", text);//"text" ������ƿ����뺯����һ����

	lua_register(l, "texs", texs);//"texs" ������ƿ����뺯����һ����

	lua_register(l, "ret", ret);

	{ 
		//c++��lua����ȫ�ֱ���   
		lua_pushstring(l, "c++��lua��ȫ�ֱ���Ӵ");
		lua_setglobal(l, "openc");// openc���Ǹ�lua��ȫ�ֱ�������
	}

	{ 
		//c++��lua����ȫ�ֱ�������
		lua_newtable(l); //����һ�����,����ջ��
		lua_pushstring(l, "names");
		lua_pushstring(l, "c++��lua��ȫ�ֱ�����Ӵ");
		lua_settable(l, -3);

		lua_pushstring(l, "age");
		lua_pushnumber(l, 500);
		lua_settable(l, -3);

		lua_setglobal(l, "opena"); // opena���Ǹ�lua��ȫ�ֱ�������
	}



	if (luaL_dofile(l, "lua.lua"))
	{
		const char * err = lua_tostring(l, -1);
		printf("lua ����ʧ��  %s", err);

	}
	if (lua_pcall(l,0,0,0)!=0)
	{
		printf("����\n");
	}




	{ 
		//c++����luaȫ�ֱ�������
		lua_getglobal(l, "conf");  //conf  ��lua�ж����ȫ�ֱ���(��)

		lua_getfield(l, -1, "name");
		printf("lua�еı�name�� %s \n", lua_tostring(l, -1));
		lua_pop(l, 1);  //1��Ԫ��

		lua_getfield(l, -1, "id");
		printf("lua�еı�id�� %d\n", (int)lua_tonumber(l, -1));  //�ǵ�ȡֵ��ʱ��number��ʱ��ǵ�ǿתint
		lua_pop(l, 1);  // 1��Ԫ��

		lua_pop(l, 1);  // 1��Ԫ��
	}


	{
		//c++����luaȫ�ֱ���     һ����˵��������ʼ����������
		lua_getglobal(l, "lsbl_s");  //lsbl_s  ��lua�ж����ȫ�ֱ���
		int lsbl = lua_tonumber(l, -1);   //ȡ����Ҫ�ı���ֵ  ��ջ-1
		lua_pop(l, 1); //���1����λ�� ���ǵ�������
		printf("ȡ��lua�е�ȫ�ֱ��� ==%d\n", lsbl);
	}


	//�鿴��ջ�Ĵ�С
	printf("��ǰ��ջ %d\n", lua_gettop(l));


	//c++����lua�еĺ���
	lua_getglobal(l, "funopen");  //funopen  ��lua�ж���ĺ���
	if (lua_pcall(l, 0, 0, 0)!=0)   //�ڶ��������� ��������   �����������Ƿ���ֵ  ���ĸ������Ǵ����������
	{
		//==0�ǵ��óɹ���   ��=0���Ǵ����
		printf("���� =%s\n",lua_tostring(l,-1));
		//ΪʲôҪluapop�� ��Ϊ��ջ�����˱仯
		lua_pop(l, 1);
	}
	printf("��ǰ��ջ %d\n", lua_gettop(l));



	//c++����lua�еĺ��� ���Ҵ��ݲ���  ��2��������Ϊʾ��
	lua_getglobal(l, "funopen1");  //funopen  ��lua�ж���ĺ���
	lua_pushstring(l,"���ǵ�һ������Ӵ");
	lua_pushnumber(l, 666);
	if (lua_pcall(l, 2, 0, 0) != 0)   //�ڶ��������� �������� ��Ϊ���洫2���������Ը�д2   �����������Ƿ���ֵ  ���ĸ������Ǵ����������
	{
		//==0�ǵ��óɹ���   ��=0���Ǵ����
		printf("���� =%s\n", lua_tostring(l, -1));
		//ΪʲôҪluapop�� ��Ϊ��ջ�����˱仯
		lua_pop(l, 1);
	}
	printf("��ǰ��ջ %d\n", (int)lua_gettop(l));




	//c++����lua�еĺ��� ���Ҵ��ݲ���  ��2��������Ϊʾ��  ���һ�ȡ����ֵ
	lua_getglobal(l, "funopen2");  //funopen  ��lua�ж���ĺ���
	lua_pushstring(l, "���ǵ�һ������Ӵ");
	lua_pushnumber(l, 666);
	if (lua_pcall(l, 2, 1, 0) != 0)   //�ڶ��������� �������� ��Ϊ���洫2���������Ը�д2   �����������Ƿ���ֵ ��Ϊ1 ����1������ֵ  ���ĸ������Ǵ����������
	{
		//==0�ǵ��óɹ���   ��=0���Ǵ����
		printf("���� =%s\n", lua_tostring(l, -1));
		//ΪʲôҪluapop�� ��Ϊ��ջ�����˱仯
		lua_pop(l, 1);
	}
	else
	{
		printf("funopen2����ֵ   %s\n", lua_tostring(l, -1));
		//ΪʲôҪluapop�� ��Ϊȡ������ֵ  ������Ҫƽ���ջ
		lua_pop(l, 1); 
	}
	printf("��ǰ��ջ %d\n", (int)lua_gettop(l));



	//c++����lua���� ���ݱ�ͷ��ر�

	lua_getglobal(l, "funopen3");  //funopen  ��lua�ж���ĺ���
	lua_pushstring(l, "���ǵ�һ������Ӵ");
	lua_pushnumber(l, 666);

	lua_newtable(l); //����һ�����,����ջ��
	lua_pushstring(l, "names");
	lua_pushstring(l, "c++��lua��ȫ�ֱ�����Ӵ");
	lua_settable(l, -3);

	lua_pushstring(l, "age");
	lua_pushnumber(l, 500);
	lua_settable(l, -3);

	if (lua_pcall(l, 3, 1, 0) != 0)   //�ڶ��������� �������� ��Ϊ���洫3���������Ը�д3   �����������Ƿ���ֵ ��Ϊ2����2������ֵ  ���ĸ������Ǵ����������
	{
		//==0�ǵ��óɹ���   ��=0���Ǵ����
		printf("���� =%s\n", lua_tostring(l, -1));
		//ΪʲôҪluapop�� ��Ϊ��ջ�����˱仯
		lua_pop(l, 1);
	}
	else
	{ 
		lua_getfield(l, -1, "pass");
		printf("lua�еı�name�� %s \n", lua_tostring(l, -1));
		lua_pop(l, 1);  //1��Ԫ��

		lua_getfield(l, -1, "id");
		printf("lua�еı�id�� %d \n", (int)lua_tonumber(l, -1));
		lua_pop(l, 1);  //1��Ԫ��

		lua_getfield(l, -1, "op");
		printf("lua�еı�op�� %d \n", (int)lua_tonumber(l, -1));
		lua_pop(l, 1);  //1��Ԫ��


		lua_pop(l, 1);  //1��Ԫ��
	}
	printf("��ǰ��ջ %d\n", (int)lua_gettop(l));










	lua_close(l);
	system("pause");
	
	





    return 0;
}

