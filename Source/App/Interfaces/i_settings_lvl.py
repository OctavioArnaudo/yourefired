# ============================================================
# YOU'RE FIRED - Interface : SettingsLvl
# ============================================================
import unreal

class ISettingsLvlInterface:
    """Interface: Contrato para SettingsLvl."""
    def execute_settings_lvl(self):
        raise NotImplementedError("execute_settings_lvl debe ser implementado")
