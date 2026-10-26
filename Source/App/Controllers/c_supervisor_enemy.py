# ============================================================
# YOU'RE FIRED - Controller : SupervisorEnemy
# ============================================================
import unreal
import c_actor_spawner

def handle_supervisor_enemy_logic(location=(0,0,0)):
    """Controller: Lógica de control e interacción para SupervisorEnemy."""
    unreal.log("[Controller:SupervisorEnemy] Ejecutando lógica de control para SupervisorEnemy.")
    return c_actor_spawner.spawn_actor("SupervisorEnemy", "/Script/App.SupervisorEnemy", location)
