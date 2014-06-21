#pragma once
#include <string.h>

class z_lua_state
{
public:
    z_lua_state();
    virtual ~z_lua_state();

    ///> �Ƿ���������ʱ���Զ��ر�lua_State��Ĭ��Ϊtrue
    bool auto_close() const;
    void auto_close(bool val);

    ///> �����͹ر�lua_State��open��ͬ��create������0Ϊ�ɹ�
    int open();
    int create();
    int close();

    ///> ע��lua�ű����Ե��õı�׼��
    int open_all_libs();
    int open_base();
    int open_coroutine();
    int open_table();
    int open_io();
    int open_os();
    int open_string();
    int open_bit32();
    int open_math();
    int open_debug();
    int open_package();

    ///> ע�ắ����lua
    int reg_lib(const char *libname, const luaL_Reg* pfuncs, int nup = 0);
    int reg_lib(z_lua_function_reg& funcs);
    int reg_function(const char *name, lua_CFunction func);

    ///> ���ؽű���ִ��ȫ�ֵĶ���
    int dofile(const char *filename);
    int dostring(const char* buff);
    int dobuffer(const char* buff, size_t sz);

protected:
    lua_State* L;
    bool auto_close_;
};
