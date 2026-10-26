# ============================================================
# YOU'RE FIRED - Controller : WbpPlaceholder
# ============================================================
import unreal
import c_actor_spawner

def handle_wbp_placeholder_logic(location=(0,0,0)):
    """Controller: Lógica de control e interacción para WbpPlaceholder."""
    unreal.log("[Controller:WbpPlaceholder] Ejecutando lógica de control para WbpPlaceholder.")
    return c_actor_spawner.spawn_actor("WbpPlaceholder", "/Script/App.WbpPlaceholder", location)
