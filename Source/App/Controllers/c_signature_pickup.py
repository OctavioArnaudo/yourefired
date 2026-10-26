# ============================================================
# YOU'RE FIRED - Controller : SignaturePickup
# ============================================================
import unreal
import c_actor_spawner

def handle_signature_pickup_logic(location=(0,0,0)):
    """Controller: Lógica de control e interacción para SignaturePickup."""
    unreal.log("[Controller:SignaturePickup] Ejecutando lógica de control para SignaturePickup.")
    return c_actor_spawner.spawn_actor("SignaturePickup", "/Script/App.SignaturePickup", location)
