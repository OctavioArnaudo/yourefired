# ============================================================
# YOU'RE FIRED - Service: Patrol Logic & Routing Calculation
# ============================================================
import unreal

def execute_patrol_step(character_actor, target_location=(0.0, 0.0, 0.0), patrol_radius=500.0):
    """Service: Calcula y ejecuta el paso de patrullaje unitario para cualquier actor."""
    if not character_actor or not character_actor.is_valid():
        return False
    unreal.log(f"[Service:Patrol] Ejecutando paso de patrullaje unitario para {character_actor.get_actor_label()} en {target_location} (Radio: {patrol_radius}).")
    return True
