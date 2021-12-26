#pragma once 

#include <vector>
#include <string>

#define SOL_ALL_SAFETIES_ON 1
#include <sol/sol.hpp>

#include "dCommonVars.h"
#include "CppScripts.h"

class dLuaScript : public Script {
public:
    dLuaScript(const std::string& scriptName, const std::string& scriptValue);

    ~dLuaScript();

    void Execute();
    void GetExecuteState() { return m_ReadyToExecute; }
private:
    
    sol::state m_LuaState;
    sol::load_result m_LoadResult;
    
    std::string m_Name
    std::string m_ScriptValue;

    bool m_ReadyToExecute = false;
}

class dLuaScriptEngine : public Singleton<dLuaScriptEngine> {
public:
    dLuaScriptEngine();

    ~dLuaScriptEngine();

    dLuaScript* CreateScript(const std::string& scriptName, const std::string& scriptValue);
    dLuaScript* GetScript(const std::string& scriptName)

private:
    std::vector<dLuaScript*> m_Scripts;
}
