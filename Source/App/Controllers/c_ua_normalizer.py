# ============================================================
# YOU'RE FIRED - Controller : UaNormalizer
# ============================================================
import unreal
import c_actor_spawner

def handle_ua_normalizer_logic(location=(0,0,0)):
    """Controller: Lógica de control e interacción para UaNormalizer."""
    unreal.log("[Controller:UaNormalizer] Ejecutando lógica de control para UaNormalizer.")
    return c_actor_spawner.spawn_actor("UaNormalizer", "/Script/App.UaNormalizer", location)
