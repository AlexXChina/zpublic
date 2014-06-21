#pragma once
#include <map>
#include <string>

class z_lua_function_reg
{
public:
    z_lua_function_reg();
    ~z_lua_function_reg();

    ///> �����ɾ���º���������������ظ��Ḳ��
    void insert_no_prefix(const char *name, lua_CFunction func);
    void insert_no_prefix(const luaL_Reg* pfuncs);
    void insert(const char *name, lua_CFunction func);
    void insert(const luaL_Reg* pfuncs);
    void erase(const char *name);

    ///> ��������ͳһǰ׺
    void prefix(std::string val) { prefix_ = val; }

    ///> ����
    std::string libname() const { return libname_; }
    void libname(std::string val) { libname_ = val; }

    ///> ����luaL_Reg����Ҫ�������ͷ��ڴ�
    luaL_Reg* create();
    void close(luaL_Reg* pfuncs);


private:
    std::map<std::string, lua_CFunction> funcs_;
    std::string prefix_;
    std::string libname_;
};
