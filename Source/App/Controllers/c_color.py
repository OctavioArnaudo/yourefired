# ============================================================
# YOU'RE FIRED - Controller : Color
# ============================================================
import unreal
import c_actor_spawner

def handle_color_logic(location=(0,0,0)):
    """Controller: Lógica de control e interacción para Color."""
    unreal.log("[Controller:Color] Ejecutando lógica de control para Color.")
    return c_actor_spawner.spawn_actor("Color", "/Script/App.Color", location)
