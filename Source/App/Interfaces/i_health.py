# ============================================================
# YOU'RE FIRED - Interface : Health Contract
# ============================================================
import unreal

class IHealthInterface:
    """Interface: Contrato para recepcion de dano y consulta de salud."""

    def on_take_damage(self, damage_amount, damage_type=None):
        unreal.log(f"[IHealthInterface] Evento de recepcion de dano: {damage_amount}")
        return float(damage_amount)
