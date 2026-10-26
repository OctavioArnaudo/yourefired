# ============================================================
# YOU'RE FIRED - Interface : Weapon
# ============================================================
import unreal

class IWeaponInterface:
    """Interface: Contrato para Weapon."""
    def execute_weapon(self):
        raise NotImplementedError("execute_weapon debe ser implementado")
