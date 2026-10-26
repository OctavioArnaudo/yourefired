# ============================================================
# YOU'RE FIRED - Controller : MPlaceholder
# ============================================================
import unreal
import c_actor_spawner

def handle_m_placeholder_logic(location=(0,0,0)):
    """Controller: Lógica de control e interacción para MPlaceholder."""
    unreal.log("[Controller:MPlaceholder] Ejecutando lógica de control para MPlaceholder.")
    return c_actor_spawner.spawn_actor("MPlaceholder", "/Script/App.MPlaceholder", location)
