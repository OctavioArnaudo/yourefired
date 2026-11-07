# ============================================================
# YOU'RE FIRED - Service: Melee Attack Execution Logic
# ============================================================
import unreal

def perform_melee_attack(attacker_actor=None):
    """Service: Ejecuta la lógica unitaria de ataque cuerpo a cuerpo (Melee)."""
    label = attacker_actor.get_actor_label() if attacker_actor and attacker_actor.is_valid() else "Unknown"
    unreal.log(f"[Service:Melee] Ejecutando ataque MELEE para {label}.")
    return True
