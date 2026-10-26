# ============================================================
# YOU'RE FIRED - Interface : UiLvl
# ============================================================
import unreal

class IUiLvlInterface:
    """Interface: Contrato formal de interacción para UiLvl."""
    def execute_ui_lvl_contract(self, data):
        raise NotImplementedError("execute_ui_lvl_contract debe ser implementado")
