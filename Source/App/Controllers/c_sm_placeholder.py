# ============================================================
# YOU'RE FIRED - Controller : SmPlaceholder
# ============================================================
import unreal
import c_actor_spawner

def handle_sm_placeholder_logic(location=(0,0,0)):
    """Controller: Lógica de control e interacción para SmPlaceholder."""
    unreal.log("[Controller:SmPlaceholder] Ejecutando lógica de control para SmPlaceholder.")
    return c_actor_spawner.spawn_actor("SmPlaceholder", "/Script/App.SmPlaceholder", location)
