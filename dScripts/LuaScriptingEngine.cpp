#include "LuaScriptingEngine.h"

dLuaScriptEngine::dLuaScriptEngine() {

}

dLuaScript* dLuaScriptEngine::CreateScript(const std::string& scriptName, const std::string& scriptValue) {
    dLuaScript* script = new dLuaScript(scriptName, scriptValue);

    if (script->GetExecuteState()) {
        m_Scripts.push_back(script);
        return script;
    } else {
        return nullptr;
    }
}

dLuaScript::dLuaScript(const std::string& scriptName, const std::string& scriptValue) {
    m_Name = scriptName;
    m_ScriptValue = scriptValue;

    m_LuaState.open_libraries(sol::lib::base, sol::lib::package);

    m_LoadResult = m_LuaState.load(scriptValue);

    m_ReadyToExecute = m_LoadResult.valid();
}

void dLuaScript::Execute() {
    if (m_ReadyToExecute) {
        m_LuaState.script(m_ScriptValue);
    } else {
        Game::logger->Log("LuaEngine", "Script " + m_Name + " was ran before ready. \n");
    }
}