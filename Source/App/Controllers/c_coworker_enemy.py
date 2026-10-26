# ============================================================
# YOU'RE FIRED - Controller : CoworkerEnemy
# ============================================================
import unreal
import c_actor_spawner

def handle_coworker_enemy_logic(location=(0,0,0)):
    """Controller: Lógica de control e interacción para CoworkerEnemy."""
    unreal.log("[Controller:CoworkerEnemy] Ejecutando lógica de control para CoworkerEnemy.")
    return c_actor_spawner.spawn_actor("CoworkerEnemy", "/Script/App.CoworkerEnemy", location)
